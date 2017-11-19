/*
 *  Name: Screen.cpp @ particle_fire_simulation project pfsim
 *  Description: library source file to control screen graphic
 *  Created on: 05-05-17
 *  Author: Gavin Lyons
 */

#include "Screen.h"

namespace pfsns {
// constructor for Screen class
Screen::Screen() :
		m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL) {

}

bool Screen::init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}

	m_window = SDL_CreateWindow("Particle Fire Explosion",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
			SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (m_window == NULL) {
		SDL_Quit();
		return false;
	}
    //set the renderer and texture
    //Use this function to create a 2D rendering context for a window.
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	//Use this function SDL_CreateTexture to create a texture for a rendering context.
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (m_renderer == NULL) {
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	if (m_texture == NULL) {
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}


	m_buffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
	m_buffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

    //clear the buffers
	memset(m_buffer1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
	memset(m_buffer2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

	return true;
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
	if(x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
		return;
	}
    //unsigned int 4 bytes 0xXXXXXXXX colour set
	Uint32 color = 0;
    //left bitshifting to get colour value eg 0xrrggbbAA Red Green Blue Alpha
	color <<= 8;
	color += green;
	color <<= 8;
	color += blue;
	color <<= 8;
	color += 0xFF;
    // putting x y cord into buffer set equal to colour
	m_buffer1[(y * SCREEN_WIDTH) + x] = color;
}

void Screen::boxBlur() {
	// Swap the buffers, so pixel is in m_buffer2 and we are drawing to m_buffer1.
	Uint32 *temp = m_buffer1;
	m_buffer1 = m_buffer2;
	m_buffer2 = temp;

    //loop to iterate over all pixels
	for(int y=0; y<SCREEN_HEIGHT; y++) {
		for(int x=0; x<SCREEN_WIDTH; x++) {

			int redTotal=0;
			int greenTotal=0;
			int blueTotal=0;

			for(int row=-1; row<=1; row++) {
				for(int col=-1; col<=1; col++) {
					int currentX = x + col;
					int currentY = y + row;

					if(currentX >= 0 && currentX < SCREEN_WIDTH && currentY >= 0 && currentY < SCREEN_HEIGHT) {
						Uint32 color = m_buffer2[currentY*SCREEN_WIDTH + currentX];

						Uint8 red = color >> 24;
						Uint8 green = color >> 16;
						Uint8 blue = color >> 8;

						redTotal += red;
						greenTotal += green;
						blueTotal += blue;
					}
				}
			}

			Uint8 red = redTotal/9;
			Uint8 green = greenTotal/9;
			Uint8 blue = blueTotal/9;

			setPixel(x, y, red, green, blue);
		}
	}
}

void Screen::update() {
    //Use this function to update the given texture rectangle with new pixel data.
    SDL_UpdateTexture(m_texture, NULL, m_buffer1, SCREEN_WIDTH * sizeof(Uint32));
	//Use this function to clear the current rendering target with the drawing color.
	SDL_RenderClear(m_renderer);
    //Use this function to copy a portion of the texture to the current rendering target.
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	//Use this function to update the screen with any rendering performed since the previous call.
	SDL_RenderPresent(m_renderer);

}

bool Screen::processEvents() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			return false;
		}
	}
	return true;
}

void Screen::clear() {
	memset(m_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
}


void Screen::close() {
    delete[] m_buffer1;
	delete[] m_buffer2;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyTexture(m_texture);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

} /* namespace pfsns */
