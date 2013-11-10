/*
 * Copyright (c) 2013 Dan Wilcox <danomatika@gmail.com>
 *
 * BSD Simplified License.
 * For information on usage and redistribution, and for a DISCLAIMER OF ALL
 * WARRANTIES, see the file, "LICENSE.txt," in this distribution.
 *
 * See https://github.com/danomatika/ofxMidi for documentation
 *
 */
#pragma once

#include "ofMain.h"

#include "ofxMidi.h"
#include "ofxTweener.h"

class testApp : public ofBaseApp, public ofxMidiListener {
	
public:
	
	void setup();
	void update();
	void draw();
	void exit();
	
	void keyPressed(int key);
	void keyReleased(int key);
	
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased();
	
	void newMidiMessage(ofxMidiMessage& eventArgs);
	
	stringstream text;
	
	ofxMidiIn midiIn;
	ofxMidiMessage midiMessage;
    int count;
    
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
    float frequency;
       float pitchBend, pitchBendDec, lastMIDINoteIn;
    
};
