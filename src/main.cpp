//A simple example of how to use SDL in C++
//By Mattias Lasersköld

#include <iostream>
#include <SDL2/SDL.h>
#include <memory>

using namespace std;

int main(int argc, char **argv) {
	bool quit = false;
	SDL_Event event;

	SDL_Init(SDL_INIT_VIDEO);


	std::shared_ptr<SDL_Window> window(
		SDL_CreateWindow(
				"Hello",
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				800, 600, 0),
		SDL_DestroyWindow);

	shared_ptr<SDL_Renderer> renderer(
		SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_ACCELERATED),
		SDL_DestroyRenderer
	);

	shared_ptr<SDL_Surface> surface(
		SDL_LoadBMP("image.bmp"),
		SDL_FreeSurface
	);

	shared_ptr<SDL_Texture> texture(
		SDL_CreateTextureFromSurface(
			renderer.get(), surface.get()),
		SDL_DestroyTexture
	);

	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;

	SDL_Rect dst = {0,0,800,600};

	SDL_QueryTexture(texture.get(), nullptr, nullptr, &rect.w, &rect.h);


	while (!quit) {
		SDL_WaitEvent(&event);

		switch(event.type) {
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym) {
			case SDLK_ESCAPE:
				quit=true;
				break;
			}
			break;
		}

		SDL_RenderCopy(renderer.get(), texture.get(), &rect, &dst); //the rects is not required
		SDL_RenderPresent(renderer.get());
	}


	SDL_Quit();
	return 0;
}
