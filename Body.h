#pragma once

#include "ofMain.h"

// enum
enum BodyType { Empty, Sun, Planet, MoonPlanet, RingPlanet };

class Body
{
public:

	float _distance = 0;
	float _size = 0;
	float _speed = 0;
	glm::vec2 _position;
	ofColor* _bodyColor = NULL;

	// constants
	const float _SUN_SIZE = 40.0f;
	const float _PLUTO_SIZE = 5.0f;
	const float _SUN_REAL = 1392000.0f;
	const float _PLUTO_REAL = 2306.0f;

	// Array of all daughter bodies
	Body*_bodies = NULL;
	int _bodyCount = 0;
	BodyType _bodyType = Empty;
	
	// constructors
	Body() {};
	Body(float distance, float size, float speed, ofColor* bodyColor, BodyType bodyType);

	// destructors
	~Body() {
		if (_bodyColor != NULL) delete _bodyColor;
		delete[] _bodies;
	};

	// used functions
	bool createSolarSystem();
	bool setBodyAttributes(float distance, float size, float speed, ofColor* color, BodyType bt);
	float relativeSizing(float realsize);

	// other methods
	void draw(); // draw on the screen
	void calc(); // update the position
	void drawRing(); // draw ring on a planet
};

