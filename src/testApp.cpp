
 #include "testApp.h"


 ofVec3f testApp::famly2Screen12(int number,int x) {
 // hello i have change this
 // this is new
 float qqq;
 float adsfasdf;
 float www;
 
 float pointOrderValue = (x+1)/(float)number;
 float speedUp = speed[x]*50000;
 float pointTime = speedUp * pointOrderValue;
 float rad = MAX(2, len*.05);
 //////float CLScaler = 10000;
 
 float speedUp2 = speed[x]*100;
 float theta = ofMap((x+1)*TWO_PI,0,speedUp2 * TWO_PI, -1, 1.) / number;
 float rsin = rad * sin(speedUp*theta);
 float rcos = rad * cos(speedUp*theta)/1.618;
 float rtan = rad * tan(speedUp*theta);
 
 // 'classic' Rose type
 float len = (x+1)*rad/(float)number;
 
 temp.x = cos(pointTime)*len;
 temp.y = sin(pointTime)*len;
 
 temp.z = atan(theta)*rsin;
 
 temp.x = ofMap(temp.x, -1, 1,x * widthRose,(x * widthRose)+widthRose);
 temp.y = ofMap(temp.y, -1, 1,0,ofGetHeight());
 temp.z = ofMap(temp.z, -1, 1,x * widthRose, (x * widthRose)+widthRose);
 return temp;
 
 }
 
 //--------------------------------------------------------------
 void testApp::setup(){
 ofBackground(111, 111, 111);
 
 totalNumberRose = 3;
 widthRose =  ofGetWidth() / totalNumberRose ;
 
 tween = new ofxTweener*[totalNumberRose];
 for(int i = 0; i<totalNumberRose; i++){
 tween[i] = new ofxTweener();
 speed.push_back(0);
 speed[i] = 0;
 
 
 }
 for(int i = 0; i<totalNumberRose; i++){
 tween[i]->addTween(speed[i], .0022, ofRandom(4));
 }
     
     
     // print input ports to console
     midiIn.listPorts(); // via instance
     //ofxMidiIn::listPorts(); // via static as well
     
     // open port by number (you may need to change this)
     midiIn.openPort(0);
     //midiIn.openPort("IAC Pure Data In");	// by name
     //midiIn.openVirtualPort("ofxMidiIn Input");	// open a virtual port
     
     // don't ignore sysex, timing, & active sense messages,
     // these are ignored by default
     midiIn.ignoreTypes(true, true   , true);
     
     // add testApp as a listener
     midiIn.addListener(this);
     
     // print received messages to the console
     midiIn.setVerbose(false);
     
     rootFreq = 349.23; // f4
     
 }




 //--------------------------------------------------------------
 void testApp::update(){
 for(int q = 0; q < totalNumberRose;q++){
 tween[q]->update();
 }
 Tweener.update();
 
 
 }
 
 //--------------------------------------------------------------
 void testApp::draw(){
 ofSetColor(0, 0, 0);
 speed[0] += .00001;
 speed[1] += .00001;
 speed[2] += .00001;
 for(int q = 0; q < totalNumberRose;q++){
 for(int x = 0;x<4000;x++){
 ofVec3f aa = famly2Screen12(x,q);
 ofRect(aa.x,aa.y, 2, 2);
 }
 }
 }
 
 //--------------------------------------------------------------
 void testApp::keyPressed(int key){
 if(key == OF_KEY_BACKSPACE){
 ofToggleFullscreen();
 }
 
 
 switch (key) {
 case 'a':
 
 tween[0]->addTween(speed[0], ofRandom(10), 2);
 tween[1]->addTween(speed[1], ofRandom(10), 2);
 tween[2]->addTween(speed[2], ofRandom(10), 2);
 break;
 case 's':
 
 break;
 case 'd':
 
 break;
 case 'f':
 
 break;
 case 'g':
 
 break;
 case 'h':
 
 break;
 case 'j':
 
 break;
 case 'k':
 
 break;
 
 
 
 
 default:
 break;
 }
 
 
 }
 void numberChange(){
 
 //    for(int a = 0;a< totalNumberRose;a++ ){
 //        tween[a]->addTween(speed[a], ofRandom(.03), 2);
 //
 //
 //    }
 }

//--------------------------------------------------------------
void testApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void testApp::exit() {
	
	// clean up
	midiIn.closePort();
	midiIn.removeListener(this);
}

//--------------------------------------------------------------
void testApp::newMidiMessage(ofxMidiMessage& msg) {

    

    


    midiMessage = msg;
    
        if(midiMessage.channel == 1){
    cout << midiMessage.pitch << " i woking  " << endl;
    if((midiMessage.velocity != 0)){
        if (ofxMidiMessage::getStatusString(midiMessage.status) == "Note On"    ){
            lastMIDINoteIn = float(midiMessage.pitch -12);
            
            
            frequencyOne = 440 * pow(2.0,(lastMIDINoteIn-69.0+pitchBendDec)/12.0);
           // cout << "frequencyOne: " << frequencyOne << endl;

            ratioOne = frequencyOne / rootFreq;

            speed[0] =ratioOne;
            cout <<speed[0] << endl;
            tween[0]->addTween(speed[0], 1, 500);

        }
        
        // not really required but...
        if (ofxMidiMessage::getStatusString(midiMessage.status) == "Note Off"){
        }
        
        if (ofxMidiMessage::getStatusString(midiMessage.status) == "Pitch Bend"){
            pitchBend = midiMessage.value;
            pitchBendDec = ((pitchBend-8192)/4096);
            
            
            
        }
        
    }
            
          }

        if(midiMessage.channel == 2){

            if((midiMessage.velocity != 0)){
                if (ofxMidiMessage::getStatusString(midiMessage.status) == "Note On"    ){
                    lastMIDINoteIn = float(midiMessage.pitch -12);
                    
                    
                    frequencyTwo = 440 * pow(2.0,(lastMIDINoteIn-69.0+pitchBendDec)/12.0);
                    cout << "frequencyTwo: " << frequencyTwo << endl;
                    
                     ratioTwo = frequencyTwo / rootFreq;
                    
                    speed[2] =ratioTwo;
                    tween[2]->addTween(speed[2], 1, 500);
                }
                
                // not really required but...
                if (ofxMidiMessage::getStatusString(midiMessage.status) == "Note Off"){
                }
                
                if (ofxMidiMessage::getStatusString(midiMessage.status) == "Pitch Bend"){
                    pitchBend = midiMessage.value;
                    pitchBendDec = ((pitchBend-8192)/4096);
                    
                    
                }

            
            
            
        }
    }
    
    
}




//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {
}

//--------------------------------------------------------------
void testApp::mouseReleased() {
}
