#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofEnableDepthTest();
    
    ofSetVerticalSync(false);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    if(fbo.getWidth() != ofGetWidth() || fbo.getHeight()!=ofGetHeight())
        fbo.allocate(ofGetWidth(),ofGetHeight(),GL_RGBA,8);
    static int renderFr = 0;
    
    for(int fr = 0; fr < 600 ; fr++){
        
        fbo.begin();
        
        ofBackground(0,0,0);
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofRotate(renderFr*3, 1, 1, 0.5);
        ofSetColor(255, 0, 0);
        ofBoxPrimitive(200,200,200).draw();
        ofPopMatrix();
        ofDrawBitmapString(ofToString(ofGetFrameRate(),2), 20,20);
        fbo.end();
        fbo.draw(0,0);
        
        
        if(ofGetFrameNum()<5)
            return;
        
        ofPixels pix;
        pix.allocate(ofGetWidth(),ofGetHeight(),OF_IMAGE_COLOR_ALPHA);
        
        fbo.readToPixels(pix);
        
        int totalpix = ofGetWidth()*ofGetHeight();
        unsigned char c;
        unsigned char* buf = pix.getPixels();
        for(int i=0;i<totalpix;i++){
            c = buf[i*4];
            buf[i*4] = buf[i*4 + 2];
            buf[i*4+2] = c;
        }
        
        while(fsOut.getFramePosition() < 0.5f){
            
            sleep(0);
        }
        while(fsOut.getFramePosition() >= 0.5f){
            sleep(0);
        }
        
        fsOut.renderFrame(buf, totalpix*4);
        
        renderFr++;
    }
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