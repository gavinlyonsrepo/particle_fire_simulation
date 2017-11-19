/*
 *  Name: Swarm.cpp @ particle_fire_simulation project pfsim
 *  Description: library source file to control the swarm of particles on screen
 *  Created on: 05-05-17
 *  Author: Gavin Lyons
 */

#include "Swarm.h"

namespace pfsns {

Swarm::Swarm(): lastTime(0) {
	m_pParticles = new Particle[NPARTICLES];

}

Swarm::~Swarm() {
	delete [] m_pParticles;
}

void Swarm::update(int elapsed) {
	int interval = elapsed - lastTime;

	for (int i = 0; i < Swarm::NPARTICLES; i++) {
		m_pParticles[i].update(interval);
	}

	lastTime = elapsed;
}


} /* namespace pfsns */
