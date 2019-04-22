#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetCircleResolution(100);
    ofSetFrameRate(30);

// Arbitrary values to reproduce a warm
    
    cN = 500; // number of circles
    
    // Colour
    oscR = 0.011; // red value
    oscG = 0.012; // green value
    oscB = 0.013; // blue value
    
    // X Position
    sX = 100; // x position at the start
    ampX = 100; // amplitude of the x position at the start
    oscX = 0.08; // rate of the oscillation of the x position
    
    // Radius
    sR = 40; // radius value at the start
    aR = 35; // amplitude of the radius at the start
    oscRa = 0.01;
    aY = 50;
    
    // Transformation
    ampTrans = 0.3; // the amplitude of the transformation
    trRate = 0.001; // the rate of the transformation
    rotRate = 0.2; // the rate of the rotation
    
    frameSpeed = 10; // value to divide the frame rate
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
// ANIMATION
    
// Set up the different speed values ...
    float time = ofGetElapsedTimef();
    float speed1 = 0.1;
    float speed2 = 0.3;
    float speed3 = 0.5;
    float speed4 = 0.01;
    
// ... to create sine waves with different frequencies
    float timing1 = sin (ofGetElapsedTimef() * speed1);
    float timing2 = sin (ofGetElapsedTimef() * speed2);
    float timing3 = sin (ofGetElapsedTimef() * speed3);
    
    frameSpeed = 150 * ofNoise (time * 0.05);
    
// EVENTS
// 3 main events repeating
// Variables get updated at each event
    

// 1st Event
    
    if (ofGetFrameNum() / frameSpeed % 30 < 10){
        
    // Change the value of the variables once
        sX = ofGetWidth()/5;
        sR = 40;
        aR = 15;
        aY = -100;
        startCol_R = 127;
        startCol_G = 127;
        startCol_B = 127;
        startAlpha = 255;

    // Change the value of the variables continuously
    // Scale values of the sine functions (-1, 1) to desired values
        oscR = ofMap (timing1, -1, 1, 0.01, 0.1);
        oscB = ofMap (timing1, -1, 1, 0.01, 0.5);
        ampTrans = ofMap (timing1, -1, 1, 0.05, 0.15);
        trRate = ofMap (timing2, -1, 1, 0.001, 0.004);
        stretch = ofMap (timing2, -1, 1, 0.1, 2);

    // Use perlin noise for organic random fluid simulation
        oscX = 0.2 * ofNoise (time * speed1);
        ampX = 300 * ofNoise (time * speed4);
        oscRa = 0.01 * ofNoise (time * speed4);
        rotRate = 0.5 * ofNoise (time * speed4);
        ampRate = 0;
        coef1_xPos = 0.5 * ofNoise (time * 0.4); // factor to alter the x position
        coef2_Rad = 5 * ofNoise (time * 0.6); // factor to alter the radius
        vitesse_de_pointe = 1.5 + ofNoise (time * speed4); // speed of the warm
        
    // Change the number of circles drawn
        cN = 500 - 200 * sin(ofNoise (time * 0.1));
    }
    
// 2nd Event
    
    else if (ofGetFrameNum() / frameSpeed % 30 > 10 && ofGetFrameNum()/10 % 30 < 20){

    // Change the value of the variables once
        sX = ofGetWidth()/5;
        sR = 30;
        aR = 25;
        aY = -200;
        startCol_R = 0;
        startCol_G = 127;
        startCol_B = 255;
        startAlpha = 255;
        
    // Change the value of the variables continuously
    // Scale values of the sine functions (-1, 1) to desired values
        oscR = ofMap (timing1, -1, 1, 0.4, 0.6);
        ampTrans = ofMap (timing1, -1, 1, 0.05, 0.15);
        trRate = ofMap (timing2, -1, 1, 0.001, 0.004);
        stretch = ofMap (timing2, -1, 1, 0.1, 1);

    // Use perlin noise for organic random fluid simulation
        oscG = 0;
        oscB = ofNoise (time * 0.5);
        oscX = 0.2 * ofNoise (time * speed1);
        ampX = 300 * ofNoise (time * speed4);
        oscRa = 0.01 * ofNoise (time * speed4);
        rotRate = 0.5 * ofNoise (time * speed4);
        ampRate = ofNoise (time * speed4) / 5;
        coef1_xPos = 0.5 * ofNoise (time * 0.4);
        coef2_Rad = 5 * ofNoise (time * 0.6);
        vitesse_de_pointe = 1.5 + ofNoise (time * speed4);
        
    // Change the number of circles drawn
        cN = 500 - 200 * sin(ofNoise (time * 0.1));
}
    
// 3rd Event
    
    else if (ofGetFrameNum() / frameSpeed % 30 > 20){
        
    // Change the value of the variables once
        sX = ofGetWidth()/5;
        sR = 5;
        aR = 10;
        aY = 0;
        startCol_R = 0;
        startCol_G = 0;
        startCol_B = 250;
        startAlpha = 255;
        
    // Change the value of the variables continuously
    // Scale values of the sine functions (-1, 1) to desired values
        oscR = ofMap (timing1, -1, 1, 0.4, 0.6);
        ampTrans = ofMap (timing1, -1, 1, 0.05, 0.15);
        trRate = ofMap (timing2, -1, 1, 0.1, 0.004);
        stretch = ofMap (timing2, -1, 1, 0.1, 0.5);
        
    // Use perlin noise for organic random fluid simulation
        oscG = 0;
        oscB = 0.4 + ofNoise (time * 0.5);
        oscX = -0.3 * ofNoise (time * speed1);
        ampX = 600 * ofNoise (time * speed4);
        oscRa = 0.005 * ofNoise (time * speed4);
        rotRate = 0.5 * ofNoise (time * speed4);
        ampRate = ofNoise (time * speed4) / 5;
        coef1_xPos = -0.5 * ofNoise (time * 0.4);
        coef2_Rad = -10 * ofNoise (time * 0.6);
        vitesse_de_pointe = 1.6 + ofNoise (time * speed4);
        
    // Change the number of circles drawn
        cN = 500 - 300 * sin(ofNoise (time * 0.4));

}
}


//--------------------------------------------------------------
void ofApp::draw(){

// Black background
    background.r=0;
    background.g=0;
    background.b=0;
    ofSetColor(background);
    ofBackground(background);
    
// Draw circles
    drawCircle(cN, oscR, oscG, oscB, sX, ampX, oscX, sR, aR, oscRa);



}

// Main function

void ofApp::drawCircle(float _circle_Number, float _oscRate_R, float _oscRate_G, float _oscRate_B, float _start_xPos, float _amp_xPos, float _oscRate_xPos, float _start_Radius, float _amp_Radius, float _oscRate_Radius){
    
    // Assign variables to the attributes of the function
    
    circle_Number = _circle_Number;
    
    oscRate_R = _oscRate_R;
    oscRate_G = _oscRate_G;
    oscRate_B = _oscRate_B;
    
    start_xPos = _start_xPos;
    amp_xPos = _amp_xPos;
    oscRate_xPos = _oscRate_xPos;
    
    start_Radius = _start_Radius;
    amp_Radius = _amp_Radius;
    oscRate_Radius = _oscRate_Radius;
    
// To make the warm wiggle :
    // - sine functions and perlin noise to alter the coordinates of the center of the circles and the radius of the circles
    // - translate and Rotate the circles
    
// Equation : y = b + amp * sin (i * rate + time)
    // where b is the start position, amp the amplitude and i the number of circles
// Inspired from Zach Lieberman poetic computation talk
    // https://www.youtube.com/watch?v=bmztlO9_Wvo
    
    for (int i = 0; i < circle_Number; i++){
    // Time
        float time = ofGetElapsedTimef();
    // Colour
        ofFill();
        colour_Red = startCol_R + 127 * sin(i * oscRate_R + time);
        colour_Green = startCol_G + 127 * sin(i * oscRate_G + time);
        colour_Blue = startCol_B + 127 * sin(i * oscRate_B + time);
        ofSetColor (colour_Red, colour_Green, colour_Blue, startAlpha);
    // X and Y coordinates
        xPos = start_xPos + amp_xPos * 3 * ofNoise(i * oscRate_xPos * 0.05 + time * vitesse_de_pointe);
        yPos = aY + i;
    // Radius
        Radius = start_Radius + amp_Radius * sin(i * oscRate_Radius + time);
    // Transformation
        ofTranslate (ampTrans * sin(i * trRate + time), stretch);
        ofRotate (ampRate + sin(i * rotRate + time));
    // Draw
        ofDrawCircle(xPos + xPos * coef1_xPos * ofNoise(time * 0.2 + i * 0.5), yPos, Radius + Radius * coef2_Rad * ofNoise(time * 0.2 + i * 0.5));
    // Alternatives
        //        ofDrawTriangle(xPos, yPos, 100, 100, xPos + 200, yPos + 200);
        //        ofDrawTriangle(xPos, yPos, xPos + ofNoise (time), yPos + 100, xPos - 100, yPos + 100);
        }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
