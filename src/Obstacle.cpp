//
//  Obstacle.cpp
//  cglib
//
//  Created by Inês on 3/24/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "Obstacle.h"

namespace Micromachines {
    
	int Obstacle::RandomBeetween(int min, int max)
	{
		return (rand() % (max-min) + min);
	}
    
	Obstacle::Obstacle(std::string name) : Collidable(name){}
    
	Obstacle::~Obstacle(){}
    
	void Obstacle::init()
	{
		_winWidth = cg::Manager::instance()->getApp()->getWindow().width;
		_winHeight = cg::Manager::instance()->getApp()->getWindow().height;
		_position = cg::Vector3d(RandomBeetween(27, (_winWidth-27)), RandomBeetween(27, (_winHeight-27)), -400);
		_color = cg::Vector3d(0.9, 0.9, 0.9);
		int i = rand()%2;
		if (i == 0) {
			_isMovable = true;
		} else _isMovable = false;
		_initialPos = _position;
		_direction = -1;
		_size = cg::Vector2d(27, 18);
	}
    
	void Obstacle::draw()
	{
		glColor3d(_color[0], _color[1], _color[2]);
		glBegin(GL_QUADS);
			glVertex3d(_position[0]-_size[0], _position[1]+_size[1], -400);       
			glVertex3d(_position[0]-_size[0], _position[1]-_size[1], -400);       
			glVertex3d(_position[0]+_size[0], _position[1]-_size[1], -400);       
			glVertex3d(_position[0]+_size[0], _position[1]+_size[1], -400);
		
			//bottom
			glVertex3d(_position[0]-_size[0], _position[1]+_size[1], -395);       
			glVertex3d(_position[0]-_size[0], _position[1]-_size[1], -395);       
			glVertex3d(_position[0]+_size[0], _position[1]-_size[1], -395);       
			glVertex3d(_position[0]+_size[0], _position[1]+_size[1], -395);
		
			//side1
			glVertex3d(_position[0]-_size[0], _position[1]-_size[1], -400);
			glVertex3d(_position[0]+_size[0], _position[1]-_size[1], -400);
			glVertex3d(_position[0]+_size[0], _position[1]-_size[1], -395);
			glVertex3d(_position[0]-_size[0], _position[1]-_size[1], -395);
		
			//side2
			glVertex3d(_position[0]+_size[0], _position[1]-_size[1], -400);
			glVertex3d(_position[0]+_size[0], _position[1]+_size[1], -400);
			glVertex3d(_position[0]+_size[0], _position[1]+_size[1], -395);
			glVertex3d(_position[0]+_size[0], _position[1]-_size[1], -395);
			
			//side3
			glVertex3d(_position[0]-_size[0], _position[1]+_size[1], -400);
			glVertex3d(_position[0]+_size[0], _position[1]+_size[1], -400);
			glVertex3d(_position[0]+_size[0], _position[1]+_size[1], -395);
			glVertex3d(_position[0]-_size[0], _position[1]+_size[1], -395);
		
			//side4
			glVertex3d(_position[0]-_size[0], _position[1]-_size[1], -400);
			glVertex3d(_position[0]-_size[0], _position[1]+_size[1], -400);
			glVertex3d(_position[0]-_size[0], _position[1]+_size[1], -395);
			glVertex3d(_position[0]-_size[0], _position[1]-_size[1], -395);

		
		glEnd();
	}
    
	void Obstacle::update(unsigned long elapsed_millis) 
	{
		if (_isMovable) {
			if(_position[0] <= _initialPos[0] - MAX_MOV){
				_direction = 1;
				_position[0] += VELOCITY;
			}
			if (_position[0] >= _initialPos[0] + MAX_MOV) {
				_direction = -1;
				_position[0] -= VELOCITY;
			}
			if (_position[0] <= _initialPos[0] && _direction == -1){
				_position[0] -= VELOCITY;
			}
			if (_position[0] <= _initialPos[0] && _direction == 1){
				_position[0] += VELOCITY;
			}
			if (_position[0] > _initialPos[0] && _direction == -1){
				_position[0] -= VELOCITY;
			}
			if (_position[0] > _initialPos[0] && _direction == 1){
				_position[0] += VELOCITY;
			}
		}
		
	}
	
	cg::Vector3d Obstacle::getPosition()
	{
		return _position;
	}
	
	cg::Vector2d Obstacle::getSize()
	{
		return _size;
	}
    
}
