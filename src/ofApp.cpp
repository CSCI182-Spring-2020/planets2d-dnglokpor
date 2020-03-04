#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	// Setup the window
	ofBackground(0, 0, 0);
	ofSetCircleResolution(50);
	ofSetVerticalSync(true);
	ofSetFrameRate(60);

	// Setup the sun
	s = new Body(0, 1392000.0f, 0.0f, new ofColor(248, 222, 126), Sun);
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofPushMatrix();
	// go to the middle of the screen
	ofTranslate(ofGetWidth() / 2.0f, ofGetHeight() / 2.0f);
	// draw the sun
	s->draw();
	
	ofPopMatrix();

	s->calc();
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
