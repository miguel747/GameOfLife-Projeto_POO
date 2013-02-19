//
//  LGDefault.cpp
//  GameofLife
//
//  Created by Filipe Ribeiro on 19/02/13.
//  Copyright (c) 2013 Filipe Ribeiro. All rights reserved.
//

#include "LifeGeneration.h"
#include "GameOfLife.h"
#include <iostream>
#include <list>

using namespace std;

void Default::NextGeneration(GameOfLife& a){
    Cell *cells = new Cell();
    list<Cell*> mustRevive;
    list<Cell*> mustDie;
    
    for(int i = 0; i < a.getHeight(); i++) {
        for(int j = 0; j < a.getWidth(); j++) {
            if(a.shouldRevive(j,i)) {
                mustRevive.push_back(&cells[i*(a.getWidth())+j]);
            }
            else if (a.shouldKill(j,i)) {
                mustDie.push_back(&cells[i*(a.getWidth())+j]);
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
