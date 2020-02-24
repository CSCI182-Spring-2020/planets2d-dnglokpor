#pragma once

#include "ofMain.h"

class Body
{
private:
	float _distance = 0;
	float _size = 0;
	float _speed = 0;
	glm::vec2 _position;
	ofColor _bodyColor = NULL;
public:
	// constructors
	Body();
	Body(float distance, float size, float speed, ofColor bodyColor);

	// destructors
	~Body();

};

