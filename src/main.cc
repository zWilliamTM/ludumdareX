#include <SDL.h>
#include <iostream>
#include <tuple>
#include <unordered_map>

#include "screen.h"
#include "keyboard.h"

#include "state_mgr.h"

constexpr int sw = 300;
constexpr int sh = 168;
constexpr int scale = 3;
constexpr unsigned screen_buffer_size = sw * sh;

int main()
{
	using namespace graphics;
	using namespace input;
	using namespace state;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		std::cout << SDL_GetError() << std::endl;
	IMG_Init(IMG_INIT_PNG);

	SDL_Window *w = 
		SDL_CreateWindow("Ld",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			sw * scale, sh * scale,
			SDL_WINDOW_SHOWN);
	if (!w)
		std::cout << SDL_GetError() << std::endl;

	SDL_Renderer *render =
		SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED);

	// buffer
	SDL_Texture *tex =
		SDL_CreateTexture(render, 
			SDL_PIXELFORMAT_RGB888,
			SDL_TEXTUREACCESS_STREAMING, sw, sh);

	Screen s(sw, sh);
	Keyboard kb;
	StateManager sm(StateID::TESTING);

	bool run = true;
	auto [_x,_y] = std::tuple(0,0);
	for (SDL_Event e; run; SDL_RenderPresent(render))
	{
		for ( ; SDL_PollEvent(&e); )
		{
			switch (e.type)
			{
				case SDL_QUIT: 		run = false; 						break;
				case SDL_KEYDOWN: 	kb.keyPressed(e.key.keysym.sym); 	break;
				case SDL_KEYUP: 	kb.keyReleased(e.key.keysym.sym); 	break;
			}
		}

		// update
		kb.update();

		// handle events
		sm.handleEvent(&kb);
		
		// update
		sm.update(0.f);

		// screen
		s.clear();
		sm.render(&s);

		SDL_UpdateTexture(tex, nullptr, s.pixels, sw << 2);
		SDL_RenderClear(render);
		SDL_RenderCopy(render, tex, nullptr, nullptr);
		SDL_Delay(20);
	}

	SDL_DestroyWindow(w);
	SDL_Quit();

	return 0;
}
