#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(100);
    ofSetFrameRate(30);
    cN = 500;
    oscR = 0.011;
    oscG = 0.012;
    oscB = 0.013;
    sX = 100;
    ampX = 100;
    oscX = 0.08;
    sR = 40;
    aR = 35;
    oscRa = 0.01;
    aY = 50;
//    Allnighter.load("Allnighter_6.png");
    
    ampTrans = 0.3;
    trRate = 0.001;
    rotRate = 0.2;
    
    test1 = true;
    test2 = false;
    
    frameSpeed = 10;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    float time = ofGetElapsedTimef();
    float speed1 = 0.1;
    float speed2 = 0.3;
    float speed3 = 0.5;
    float speed4 = 0.01;
    
    float timing1 = sin (ofGetElapsedTimef() * speed1);
    float timing2 = sin (ofGetElapsedTimef() * speed2);
    float timing3 = sin (ofGetElapsedTimef() * speed3);
    
    frameSpeed = 150 * ofNoise (time * 0.05);
    
    // Events
    
    if (ofGetFrameNum() / frameSpeed % 30 < 10){
    
        sX = ofGetWidth()/5;
        sR = 40;
        aR = 15;
        aY = -100;
        startCol_R = 127;
        startCol_G = 127;
        startCol_B = 127;
        startAlpha = 255;


        oscR = ofMap (timing1, -1, 1, 0.01, 0.1);
        oscB = ofMap (timing1, -1, 1, 0.01, 0.5);
        oscX = 0.2 * ofNoise (time * speed1);
        ampX = 300 * ofNoise (time * speed4);
        oscRa = 0.01 * ofNoise (time * speed4);


        ampTrans = ofMap (timing1, -1, 1, 0.05, 0.15);
        trRate = ofMap (timing2, -1, 1, 0.001, 0.004);
        rotRate = 0.5 * ofNoise (time * speed4);
        ampRate = 0;
        coef1_xPos = 0.5 * ofNoise (time * 0.4);
        coef2_Rad = 5 * ofNoise (time * 0.6);
        stretch = ofMap (timing2, -1, 1, 0.1, 2);
        vitesse_de_pointe = 1.5 + ofNoise (time * speed4);
        cN = 500 - 200 * sin(ofNoise (time * 0.1));
//

    }
    
    else if (ofGetFrameNum() / frameSpeed % 30 > 10 && ofGetFrameNum()/10 % 30 < 20){

        sX = ofGetWidth()/5;
        sR = 30;
        aR = 25;
        aY = -200;
        startCol_R = 0;
        startCol_G = 127;
        startCol_B = 255;
        startAlpha = 255;
        
        oscR = ofMap (timing1, -1, 1, 0.4, 0.6);
        oscG = 0;
        oscB = ofNoise (time * 0.5);
        oscX = 0.2 * ofNoise (time * speed1);
        ampX = 300 * ofNoise (time * speed4);
        oscRa = 0.01 * ofNoise (time * speed4);
        
        
        ampTrans = ofMap (timing1, -1, 1, 0.05, 0.15);
        trRate = ofMap (timing2, -1, 1, 0.001, 0.004);
        rotRate = 0.5 * ofNoise (time * speed4);
        ampRate = ofNoise (time * speed4) / 5;
        coef1_xPos = 0.5 * ofNoise (time * 0.4);
        coef2_Rad = 5 * ofNoise (time * 0.6);
        stretch = ofMap (timing2, -1, 1, 0.1, 1);
        vitesse_de_pointe = 1.5 + ofNoise (time * speed4);
        cN = 500 - 200 * sin(ofNoise (time * 0.1));
}
    else if (ofGetFrameNum() / frameSpeed % 30 > 20){
        
        sX = ofGetWidth()/5;
        sR = 5;
        aR = 10;
        aY = 0;
        startCol_R = 0;
        startCol_G = 0;
        startCol_B = 250;
        startAlpha = 255;
        
        oscR = ofMap (timing1, -1, 1, 0.4, 0.6);
        oscG = 0;
        oscB = 0.4 + ofNoise (time * 0.5);
        oscX = -0.3 * ofNoise (time * speed1);
        ampX = 600 * ofNoise (time * speed4);
        oscRa = 0.005 * ofNoise (time * speed4);
        
        
        ampTrans = ofMap (timing1, -1, 1, 0.05, 0.15);
        trRate = ofMap (timing2, -1, 1, 0.1, 0.004);
        rotRate = 0.5 * ofNoise (time * speed4);
        ampRate = ofNoise (time * speed4) / 5;
        coef1_xPos = -0.5 * ofNoise (time * 0.4);
        coef2_Rad = -10 * ofNoise (time * 0.6);
        stretch = ofMap (timing2, -1, 1, 0.1, 0.5);
        vitesse_de_pointe = 1.6 + ofNoise (time * speed4);
        cN = 500 - 300 * sin(ofNoise (time * 0.4));

}
}


//--------------------------------------------------------------
void ofApp::draw(){
    background.r=0;
    background.g=0;
    background.b=0;
    ofSetColor(background);
    ofBackground(background);
//    Allnighter.draw(0, 0, ofGetWidth(), ofGetHeight());
    
    drawCircle(cN, oscR, oscG, oscB, sX, ampX, oscX, sR, aR, oscRa);



}

void ofApp::drawCircle(float _circle_Number, float _oscRate_R, float _oscRate_G, float _oscRate_B, float _start_xPos, float _amp_xPos, float _oscRate_xPos, float _start_Radius, float _amp_Radius, float _oscRate_Radius){
    
    float time = ofGetElapsedTimef();
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
    

    // Real shit
    for (int i = 0; i < circle_Number; i++){
        ofFill();
        colour_Red = startCol_R + 127 * sin(i * oscRate_R + time);
        colour_Green = startCol_G + 127 * sin(i * oscRate_G + time);
        colour_Blue = startCol_B + 127 * sin(i * oscRate_B + time);
        ofSetColor (colour_Red, colour_Green, colour_Blue, startAlpha);
        
        xPos = start_xPos + amp_xPos * 3 * ofNoise(i * oscRate_xPos * 0.05 + time * vitesse_de_pointe);
        yPos = aY + i; // 50 = Y offset
        Radius = start_Radius + amp_Radius * sin(i * oscRate_Radius + time);
        
        ofTranslate (ampTrans * sin(i * trRate + time), stretch);
        ofRotate (ampRate + sin(i * rotRate + time));
//        ofDrawTriangle(xPos, yPos, 100, 100, xPos + 200, yPos + 200);
//        ofDrawTriangle(xPos, yPos, xPos + ofNoise (time), yPos + 100, xPos - 100, yPos + 100);

        ofDrawCircle(xPos + xPos * coef1_xPos * ofNoise(time * 0.2 + i * 0.5), yPos, Radius + Radius * coef2_Rad * ofNoise(time * 0.2 + i * 0.5));
        }
    

    // Check values
    for (int i = 0; i < circle_Number; i++){
        int timecaca = ofGetFrameNum()/10 % 60;
        std::cout << "ampT: " << 100 * ofNoise (ofGetElapsedTimef() * 0.05) << endl;

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
