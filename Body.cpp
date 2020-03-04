#pragma once

#include "Body.h"

#define PLANET_COUNT 9

Body::Body(float distance, float size, float speed, ofColor* bodyColor, BodyType bodyType) {
	// Setup the body variables
	_distance = distance;
	_size = relativeSizing(size);
	_speed = speed;
	_bodyColor = bodyColor;

	// setup the position
	glm::vec2 vPos(0, distance * -1);
	_position = vPos;
	_bodyType = bodyType;

	// Setup the body its sub bodies
	createSolarSystem();
}

bool Body::createSolarSystem() {
	int mDist = 0;
	switch (_bodyType)
	{
	case Sun:
		_bodyCount = PLANET_COUNT;
		_bodies = new Body[_bodyCount]; // planets
		mDist = 85;
		// mercury
		_bodies[0].setBodyAttributes(mDist, 4880.0f, .04, new ofColor(107, 49, 11), Planet);
		// venus
		_bodies[1].setBodyAttributes(mDist * 1.6, 12102.0f, .03, new ofColor(216, 102, 53), Planet);
		// earth
		_bodies[2].setBodyAttributes(mDist * 2.2, 12756.0f, .029, new ofColor(36, 53, 91), MoonPlanet);
		// mars
		_bodies[3].setBodyAttributes(mDist * 2.8, 9796.0f, .025, new ofColor(162, 102, 76), Planet);
		// jupiter
		_bodies[4].setBodyAttributes(mDist * 3.6, 142984.0f, .031, new ofColor(255, 214, 157), Planet);
		// saturn
		_bodies[5].setBodyAttributes(mDist * 4.2, 120536.0f, .021, new ofColor(207, 187, 151), RingPlanet);
		// uranus
		_bodies[6].setBodyAttributes(mDist * 4.8, 51118.0f, .025, new ofColor(140, 186, 233), Planet);
		// neptune
		_bodies[7].setBodyAttributes(mDist * 5.4, 49528.0f, .016, new ofColor(1, 53, 160), Planet);
		// pluto
		_bodies[8].setBodyAttributes(mDist * 6, _PLUTO_REAL, .024, new ofColor(85, 87, 73), Planet);
		break;
	case MoonPlanet:
		_bodyCount = 1; // moons
		_bodies = new Body[_bodyCount];
		mDist = 20;
		// moon
		_bodies[0].setBodyAttributes(mDist + (_size / 2.0f), 3474, .04, new ofColor(129, 102, 109), Empty);
		break;
	case RingPlanet:
		_bodyCount = 0;
		_bodies = NULL;
		drawRing();
		break;
	default:
		_bodyCount = 0;
		_bodies = NULL;
		break;
	}

	return true;
}

bool Body::setBodyAttributes(float distance, float size, float speed, ofColor* bodyColor, BodyType bodyType) {
	_distance = distance;
	_size = relativeSizing(size);
	_speed = speed;
	_bodyColor = bodyColor;
	glm::vec2 vPos(0, distance * -1);
	_position = vPos;
	_bodyType = bodyType;
	createSolarSystem();

	return true;
}
/// <summary>
/// Draw a Body instance to the screen.
/// </summary>
void Body::draw() {
	ofPushMatrix();

	ofSetColor(*_bodyColor);
	ofTranslate(_position);
	ofDrawCircle(0.0, 0.0, _size);

	for (int i = 0; i < _bodyCount; i++) {
		_bodies[i].draw();
	}

	ofPopMatrix();
}

/// <summary>
/// Updates the position of the bodies each frame
/// </summary>
void Body::calc() {
	_position.x = cos(ofGetFrameNum() * _speed) * _distance;
	_position.y = sin(ofGetFrameNum() *_speed) * _distance;

	for (int i = 0; i < _bodyCount; i++) {
		_bodies[i].calc();
	}
}

// return relative sizes of bodies
float Body::relativeSizing(float realsize) {
	return ofMap(realsize, _PLUTO_REAL, _SUN_REAL, _PLUTO_SIZE, _SUN_SIZE);
}

/// <summary>
/// Draw a rings on planets
/// </summary>
void Body::drawRing() {
	ofPushMatrix();

	ofRotate(27.0);
	ofTranslate(_position);
	ofSetColor(ofColor::black);
	ofDrawRectangle(-_size, 0.0, _size, 2.0);
	ofSetColor(*_bodyColor);
	ofDrawRectangle(-_size + 2.0, 0.0 + 2.0, _size, 2.0);

	ofPopMatrix();
}