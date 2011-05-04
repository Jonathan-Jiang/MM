/*
 * NearCamera.cpp
 *
 *  Created on: Jul 21, 2010
 *      Author: pinto
 */

#include "DoubleCamera.h"
#include "Car.h"
#include "PlayerManager.h"

namespace Micromachines {

	DoubleCamera::DoubleCamera() : Entity("NearCamera")
	{
	}

	DoubleCamera::~DoubleCamera()
	{
	}

	void DoubleCamera::init() {
		cg::tWindow win = cg::Manager::instance()->getApp()->getWindow();
		_pm = (PlayerManager*) cg::Registry::instance()->get("PlayerManager");
		_car = NULL;
		_winWidth = win.width;
		_winHeight = win.height;
	}

	void DoubleCamera::draw()
	{	
		if (_car == NULL) {
			_car = _pm->firstPlayer();
		} else {
			_position = -_car->getPosition();
			double _rotation = _car->getRotation();
			
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(60, _winWidth/_winHeight, 1, 3000);
			gluLookAt(-_position[0] -100 , -_position[1], -355, 
				  -_position[0], -_position[1], -396, 
				  0, 0 , 1);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
		}

	}
}


