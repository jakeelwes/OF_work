#include "ofApp.h"

void ofApp::setup(){
    
    gui = new ofxDatGui( ofxDatGuiAnchor::TOP_RIGHT );
    gui->addSlider("size", 0, 500);
    gui->addColorPicker("** picker", ofColor::fromHex(0xeeeeee));
    
    gui->onSliderEvent(this, &ofApp::onSliderEvent);
    gui->onColorPickerEvent(this, &ofApp::onColorPickerEvent);
    
    gui->addFooter();
    
    
    size = 30;

}

void ofApp::update(){

}

void ofApp::draw(){
    ofDrawRectangle(ofGetWidth()/2-size/2, ofGetHeight()/2-size/2, size, size);
}



void ofApp::onColorPickerEvent(ofxDatGuiColorPickerEvent e){
    ofSetBackgroundColor(e.color);
}