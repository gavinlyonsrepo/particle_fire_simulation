#ifndef PARTICLE_H
#define PARTICLE_H
/*
 *  @file Particle.h @ particle_fire_simulation project pfsim
 *  @brief library header file
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
	//methods
	Particle();
	void update(int interval);
	virtual ~Particle();
};

} /* namespace pfsns */

#endif // PARTICLE_H
