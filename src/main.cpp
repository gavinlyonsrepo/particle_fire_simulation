/*
	@file main.cpp @ particle_fire_simulation project pfsim
	@brief Graphic animation particle fire simulation created using SDL
*/
#include <iostream>
#include <math.h>
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <time.h>
#include <string>

//my libraries
#include "Screen.h"
#include "Swarm.h"

#define SCRN_WIDTH_DEFAULT 800
#define SCRN_HEIGHT_DEFAULT 600
#define NUM_OF_PARTICLES_DEFAULT 5000
#define RGB_COLOUR_BITS_DEFAULT 7 
#define NUMBER_OF_ITERATIONS 1000

using namespace pfsns;

int main(int argc, char **argv)
{
	int numberOfParticles = NUM_OF_PARTICLES_DEFAULT;
	int rgbColorBits = RGB_COLOUR_BITS_DEFAULT;
	int loopCount = NUMBER_OF_ITERATIONS;

	const std::string myStringHeader = ": Particle fire sim : ";
	std::cout << myStringHeader << "Started." << std::endl;
	//seed the random generator with time function
	std::srand(time(NULL));
	//define a screen object with Screen class
 	Screen screen;

	// Parse command line arguments 
	if (argc != 6)
	{
		std::cout << myStringHeader <<  "Number of input arguments :: " << argc << '\n';
		std::cout <<  myStringHeader << "Missing input arguments. using defaults, Should be 6.\n" ;
		screen.SCREEN_WIDTH = SCRN_WIDTH_DEFAULT;
		screen.SCREEN_HEIGHT = SCRN_HEIGHT_DEFAULT;	
	}else
	{
		screen.SCREEN_WIDTH = std::stoi(argv[1]) ;
		screen.SCREEN_HEIGHT = std::stoi(argv[2]);
		numberOfParticles = std::stoi(argv[3]);
		rgbColorBits = std::stoi(argv[4]);
		loopCount = std::stoi(argv[5]);
		std::cout << myStringHeader <<  "Width Resolution = " <<  screen.SCREEN_WIDTH << '\n';
		std::cout << myStringHeader<<   "Height Resolution = "  <<  screen.SCREEN_HEIGHT << '\n';
		std::cout << myStringHeader<<   "No of Particles in Swarm = "  <<  numberOfParticles << '\n';
		if (rgbColorBits < 0 || rgbColorBits >6)
		{
			std::cout << myStringHeader << "Warning incorrect RGB value, default used.'\n'";
		}else{
			std::cout << myStringHeader<< "RGB colour bits = " << rgbColorBits << std::endl;
		}
		std::cout << myStringHeader <<  "Number of iterations  = " <<  loopCount << '\n';
	}

	if(screen.init() == false) {
		std::cout << myStringHeader << "Error initialising SDL." << std::endl;
	}

	//define swarm object with Swarm class
	Swarm swarm(numberOfParticles);
	while (loopCount-- > 0) {
			//Returns an unsigned 32-bit value representing the number of milliseconds since the SDL library initialized.
		int elapsed = SDL_GetTicks();

		 // Update particles
		swarm.update(elapsed);

		// Draw particles
		//assign RGB colours * elapsed to slow it down send to sin function
		unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);
		switch (rgbColorBits) //rgb d7 b111  = all on , d1 b001 blue on 
		{
			case 1: red = 0, green = 0; break;
			case 2: red = 0, blue = 0; break;
			case 3: red = 0; break;
			case 4: green = 0, blue = 0; break;
			case 5: green = 0; break;
			case 6: blue = 0; break ;
			default: break;
		}
		const Particle * const pParticles = swarm.getParticles();

		for (int i = 0; i < swarm.NPARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * screen.SCREEN_WIDTH / 2;
			int y = particle.m_y * screen.SCREEN_WIDTH / 2 + screen.SCREEN_HEIGHT/2;
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
		
		//std::cout << '\r' <<loopCount << std::flush;
	}

	screen.close();
	std::cout << myStringHeader << "Finished." << std::endl;
	return 0;
}
