/*
 *  Name: Particle.cpp @ particle_fire_simulation project pfsim
 *  Description: library source file to control the individual particle on screen
 *  Created on: 05-05-17
 *  Author: Gavin Lyons
 */


#include <math.h>
#include <stdlib.h>

//mine
#include "Particle.h"


namespace pfsns {

//constructor
Particle::Particle() :
		m_x(0), m_y(0) {

	init();
}

void Particle::init() {
	m_x = 0;
	m_y = 0;
	m_direction = (2 * M_PI * rand()) / RAND_MAX;
	m_speed = (0.04 * rand()) / RAND_MAX;

	m_speed *= m_speed;
}

//destructor
Particle::~Particle() {
	// TODO Auto-generated  stub
}

 // change positions and speeds of particles
void Particle::update(int interval) {
   //give particles a curl
    m_direction += interval * 0.0003;

	double xspeed = m_speed * cos(m_direction);
	double yspeed = m_speed * sin(m_direction);

	m_x += xspeed * interval;
	m_y += yspeed * interval;

	if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1) {
		init();
	}

	if(rand() < RAND_MAX/100) {
		init();
	}

}
} /* namespace pfsns */
