//
//  cloud.h
//  NOCFinal
//
//  Created by John Choi on 4/19/14.
//
//

#ifndef __NOCFinal__cloud__
#define __NOCFinal__cloud__

#include <iostream>
#include "ofMain.h"

#define NouberOfCloud 7

class cloud
{
public:
    cloud();
    cloud(int x, int y, int z);
    void update();
    void draw();
    void cloudParticle(int radius, float posX, float posY, float posZ);
    void rainLine(float x, float y, float z);

    
    ofSpherePrimitive sphere;
    

    float noiseX, noiseY;
    
    float randomPosX[NouberOfCloud], randomPosY[NouberOfCloud], randomPosZ[NouberOfCloud];
    
    int xx, yy,zz;
    
    ofVec3f vel;
    
    float lifespan;


};

#endif /* defined(__NOCFinal__cloud__) */
