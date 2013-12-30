#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofEnableDepthTest();
    
    ofSetVerticalSync(true);
    
    ofSetFrameRate(30);
    
    fsOut = new ofxBMFrameSync();
    
    
    
}

//--------------------------------------------------------------
void testApp::exit(){
    delete fsOut;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    return;
    fsOut->externLock();
    ofBackground(120, 0, 0);
    ofTranslate(100, 100);
    ofRotate(ofGetFrameNum(), 0, 0, 1);
    ofRect(0, 0, 100, 100);
    //ofDrawBitmapString(ofToString(ofGetFrameNum()), 100,100);
    fsOut->externUnlock();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}