#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	ofEnableDepthTest();
	ofSetLineWidth(2);
	ofSetColor(255, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	this->cam.begin();

	float noise_value;

	ofFill();
	for (float radius = 3; radius <= 20; radius += 1) {
		ofBeginShape();
		for (int deg = 180; deg < 540; deg += 1) {
			float noise_x = 3 * (16 * sin(deg * DEG_TO_RAD) * sin(deg * DEG_TO_RAD) * sin(deg * DEG_TO_RAD));
			float noise_y = 3 * (13 * cos(deg * DEG_TO_RAD) - 5 * cos(2 * deg * DEG_TO_RAD) - 2 * cos(3 * deg * DEG_TO_RAD) - cos(4 * deg * DEG_TO_RAD));

			float x = radius * (16 * sin(deg * DEG_TO_RAD) * sin(deg * DEG_TO_RAD) * sin(deg * DEG_TO_RAD));
			float y = radius * (13 * cos(deg * DEG_TO_RAD) - 5 * cos(2 * deg * DEG_TO_RAD) - 2 * cos(3 * deg * DEG_TO_RAD) - cos(4 * deg * DEG_TO_RAD));
			noise_value = ofNoise(noise_x * 0.0025, noise_y * 0.0025, ofGetFrameNum() * 0.05 - radius * 0.05);
			if (noise_value < 0.65) {
				noise_value = 0.65;
			}
			float z = noise_value * 200 - 100;

			ofVertex(x, y, z);
		}
		ofEndShape();

		ofNoFill();
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}