/*
 *  @file Screen.h @ particle_fire_simulation project pfsim
 *  @brief library header file
 */

#ifndef SCREEN_H
#define SCREEN_H

#include <SDL2/SDL.h>

namespace pfsns {

class Screen {
public:
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;

private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer;
	Uint32 *m_buffer1;
	Uint32 *m_buffer2;

public:
	//methods
	Screen();
	bool init();
	void update();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	bool processEvents();
	void close();
	void clear();
	void boxBlur();

};

} /* namespace pfsns */

#endif /* SCREEN_H_ */
