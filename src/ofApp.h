#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
    void drawCircle(float _circle_Number, float _oscRate_R, float _oscRate_G, float _oscRate_B, float _start_xPos, float _amp_xPos, float _oscRate_xPos, float _start_Radius, float _amp_Radius, float _oscRate_Radius);
    

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
private:
    
    float colour_Red;
    float colour_Green;
    float colour_Blue;
    
    float circle_Number;
    float oscRate_R, oscRate_G, oscRate_B;
    
    float xPos, yPos, Radius;
    float start_xPos, start_yPos;
    float amp_xPos, amp_yPos;
    float oscRate_xPos, oscRate_yPos;
    float start_Radius, amp_Radius, oscRate_Radius;
    
    float cN, oscR, oscG, oscB, sX, sY, ampX, ampY, oscX, oscY, sR, aR, oscRa;
    float ampTrans, trRate, rotRate, ampRate;
    
    float coef1_xPos, coef2_Rad;
    float stretch;
    float vitesse_de_pointe;
    float aY;
    
    bool test1, test2;
    
    int frameSpeed;
    float startCol_R, startCol_G, startCol_B, startAlpha;
    ofColor background;

    
    ofImage Allnighter;
    
    ofCamera camera;
    
    
		
};
