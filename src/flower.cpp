//
//  flower.cpp
//  NOCFinal
//
//  Created by John Choi on 4/19/14.
//
//

#include <iostream>
#include "flower.h"

flower::flower(){
    
}

flower::flower(int x, int y, int z){
    posX = x;
    posY = y;
    posZ = z;
    
    
    // flower ratio
    flowerHeight = 50;
    w =flowerHeight/30; // width of stem
    floralLeafLength =flowerHeight/2;
    floralLeafWidth = floralLeafLength/2;
    
    maxHeight=700;
    
    //flower color
    randomColor =ofRandom(1);
    
    // swing value
    theta1= ofRandom(4);
    theta2= ofRandom(4);
    
    
}

void flower::update(){
    
    w =flowerHeight/30; // width of stem
    floralLeafLength =flowerHeight/2;
    floralLeafWidth = floralLeafLength/2;
    
    if (flowerHeight>maxHeight)     flowerHeight =maxHeight;
    
    
    flowerSwingX = flowerHeight/20*sin(theta1);
    flowerSwingZ = flowerHeight/20*cos(theta2);
    theta1 += PI/179;
    theta1 += PI/184;

    
}

void flower::draw(){
    
    float b = ofNoise(a);
    float b1 = ofNoise(a1);
    
    
    ofPushStyle();
    ofPushMatrix();
    ofSetLineWidth(0.3);
    ofTranslate(posX,posY,posZ);
    //ofRotateY(ofGetMouseX());
    ofNoFill();
    
    //stem1
    ofSetColor(233, 156, 40);
    ofBeginShape();
    ofCurveVertex(0, 0, 0);
    ofCurveVertex(0, 0, 0);
    for (int i=1; i<6; i++) {
        ofCurveVertex(flowerSwingX/i+pow(-1.0,i)*b*w, -flowerHeight/6*i, flowerSwingZ/i+pow(-1.0,i-1)*w*b);
    }
    ofCurveVertex(flowerSwingX, -flowerHeight, flowerSwingZ);
    ofCurveVertex(flowerSwingX, -flowerHeight, flowerSwingZ);
    ofEndShape();
    
    //stem2
    ofSetColor(203, 106, 47);
    ofBeginShape();
    ofCurveVertex(0, 0, 0);
    ofCurveVertex(0, 0, 0);
    for (int i=1; i<6; i++) {
        ofCurveVertex(flowerSwingX/i+pow(-1.0,i)*b1*w, -flowerHeight/6*i, flowerSwingZ/i+pow(-1.0,i)*w*b1);
    }
    ofCurveVertex(flowerSwingX, -flowerHeight, flowerSwingZ);
    ofCurveVertex(flowerSwingX, -flowerHeight, flowerSwingZ);
    ofEndShape();
    
    //stem3
    ofSetColor(150, 106, 20);
    ofBeginShape();
    ofCurveVertex(0, 0, 0);
    ofCurveVertex(0, 0, 0);
    for (int i=1; i<10; i++) {
        ofCurveVertex(flowerSwingX/i+pow(-1.0,i)*(1-b1)*w, -flowerHeight/10*i, flowerSwingZ/i+pow(-1.0,i-1)*w*(1-b1));
    }
    ofCurveVertex(flowerSwingX, -flowerHeight, flowerSwingZ);
    ofCurveVertex(flowerSwingX, -flowerHeight, flowerSwingZ);
    ofEndShape();
    
    //stem4
    ofSetColor(130, 126, 40);
    ofBeginShape();
    ofCurveVertex(0, 0, 0);
    ofCurveVertex(0, 0, 0);
    for (int i=1; i<5; i++) {
        ofCurveVertex(flowerSwingX/i+pow(-1.0,i)*(1-b)*w, -flowerHeight/5*i, flowerSwingZ/i+pow(-1.0,i)*w*(1-b));
    }
    ofCurveVertex(flowerSwingX, -flowerHeight, flowerSwingZ);
    ofCurveVertex(flowerSwingX, -flowerHeight, flowerSwingZ);
    ofEndShape();
    
    
    //flower
    ofFill();

    
    if(randomColor<0.2)
        ofSetColor(255,20,0,100);
    else if(randomColor<0.4)
        ofSetColor(0, 255, 20,100);
    else if (randomColor<0.6)
        ofSetColor(0, 20, 255,100);
    else if (randomColor<0.8)
        ofSetColor(20, 255, 255,100);
    else
        ofSetColor(255, 23, 255,100);

    ofNoFill();
    int floralLeaf=12;
    int floralLayer=3;
    for( int j=0; j<floralLayer;j++){
        for(int i=0;i<floralLeaf;i++){
            float theta = PI*2/floralLeaf*i+j;
            float XZoffset = ofMap(j,0,floralLayer,1.7,3.9);
            ofBeginShape();
            ofCurveVertex(flowerSwingX,-flowerHeight,flowerSwingZ+0);
            ofCurveVertex(flowerSwingX,-flowerHeight,flowerSwingZ+0);
            ofCurveVertex(flowerSwingX+floralLeafWidth*cos(theta-PI/22)/XZoffset,-flowerHeight+b*5, flowerSwingZ+floralLeafWidth*sin(theta-PI/22)/XZoffset);
            ofCurveVertex(flowerSwingX+cos(theta)/XZoffset*floralLeafLength,-flowerHeight-b*5-j*10, flowerSwingZ+sin(theta)/XZoffset*floralLeafLength);
            ofCurveVertex(flowerSwingX+floralLeafWidth*cos(theta+PI/22)/XZoffset,-flowerHeight+b1*3, flowerSwingZ+floralLeafWidth*sin(theta+PI/22)/XZoffset);
            ofCurveVertex(flowerSwingX,-flowerHeight, flowerSwingZ+0);
            ofCurveVertex(flowerSwingX,-flowerHeight, flowerSwingZ+0);
            ofEndShape();
        }
    }
    ofPopMatrix();
    ofPopStyle();
    
    a+=0.05;
    a1+=0.06;
    
    
    
}