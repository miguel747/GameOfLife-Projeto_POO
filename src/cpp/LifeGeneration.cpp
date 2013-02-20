//
//  LifeGeneration.cpp
//  GameofLife
//
//  Created by Filipe Ribeiro on 10/02/13.
//  Copyright (c) 2013 Filipe Ribeiro. All rights reserved.
//

#include "../include/LifeGeneration.h"
#include "../include/GameofLife.h"
#include "../include/Statistics.h"
#include <list>
#include <iostream>

using namespace std;

Default::Default(){}
HighLife::HighLife(){}
void Default::NextGeneration(GameOfLife* a){
    //Cell *cells = new Cell();
    list<Cell*> mustRevive;
    list<Cell*> mustDie;

    for(int i = 0; i < a->getHeight(); i++) {
        for(int j = 0; j < a->getWidth(); j++) {
            if(a->shouldRevive(j,i)) {
                mustRevive.push_back(&a->GetCells(j,i));
            }
            else if (a->shouldKill(j,i)) {
                mustDie.push_back(&a->GetCells(j,i));
            }
        }
    }

    for (list<Cell*>::iterator it = mustRevive.begin(); it != mustRevive.end(); it++) {
        (*it)->revive();
        a->Getstatics()->survive();
    }

    for (list<Cell*>::iterator it = mustDie.begin(); it != mustDie.end(); it++) {
        (*it)->kill();
        a->Getstatics()->kill();
    }
}
void HighLife::NextGeneration(GameOfLife* a){
    cout<<endl;
    cout<<endl;
    cout <<"Ainda não implementada"<<endl;
    cout<<endl;
    cout<<endl;
    return;
}
