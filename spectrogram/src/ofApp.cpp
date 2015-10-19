#include "ofApp.h"

void ofApp::setup(){
    
    
    int bufferSize = ofGetWidth()/2;
    sound.assign(bufferSize, 0.0);
    
    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);

    
}

void ofApp::update(){
}

void ofApp::draw(){
    
    ofSetBackgroundAuto(false);
    
    f++;
    
//    for (unsigned int i = 0; i < sound.size(); i++){     //spectro attempt
//        ofSetColor(255-sound[i]);
//        ofDrawRectangle(i*2, f, i*2+2, f+1);
//        
//        //        ofVertex(i*2, ofGetHeight()/2 -sound[i]*180.0f);
//    }
//    
    ofBeginShape();
    ofSetColor(0,20);
    ofNoFill();
    for (unsigned int i = 0; i < sound.size(); i++){
        ofVertex(i*2, f -sound[i]*0.2);
    }
    ofEndShape();
    
}

void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    for (int i = 0; i < bufferSize; i++){
        sound[i]		= fabs(ofMap(input[i+1]*0.5, -1, 1,-255,255));
        
//        std::cout<<sound[i]<<std::endl;
    }
}