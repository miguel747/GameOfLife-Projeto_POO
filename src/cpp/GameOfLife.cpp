#include <iostream>
#include <list>

using namespace std;

#include "../include/GameOfLife.h"
#include "../include/LifeGeneration.h"
#include "../include/Statistics.h"

Cell::Cell(){
  state = ALIVE;
}

void Cell::kill() {
  state = DEAD;
}

void Cell::revive() {
  state = ALIVE;
}

bool Cell::isAlive() {
  return state == ALIVE;
}

GameOfLife::GameOfLife(int w, int h){
  width = w;
  height = h;

  cells = new Cell*[w*h];

  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {
      cells[i*width + j] = new Cell();
    }
  }

    killEnvironment();

    statistics = new Statistics();
    lifegeneration = new Default();
}
void GameOfLife::killEnvironment() {
  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {
      cells[i*width + j]->kill();
    }
  }
}

int GameOfLife::aliveCells() {
  int r = 0;

  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {
      if(cells[i*width + j]->isAlive()) {
	r++;
      }
    }
  }
  return r;
}

int GameOfLife::aliveNeighborCells(int w, int h) {
  if(w < 0 || w >= width) return 0;
  if(h < 0 || h >= height) return 0;

  int r = 0;

  for(int i = h-1; i <= h + 1; i++) {
    for(int j = w-1; j <= w+1; j++) {
      if((! ((i == h) && (j == w))) && isCellAlive(j,i)) {
	r++;
      }
    }
  }
  return r;
}

bool GameOfLife::isCellAlive(int w, int h) {
  if(w < 0 || w >= width) return false;
  if(h < 0 || h >= height) return false;

  return  cells[h * width + w]->isAlive();
}


void GameOfLife::makeCellAlive(int w, int h) {
  if(w < 0 || w >= width) return;
  if(h < 0 || h >= height) return;

  Cell* c = cells[h * width + w];

  if(!c->isAlive()) {
    cells[h * width + w]->revive();
  }

  statistics->survive();
}


void GameOfLife::makeCellDead(int w, int h) {
  if(w < 0 || w >= width) return;
  if(h < 0 || h >= height) return;

  Cell* c = cells[h * width + w];

  if(c->isAlive()) {
    cells[h * width + w]->kill();
  }

  statistics->kill();
}

//void GameOfLife::nextGeneration() {
  //retirei o metodo
//}

 /* Usando o TM, deveriamos tornar shouldRevive e
  * shouldKill abstratos.
  */

/*
 * Uma celula morta deve ressuscitar caso
 * tenha tres celulas vizinhas vivas.

 */
bool GameOfLife::shouldRevive(int w, int h) {
  int aliveNeighbors = aliveNeighborCells(w,h);

  return ((!isCellAlive(w,h)) && (aliveNeighbors == 3));
}

/*
 * Uma celula viva deve morrer caso
 * tenha duas ou tres celulas vizinhas vivas.
 */
bool GameOfLife::shouldKill(int w, int h) {
  int aliveNeighbors = aliveNeighborCells(w,h);

  return (isCellAlive(w,h) && (aliveNeighbors != 2 && aliveNeighbors != 3));
}

void GameOfLife::SetGeneration(LifeGeneration *lifegeneration)
{
    this->lifegeneration = lifegeneration;
}

void GameOfLife::NewGeneration(){
    this->lifegeneration->NextGeneration(this);
}
//Load Cell from matriz Cell**
Cell& GameOfLife::GetCells(int w, int h){
    return *cells[h * width + w];
}
