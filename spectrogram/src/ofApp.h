#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
    
        void audioIn(float * input, int bufferSize, int nChannels);

    
        ofSoundStream soundStream;
    
        vector <float> sound;
        int f;


};
