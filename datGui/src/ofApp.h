#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"


class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
    
        ofxDatGui* gui;
        void onSliderEvent(ofxDatGuiSliderEvent e);
        void onColorPickerEvent(ofxDatGuiColorPickerEvent e);

        float size;

};
