#include "ofApp.h"

float phase = TWO_PI; // separate u-noise from v-noise
float complexity = 3; // wind complexity
int step = 10; // spatial sampling rate
float timeSpeed = .02; // wind variation speed



ofPoint ofApp::getField(ofPoint position) {
    float normx = ofNormalize(position.x, 0, ofGetWidth());
    float normy = ofNormalize(position.y, 0, ofGetHeight());
    float u = ofNoise(t + phase, normx * complexity + phase, normy * complexity + phase);
    float v = ofNoise(t - phase, normx * complexity - phase, normy * complexity + phase);
    return ofVec2f(u, v);
}

void ofApp::setup(){
    ofSetVerticalSync(true); // don't go too fast
    ofEnableAlphaBlending();
    
    windSpeed = 500; // wind vector magnitude

    
    gui = new ofxDatGui( ofxDatGuiAnchor::TOP_LEFT );
    gui->addSlider("Complexity", 0, 20);
    gui->addSlider("Length", 1, 800);
    gui->addSlider("Speed", 0, .1);
    gui->onSliderEvent(this, &ofApp::onSliderEvent);
    gui->setOpacity(0.2);
    gui->addFooter();


}

void ofApp::update(){
    
    t = ofGetFrameNum() * timeSpeed;
}

void ofApp::draw(){
    
    ofBackgroundGradient(255, 100);
    
    for(int i = 0; i < ofGetWidth(); i += step) {
        for(int j = 0; j < ofGetHeight(); j += step) {
            ofVec2f field = getField(ofVec2f(i, j));
            ofPushMatrix();
            ofTranslate(i, j);
            ofSetColor(0,60);
            ofDrawLine(0, 0, ofLerp(-windSpeed, windSpeed, field.x), ofLerp(-windSpeed, windSpeed, field.y));
            ofPopMatrix();
        }
    }

}

void ofApp::onSliderEvent(ofxDatGuiSliderEvent e){
    if (e.target->is("Complexity")) complexity = e.target->getValue();
    if (e.target->is("Length")) windSpeed = e.target->getValue();
    if (e.target->is("Speed")) timeSpeed = e.target->getValue();
}