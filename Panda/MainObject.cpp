
#include "MainObject.h"


MainObject::MainObject() {
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = WIDTH_MAIN_OBJECT;
	rect_.h = HEIGHT_MAIN_OBJECT;
	x_val_ = 0;
	y_val_ = 0;
}

MainObject::~MainObject() {

}

void MainObject::HandleInputAction(SDL_Event event, SDL_Renderer *ren) {
	std::cout << x_val_ << " " << y_val_ << std::endl;
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym)
		{
		case SDLK_w:
			y_val_ -= HEIGHT_MAIN_OBJECT / 6;
			break;
		case SDLK_s:
			y_val_ += HEIGHT_MAIN_OBJECT / 6;
			break;
		case SDLK_a:
			x_val_ -= WIDTH_MAIN_OBJECT / 4;
			break;
		case SDLK_d:
			x_val_ += WIDTH_MAIN_OBJECT / 4;
			break;
		default:
			break;
		}
	}
	else if (event.type == SDL_KEYUP) {
		switch (event.key.keysym.sym)
		{
		case SDLK_w:
			y_val_ = 0;
			break;
		case SDLK_s:
			y_val_ = 0;
			break;
		case SDLK_a:
			x_val_ = 0;
			break;
		case SDLK_d:
			x_val_ = 0;
			break;
		default:
			break;
		}
	}
	else if (event.type == SDL_MOUSEBUTTONDOWN) {
		std::cout << event.motion.x << " " << event.motion.y << std::endl;
	}
	else if (event.type == SDL_MOUSEBUTTONUP) {

	}
	else {

	}
}

void MainObject::HandMove() {
	rect_.x += x_val_;
	if (rect_.x < 0) {
		rect_.x = 0;
	}
	else if (rect_.x + WIDTH_MAIN_OBJECT > SCREEN_WIDTH) {
		rect_.x = SCREEN_WIDTH - WIDTH_MAIN_OBJECT;
	}
	//		x_val_ = 0;

	rect_.y += y_val_;
	if (rect_.y < 0) {
		rect_.y = 0;
		//		y_val_ = 0;
	}
	else if (rect_.y + HEIGHT_MAIN_OBJECT > SCREEN_HEIGHT) {
		rect_.y = SCREEN_HEIGHT - HEIGHT_MAIN_OBJECT;
	}
}