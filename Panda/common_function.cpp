

#include "common_function.h"

void logSDLError(std::ostream& os, const std::string &msg, bool fatal)
{
	os << msg << " Error: " << SDL_GetError() << std::endl;
	if (fatal) {
		SDL_Quit();
		exit(1);
	}
}

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		logSDLError(std::cout, "SDL_Init", true);

	window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren)
{
	SDL_Texture *texture = nullptr;

	SDL_Surface *loadedImage = IMG_Load(file.c_str());

	// Xóa màu của nền
	if (loadedImage != NULL)
	{
		Uint32 color_key = SDL_MapRGB(loadedImage->format, 230, 254, 240);
		SDL_SetColorKey(loadedImage, SDL_TRUE, color_key);
	}


	if (loadedImage != nullptr) {
		texture = SDL_CreateTextureFromSurface(ren, loadedImage);
		SDL_FreeSurface(loadedImage);

		if (texture == nullptr) {
			logSDLError(std::cout, "CreateTextureFromSurface", true);
		}
	}
	else {
		logSDLError(std::cout, "LoadBMP", true);
	}

	return texture;
}

void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h)
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;

	SDL_RenderCopy(ren, tex, NULL, &dst);
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int randomBamboo() {
	int x = rand() % 6;
	return x;
}

