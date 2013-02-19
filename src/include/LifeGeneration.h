//
//  LifeGeneration.h
//  GameofLife
//
//  Created by Filipe Ribeiro on 10/02/13.
//  Copyright (c) 2013 Filipe Ribeiro. All rights reserved.
//
#ifndef GameofLife_LifeGeneration_h
#define GameofLife_LifeGeneration_h
#include "GameOfLife.h"


//interface-strategy
class LifeGeneration{
private:
    GameOfLife& game;
public:
    virtual void NextGeneration()=0;
    
};


//concrete strategy
class Default : public LifeGeneration{
public:
    Default();
    void NextGeneration(GameOfLife& g);
};

class HighLife : public LifeGeneration{
public:
    HighLife();
    void NextGeneration(GameOfLife& g);
};
#endif
