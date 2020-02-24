#pragma once

#include "Body.h"

using namespace std;

/// <summary>
/// instantiate an empty celestial object.
/// </summary>
Body::Body() {
	_distance = 0.0f;
	_size = 0.0f;
	_speed = 0.0f;
	_position = glm::vec2(0,0);
	_bodyColor = ofColor::black;
}
