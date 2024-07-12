/*
 *  @file Swarm.cpp @ particle_fire_simulation project pfsim
 *  @brief library source file to control the swarm of particles on screen
 */

#include "Swarm.h"

namespace pfsns {

// constructor
Swarm::Swarm(int nparticles): lastTime(0) {
	NPARTICLES = nparticles;
	m_pParticles = new Particle[NPARTICLES];

}

Swarm::~Swarm() {
	delete [] m_pParticles;
}

//update the swarm positions
void Swarm::update(int elapsed) {


	int interval = elapsed - lastTime;
    //loop thru the particles
	for (int i = 0; i < Swarm::NPARTICLES; i++) {
		m_pParticles[i].update(interval);
	}

	lastTime = elapsed;
}


} /* namespace pfsns */
