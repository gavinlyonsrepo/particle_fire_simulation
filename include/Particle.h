#ifndef PARTICLE_H
#define PARTICLE_H
/*
 * Particle.h
 *
 *  Created on: 13 Sep 2014
 *      Author: johnwpurcell
 */
namespace caveofprogramming {

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

} /* namespace caveofprogramming */

#endif // PARTICLE_H
