//
//  sun.cpp
//  NOCFinal
//
//  Created by John Choi on 4/27/14.
//
//

#include "sun.h"

sun::sun(){
    
}
sun::sun(float x, float y, float z){
    posX = x;
    posY = y;
    posZ = z;
    
    vel =0;
    

}

void sun::update(){
    posZ -=vel;
    vel+=0.3;
    noiseX +=0.01;
    noiseY +=0.04;
}

void sun::draw(){
    ofPushStyle();
    ofSetColor(255,180,0,100);
    ofFill();
    ofCircle(posX,posY,0, 100.0*ofNoise(noiseX));
    
    ofNoFill();
    ofSetLineWidth(0.4);
    for(int i=0 ; i<10 ; i++){
    ofCircle(posX, posY, posZ-i*20, 120.0*ofNoise(noiseY+i/5));
    }
    ofPopStyle();
    
    
    
}