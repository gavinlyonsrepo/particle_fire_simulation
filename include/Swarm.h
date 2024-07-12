#ifndef SWARM_H
#define SWARM_H
/*
 *  @file Swarm.h @ particle_fire_simulation project pfsim
 *  @brief library header file
 */

#include "Particle.h"

namespace pfsns {

class Swarm {
public:
	// number of particles
	int NPARTICLES;

private:
	Particle * m_pParticles;
	//last time simulation ran
		int lastTime;

public:
	Swarm(int nParticles);
	virtual ~Swarm();
	void update(int elasped);
	const Particle * const getParticles() { return m_pParticles; };
};

} /* namespace pfsns */



#endif // SWARM_H
