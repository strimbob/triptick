#pragma once

#include "ofMain.h"
#include "ofxTweener.h"

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    void numberChange();
    
    ofVec3f famly2Screen12(int x,int posX);
        float len;
  //  float speed;
    ofVec3f temp;
    ofSoundPlayer play;
    ofSoundStream str;
    int totalNumberRose;
    int widthRose;
      ofxTweener** tween;
    vector < float > speed;
    
    float rsin;
    float theta;
    float speedUp;
    float speedUp2;
    float pointOrderValue;
    float pointTime;
    float rad ;
};
