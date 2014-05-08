#pragma once

#include "ofMain.h"
#include "flower.h"
#include "cloud.h"
#include "insect.h"
#include "sun.h"


class testApp : public ofBaseApp{

	public:
		
    
    void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    float w;
    
   // ofCamera cam;
    ofEasyCam cam;
    
    vector<flower> raiseFlower;
    vector<cloud> cloudWater;
    vector<insect> insectGround;
    vector<sun> sunLight;
    //cloud testCloud;
    
    ofFbo fboGrass;
    
    int fullGrownFlower;
    
    float rotationValue;
    
    

};
