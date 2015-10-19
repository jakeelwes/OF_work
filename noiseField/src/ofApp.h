#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"


class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
    
        ofPoint getField(ofPoint position);
    
    ofxDatGui* gui;
    void onSliderEvent(ofxDatGuiSliderEvent e);
    
    float t;
    float windSpeed;
    
};
