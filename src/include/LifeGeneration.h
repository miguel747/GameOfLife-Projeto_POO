//
//  LifeGeneration.h
//  GameofLife
//
//  Created by Filipe Ribeiro on 10/02/13.
//  Copyright (c) 2013 Filipe Ribeiro. All rights reserved.
//

#ifndef GameofLife_LifeGeneration_h
#define GameofLife_LifeGeneration_h

class   LifeGeneration{
    virtual void NextGeneration()=0;
    
};
class Default : public LifeGeneration{
    void NextGeneration();
};
class HighLife : public LifeGeneration{
    void NextGeneration();
};
#endif
