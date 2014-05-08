//
//  sun.h
//  NOCFinal
//
//  Created by John Choi on 4/27/14.
//
//

#ifndef __NOCFinal__sun__
#define __NOCFinal__sun__

#include <iostream>
#include "ofMain.h"
class sun
{
public:
    sun();
    sun(float x, float y, float z);
    
    void update();
    void draw();
    
    float posX, posY, posZ;
    float noiseX,noiseY;
    
    float vel;
};

#endif /* defined(__NOCFinal__sun__) */

