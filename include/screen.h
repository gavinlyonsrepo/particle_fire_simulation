/*
 * Screen.h
 *
 *  Created on: 1 March 2017
 *      Author: Gavin Lyons
 */

#ifndef SCREEN_H
#define SCREEN_H

#include <SDL.h>
namespace caveofprogramming {

class screen {
public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;

private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer;

public:
	screen();
	bool init();
	bool processEvents();
	void close();
};

} /* namespace caveofprogramming */

#endif // SCREEN_H
