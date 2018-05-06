#pragma once

#include <SDL.h>
#include <string>
#include <iostream>
#include <SDL_image.h>
#include <ctime>
#include <sstream>


static std::string WINDOW_TITLE = "Panda";
static const int SCREEN_WIDTH = 1200;
static const int SCREEN_HEIGHT = 600;
static const int NUM_THREATS = 6;
static int Bamboo_Loc[6] = {250, 300, 450, 500, 650, 700};

static SDL_Window *window;
static SDL_Renderer *renderer;
static SDL_Texture *background;
static SDL_Event event;


void logSDLError(std::ostream& os, const std::string &msg, bool fatal);
SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren);
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
int randomBamboo();
