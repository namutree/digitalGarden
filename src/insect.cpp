//
//  insect.cpp
//  NOCFinal
//
//  Created by John Choi on 4/27/14.
//
//

#include "insect.h"

insect::insect(){
   
}

insect::insect(int x, int y, int z){
    //initial size of insect
    ISize =5;
    
    //position of insect
    posX=x;
    posY=y;
    posZ=z;
    
    // leg movement
    a1=a2=0;
    
    maxVel=5;
    velX = ofRandom(-maxVel, maxVel);
    velY = ofRandom(-maxVel, maxVel);
}

void insect::update(){
    ///position move
    posX+=velX;
    posY+=velY;
    
    //leg movement
    float LegMove= ofRandom(1);
    if(LegMove<0.2){
        a1=ISize/4;
        a2=0;
    }
    else if (LegMove<0.4){
        a1=0;
        a2=ISize/4;
    }else{
        a1=0;
        a2=0;
    }
    
    // if the speed of insect get too low or too fast, give the new velocity.
    if(abs(velX)+abs(velY) < 1 || abs(velX)+abs(velY) >10){
        velX = ofRandom(-maxVel, maxVel);
        velY = ofRandom(-maxVel, maxVel);
    }
    // boundary check////////////////
    if(posX<-ofGetWidth()){
        velX=-velX;
        posX = -ofGetWidth();
    }
    if(posX>ofGetWidth()){
        velX=-velX;
        posX = ofGetWidth();
    }
    if(posY<-ofGetWidth()){
        velY=-velY;
        posY = -ofGetWidth();
    }
    if(posY>ofGetWidth()){
        velY=-velY;
        posY = ofGetWidth();
    }
    //boundary chekc ends/////////////////////////
    
    // no larger thatn 30 for insects
    if (ISize>30)
        ISize=30;
}

void insect::draw(){
    
    ofPushMatrix();
    
    ofTranslate(posX, posY, posZ+ISize/3);    // where to go
    ofRotateZ(sin((posX+posY)/2)*10); // looks like moving, used posX and posY, instead of random no.
    ofSetColor(0);
    ofFill();
    ofCircle(0,0,ISize); //body
    ofNoFill();
    //first leg (each leg lenth is same as the width of body of insect
    ofBeginShape();
    ofVertex(0, -ISize/2,       0);
    ofVertex(0, -ISize,         ISize/2+a1); // middle point, up half
    ofVertex(0, -ISize*3/2,     -ISize/3+a1);
    ofEndShape();
    
    //2nd leg
    ofBeginShape();
    ofVertex(ISize/2,   0,  0);
    ofVertex(ISize,     0,  ISize/2+a2);
    ofVertex(ISize*3/2, 0,  -ISize/3+a2);
    ofEndShape();
    
    //3rd leg
    ofBeginShape();
    ofVertex(0, ISize/2,    0);
    ofVertex(0, ISize,      ISize/2+a1);
    ofVertex(0, ISize*3/2,  -ISize/3+a1);
    ofEndShape();
    
    //4th leg
    ofBeginShape();
    ofVertex(-ISize/2,   0,     0);
    ofVertex(-ISize,     0,     ISize/2+a2);
    ofVertex(-ISize*3/2, 0,     -ISize/3+a2);
    ofEndShape();
    ofPopMatrix();
}