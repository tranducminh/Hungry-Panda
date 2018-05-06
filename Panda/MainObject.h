#pragma once

#include "common_function.h"
#include "BaseObject.h"

#define WIDTH_MAIN_OBJECT 66
#define HEIGHT_MAIN_OBJECT 82
class MainObject : public BaseObject
{
public:
	MainObject();
	~MainObject();
	void HandleInputAction(SDL_Event event, SDL_Renderer *ren);
	void HandMove();


private:
	int x_val_;
	int y_val_;
};
