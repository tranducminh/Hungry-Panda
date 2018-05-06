#include "common_function.h"
#include "ThreatObject.h"
#include "MainObject.h"

int main(int arc, char* argv[]) {

	//Creat background
	initSDL(window, renderer);
	background = loadTexture("bg2.bmp", renderer);
	SDL_RenderClear(renderer);
	renderTexture(background, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	
	//Make Main Object
	MainObject panda;
	panda.LoadImg("panda/1.png", renderer);
	panda.render(renderer);
	
	//Make Threat Objects
	ThreatObject snail[NUM_THREATS];
	for (int  i = 0; i < NUM_THREATS; i++)
	{
		
		snail[i].LoadImg("1.gif", renderer);
		snail[i].Set_y_val(2);
	}
	
	SDL_RenderPresent(renderer);
	
	bool isRun = true;
	while (isRun) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				isRun = false;
				break;
			}
			else
				panda.HandleInputAction(event, renderer);
			
		}
		panda.render(renderer);
		panda.HandMove();
		SDL_RenderPresent(renderer);

		renderTexture(background, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
		

		//Threats 	
		for (int i = 0; i < NUM_THREATS; i++)
		{
			snail[i].HandMove(SCREEN_WIDTH, SCREEN_HEIGHT);
			
			if (snail[i].GetRect_y() <= 0) {
				snail[i].SetRect(Bamboo_Loc[randomBamboo()], SCREEN_HEIGHT + i*100);
			}
			snail[i].render(renderer);
		}
		
	}


	
	return 0;
}