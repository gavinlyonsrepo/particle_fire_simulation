//============================================================================
// Name        : main.cpp @ particle_fire_simulation project pfsim
// Author      : Gavin Lyons
// Version     : 1.0-1
// Copyright   : GPL
// Description : Graphic animation particle fire simulation created using SDL
// Date        : 05-05-17
//============================================================================
#include <iostream>
#include <math.h>
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <time.h>

//my libraries
#include "Screen.h"
#include "Swarm.h"

using namespace std;
using namespace pfsns;

int main()
{
    //seed the random generator with time function
    srand(time(NULL));
    //define a screen object with Screen class
 	Screen screen;


	if(screen.init() == false) {
		cout << "Error initialising SDL." << endl;
	}
    //define swarm object with Swarm class
    Swarm swarm;

	while (true) {
            //Returns an unsigned 32-bit value representing the number of milliseconds since the SDL library initialized.
          int elapsed = SDL_GetTicks();

         // Update particles
		swarm.update(elapsed);

        // Draw particles
        //assign RGB colours * elapsed to slow it done send to sin function
		unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);

        const Particle * const pParticles = swarm.getParticles();

		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
            int y = particle.m_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT/2;
            //set pixel colour and position within limits
			screen.setPixel(x, y, red, green, blue);
		}

		screen.boxBlur();

		// Draw the screen
		screen.update();

		// Check for messages/events eg quit event
		if(screen.processEvents() == false) {
			break;
		}
	}

	screen.close();

	return 0;
}
