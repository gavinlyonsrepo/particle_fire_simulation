/*
 * Screen.h
 *
 *  Created on: 1 Sep 2014
 *      Author: johnwpurcell
 */

#ifndef SCREEN_H
#define SCREEN_H

#include <SDL2/SDL.h>

namespace caveofprogramming {

class Screen {
public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;

private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer;
	Uint32 *m_buffer1;
	Uint32 *m_buffer2;

public:
	Screen();
	bool init();
    void update();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	bool processEvents();
	void close();
    void clear();
    void boxBlur();
};

} /* namespace caveofprogramming */

#endif /* SCREEN_H_ */
