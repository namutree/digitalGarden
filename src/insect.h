//
//  insect.h
//  NOCFinal
//
//  Created by John Choi on 4/27/14.
//
//

#ifndef __NOCFinal__insect__
#define __NOCFinal__insect__

#include "ofMain.h"
#include <iostream>

class insect
{
public:
    insect();
    insect(int x, int y, int z);
    
    void update();
    void draw();
    
    float ISize;
    float posX, posY, posZ;
    float velX, velY;
    
    float a1, a2;
    
    // max velocity of insect
    int maxVel;

};

#endif /* defined(__NOCFinal__insect__) */
