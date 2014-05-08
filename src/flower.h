//
//  flower.h
//  NOCFinal
//
//  Created by John Choi on 4/19/14.
//
//

#ifndef __NOCFinal__flower__
#define __NOCFinal__flower__

#include <iostream>
#include "ofMain.h"

class flower
{
public:
    flower();
    flower(int x, int y, int z);
    void update();
    void draw();
    
    int posX, posY, posZ;
    
    // control noise value
    float a1,a;
    
    float flowerHeight;
    
    float maxHeight;
    
    // stem width
    float w;
    
    float floralLeafLength;
    float floralLeafWidth;
    
    float randomColor;
    
    // flower is swinging
    float flowerSwingX, flowerSwingZ;
    float theta1,theta2;
};

#endif /* defined(__NOCFinal__flower__) */
