//
//  LifeGeneration.cpp
//  GameofLife
//
//  Created by Filipe Ribeiro on 10/02/13.
//  Copyright (c) 2013 Filipe Ribeiro. All rights reserved.
//

#include "../include/LifeGeneration.h"
#include <list>
#include <iostream>

using namespace std;

void Default::NextGeneration(GameOfLife& a){
    Cell *cells = new Cell();
    list<Cell*> mustRevive;
    list<Cell*> mustDie;
    
    for(int i = 0; i < a.Getheight(); i++) {
        for(int j = 0; j < a.Getwidth(); j++) {
            if(a.shouldRevive(j,i)) {
                mustRevive.push_back(&cells[i*(a.Getwidth())+j]);
            }
            else if (a.shouldKill(j,i)) {
                mustDie.push_back(&cells[i*(a.Getwidth())+j]);
            }
        }
    }
    
    for (list<Cell*>::iterator it = mustRevive.begin(); it != mustRevive.end(); it++) {
        (*it)->revive();
        a.Getstatics()->survive();
    }
    
    for (list<Cell*>::iterator it = mustDie.begin(); it != mustDie.end(); it++) {
        (*it)->kill();
        a.Getstatics()->kill();
    }
}
void HighLife::NextGeneration(GameOfLife& a){
    cout <<"Ainda não implementada"<<endl;
    return;
}