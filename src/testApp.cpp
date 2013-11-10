#include "testApp.h"



ofVec3f testApp::famly2Screen12(int number,int x) {


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
void testApp::keyReleased(int key){

    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

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
    widthRose =  ofGetWidth() / totalNumberRose ;
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}