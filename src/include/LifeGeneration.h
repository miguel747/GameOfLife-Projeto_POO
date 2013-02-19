//
//  LifeGeneration.h
//  GameofLife
//
//  Created by Filipe Ribeiro on 10/02/13.
//  Copyright (c) 2013 Filipe Ribeiro. All rights reserved.
//
#ifndef GameofLife_LifeGeneration_h
#define GameofLife_LifeGeneration_h

class GameOfLife;


//interface-strategy
class LifeGeneration{
private:
public:
    virtual void NextGeneration()=0;
};


//concrete strategy
class Default : public LifeGeneration{
public:
    void NextGeneration(GameOfLife& a);
};

class HighLife : public LifeGeneration{
public:
    void NextGeneration(GameOfLife& a);
};
#endif
