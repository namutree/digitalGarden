//
//  cloud.cpp
//  NOCFinal
//
//  Created by John Choi on 4/19/14.
//
//

#include <iostream>
#include "cloud.h"

cloud::cloud(){
 
    
}
cloud::cloud(int x, int y, int z){
    

    for(int i=0;i< NouberOfCloud;i++){
    randomPosX[i] = ofRandom(-30,30);
    randomPosY[i] = ofRandom(-20,20);
    randomPosZ[i] = ofRandom(-30,30);
    }
    xx=x;
    yy=y;
    zz=z;
    float velocity;
    velocity =5.5;
    vel.set(ofRandom(-velocity,velocity),ofRandom(-velocity,velocity),ofRandom(-velocity,velocity));
    
   
        lifespan = 600;

    
}

void cloud::update(){

    xx += vel.x;
    yy += vel.y;
    zz += vel.z;
    

    //boundary check
    if(xx<-ofGetWidth()-100){
        xx=-ofGetWidth()-100;
        vel.x=-vel.x;
    }
    if (xx>ofGetWidth()+100){
        xx=ofGetWidth()+100;
        vel.x=-vel.x;
    }
    
    if (yy > ofGetHeight()/5){
        yy= ofGetHeight()/5;
        vel.y=-vel.y;
    }
    if (yy <-ofGetHeight()/5){
        yy= -ofGetHeight()/5;
        vel.y=-vel.y*0.9;
    }
    
    if(zz<-ofGetWidth()-100){
        zz=-ofGetWidth()-100;
        vel.z=-vel.z;
    }
    if (zz>ofGetWidth()+100){
        zz=ofGetWidth()+100;
        vel.z=-vel.z;
    }
    
    lifespan -= 1;

}

void cloud::draw(){
    
    ofPushMatrix();
    ofTranslate(xx, yy,zz);
    
    ofSetColor(192,227,241,ofMap(lifespan,0,600,0,200));

    for(int i=0; i<NouberOfCloud;i++){
        cloudParticle(30+i, 8*ofNoise(noiseX+i, noiseY)+randomPosX[i], 8*ofNoise(noiseX, noiseY+i)+randomPosY[i], 8*ofNoise(noiseX+i, noiseY+i)+randomPosZ[i]);
    }
    
    noiseX+=0.02;
    noiseY+=0.03;
    // get all the faces from the icoSphere, handy when you want to copy
    // individual vertices tweak them a little ;)
    //vector<ofMeshFace> triangles = sphere.getMesh().getUniqueFaces();
    ofPopMatrix();
    
    //////////////rain//////////////
    for (int i=0 ; i<3 ; i++){
        for(int j=0 ; j<3 ; j++){
            ofPushStyle();
            ofSetColor(150, 150, 250,ofMap(ofRandom(lifespan), 0, 600, 0, 100));
            rainLine(xx+i*10*pow(-1.0,i), yy, zz+j*10*pow(-1.0,j));
            ofPopStyle();
        }
    }
}

void cloud::cloudParticle(int radius, float posX, float posY, float posZ){
    sphere.setRadius(radius);
    sphere.setPosition(posX, posY, posZ);
    sphere.draw();
}

void cloud::rainLine(float x, float y, float z){
    ofSetLineWidth(ofRandom(1));
    ofLine(x,y,z,x,ofGetHeight(),z);
    
}