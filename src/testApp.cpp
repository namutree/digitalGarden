#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    // Smooth edges
    ofEnableSmoothing();
    //ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofEnableAntiAliasing();
    ofEnableAlphaBlending();
    
    // this uses depth information for occlusion
	// rather than always drawing things on top of each other
	ofEnableDepthTest();
    
    ofSetVerticalSync(true);

    fboGrass.allocate(ofGetWidth()*2, ofGetWidth()*2,GL_RGBA);
    
    fboGrass.begin();
    ofClear(255,255,255, 0);
    fboGrass.end();

    //// ground FBO////////////////////////////////////////////////////////
    fboGrass.begin();
    ofSetColor(158, 211, 89);
    for(int i=0;i<10000;i++){
        float aColor= ofRandom(1,2);
        ofSetColor(158*aColor,211*aColor,89*aColor, ofRandom(200));
        //ofSetColor(ofRandom(158),ofRandom(211),ofRandom(89), ofRandom(200));
        ofCircle(ofRandom(0,ofGetWidth()*2), ofRandom(0,ofGetWidth()*2),ofRandom(3,50));
    }
    fboGrass.end();
    //// FBO ENDS ///////////////////////////////////////////////////////////
}

// write our boolean remove function
bool shouldRemoveCould(cloud &p){
    if(p.lifespan == 0 )return true;
    else return false;
}

bool shouldRemoveFlower(flower &f){
    if(f.flowerHeight <0) return true;
    else return false;
}

bool shouldRemoveSun(sun &s){
    if(s.posZ < -ofGetHeight()-700) return true;
    else return false;
}

bool shouldRemoveInsect(insect &i){
    if(i.ISize <0.1) return true;
    else return false;
}
/////////////////////////////////////////////////////////////////////////////
//-------------------UPDATE-------------------------------------------///////
void testApp::update(){

    
    //cloud and flower collision test. check when the flower is under the cloud.
    for( int i=0; i<raiseFlower.size();i++){
        for( int j=0; j<cloudWater.size();j++){
            
            if(cloudWater[j].xx > raiseFlower[i].posX-140 && cloudWater[j].xx < raiseFlower[i].posX+140){
                    if(cloudWater[j].zz > raiseFlower[i].posZ-140 && cloudWater[j].zz < raiseFlower[i].posZ+140){
                        raiseFlower[i].flowerHeight +=5;
                }
            }
        }
    }
    
    // when cloud lifespan ==0 remove that cloud.
    ofRemove(cloudWater,shouldRemoveCould);
    
    // when flower height <0, remove..
    ofRemove(raiseFlower,shouldRemoveFlower);
    
    // when Sun posZ < -height-700, remove..
    ofRemove(sunLight,shouldRemoveSun);
    
    // when Insect size < 0, remove..
    ofRemove(insectGround, shouldRemoveInsect);
    
    //check full grown flower
    for(int i=0;i<raiseFlower.size();i++){
        if(raiseFlower[i].flowerHeight == raiseFlower[i].maxHeight){
            fullGrownFlower++;
        }
    }
    
    //insect and flower collision test.
    for(int i=0; i<raiseFlower.size();i++){
        for (int j=0; j<insectGround.size();j++){

            if ( ofDist(insectGround[j].posX, insectGround[j].posY,raiseFlower[i].posX, raiseFlower[i].posZ) < insectGround[j].ISize+20){ // insect-->xy plane, flower --> xz plane!!!
                raiseFlower[i].flowerHeight -= 1;
                float xPosition = raiseFlower[i].posX-insectGround[j].posX;
                float yPosition = raiseFlower[i].posZ-insectGround[j].posY;
                insectGround[j].velX = xPosition/fraction*2;
                insectGround[j].velY = yPosition/fraction*2;
                insectGround[j].ISize +=0.1;
            }
        }
    }
    
    // sun and insect collistion test
    for(int i=0 ; i<sunLight.size(); i++){
        for(int j=0; j<insectGround.size(); j++){
            if(sunLight[i].posZ <-ofGetHeight()+100 && sunLight[i].posZ > - ofGetHeight()-700){
                float distance =ofDist(sunLight[i].posX,sunLight[i].posY, insectGround[j].posX, insectGround[j].posY);
                if (distance<50) {
                    insectGround[j].ISize -=1;
                }
            }
        }
    }
    
}

////////////////////////DRAW--------------------------------------------------------------
void testApp::draw(){
    ofBackground(255);
    
    ///////////////////regend////////////////////////////////////////////////////////
    ofSetColor(0, 0, 0);
    ofDrawBitmapString("Digital Flower Garden ", 50,80);
    ofDrawBitmapString("FrameRate: " + ofToString(ofGetFrameRate()),50,100);
    ofDrawBitmapString("Full grown flower: "+ofToString(fullGrownFlower)+"/"+ofToString(raiseFlower.size()), 50,120);
    ofDrawBitmapString("Clouds: "+ ofToString(cloudWater.size()), 50,140);
    ofDrawBitmapString("Insects: "+ ofToString(insectGround.size()), 50,160);
    
    ofDrawBitmapString("Press f: to create flower" ,800,80);
    ofDrawBitmapString("Press c: to create Cloud"  ,800,100);
    ofDrawBitmapString("Press i: to create Insect" ,800,120);
    ofDrawBitmapString("Press s: to create Sun" ,800,140);
    ///////////////////////////////////////////////////////////////////////////////
    
    fullGrownFlower=0;
   cam.begin();

    ofRotateX(180);
    //ofRotateX(mouseY);
    //ofRotateY(ofGetMouseX());
    ofRotateY(rotationValue);
    rotationValue+=0.2;
    cam.setPosition(ofVec3f(0, 0,750*3));

    for( int i=0; i<raiseFlower.size();i++){
        raiseFlower[i].update();
        raiseFlower[i].draw();
    }
    for( int i=0; i<cloudWater.size();i++){
        cloudWater[i].update();
        cloudWater[i].draw();
    }


    // grass
    ofPushMatrix();
    ofTranslate(0,ofGetHeight());
    ofRotateX(90);
    ofSetColor(158, 211, 89);
    fboGrass.draw(-ofGetWidth(),-ofGetWidth());
    ofPopMatrix();
    
    //insect
    ofPushMatrix();
    //translate to make 3d!! I used 2d when I drew.
    ofTranslate(0,ofGetHeight());
    ofRotateX(90);
    for( int i=0; i<insectGround.size();i++){
        insectGround[i].update();
        insectGround[i].draw();
    }
    ofPopMatrix();
    
    //sun
    ofPushMatrix();
    //translate to make 3d!! I used 2d when I drew.
    ofTranslate(0,-500);
    ofRotateX(90);
    for( int i=0; i<sunLight.size();i++){
        sunLight[i].update();
        sunLight[i].draw();
    }
    ofPopMatrix();
    
    cam.end();
  
}


//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if( key =='f')
    raiseFlower.push_back(flower(ofRandom(-ofGetWidth(),ofGetWidth()),ofGetHeight(),ofRandom(-ofGetWidth(), ofGetWidth())));
    
    if(key =='c')
    cloudWater.push_back(cloud(ofRandom(-ofGetWidth(),ofGetWidth()),ofRandom(-ofGetHeight()/5, ofGetHeight()/5),ofRandom(-ofGetWidth(), ofGetWidth())));
    
    if(key =='i')
        insectGround.push_back(insect(ofRandom(-ofGetWidth(),ofGetWidth()),ofRandom(-ofGetWidth(),ofGetWidth()),0));
    
    if(key =='s')
        sunLight.push_back(sun(ofRandom(-ofGetWidth(),ofGetWidth()),ofRandom(-ofGetWidth(),ofGetWidth()),0));
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
