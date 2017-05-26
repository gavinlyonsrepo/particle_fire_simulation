#ifndef SWARM_H
#define SWARM_H
/*
 * Swarm.h
 *
 *  Created on: 13 Sep 2014
 *      Author: johnwpurcell
 */

#include "Particle.h"

namespace caveofprogramming {

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

} /* namespace caveofprogramming */



#endif // SWARM_H
