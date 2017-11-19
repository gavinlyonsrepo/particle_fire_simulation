#ifndef SWARM_H
#define SWARM_H
/*
 *  Name: Swarm.h @ particle_fire_simulation project pfsim
 *  Description: library header file
 *  Created on: 05-05-17
 *  Author: Gavin Lyons
 */

#include "Particle.h"

namespace pfsns {

class Swarm {
public:
	const static int NPARTICLES = 5000;

private:
	Particle * m_pParticles;
		int lastTime;

public:
	Swarm();
	virtual ~Swarm();
    void update(int elasped);
	const Particle * const getParticles() { return m_pParticles; };
};

} /* namespace pfsns */



#endif // SWARM_H
