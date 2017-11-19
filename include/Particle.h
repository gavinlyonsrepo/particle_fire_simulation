#ifndef PARTICLE_H
#define PARTICLE_H
/*
 *  Name: Particle.h @ particle_fire_simulation project pfsim
 *  Description: library header file
 *  Created on: 05-05-17
 *  Author: Gavin Lyons
 */

namespace pfsns {

struct Particle {
	double m_x;
	double m_y;

    double m_speed;
	double m_direction;

private:
	void init();

public:
	Particle();
    void update(int interval);
	virtual ~Particle();
};

} /* namespace pfsns */

#endif // PARTICLE_H
