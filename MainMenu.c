#include "header.h"

bool quitMainMenu = false;
SDL_Surface* menu_image = NULL;
SDL_Texture* menu_texture = NULL;

bool loadMainMenu(){
    bool success = true;

    menu_image = IMG_Load(MENU_IMAGE);
    if(menu_image == NULL){
        printf( "Unable to load image %s! IMG Error: %s\n", MENU_IMAGE, IMG_GetError() );
        success = false;
        return success;
    }
    menu_texture = SDL_CreateTextureFromSurface(renderer, menu_image);
    SDL_FreeSurface(menu_image);
    menu_image = NULL;

	SinglePlayRectSauce.x = 25;
	SinglePlayRectSauce.y = 458;
	SinglePlayRectSauce.w = 224;
	SinglePlayRectSauce.h = 28;

	SinglePlayRectDest.x = SCREEN_WIDTH/2 - SinglePlayRectSauce.w/2;
	SinglePlayRectDest.y = SCREEN_HEIGHT/2 - SinglePlayRectSauce.h *2;
	SinglePlayRectDest.w = 224;
	SinglePlayRectDest.h = 28;


    OptionRectSauce.x = 25;
    OptionRectSauce.y = 563;
    OptionRectSauce.w = 224;
    OptionRectSauce.h = 28;

    OptionRectDest.x = SCREEN_WIDTH/2 - OptionRectSauce.w/2;
    OptionRectDest.y = SCREEN_HEIGHT/2 - OptionRectSauce.h/2;
    OptionRectDest.w = 224;
    OptionRectDest.h = 28;


    ExitRectSauce.x = 307;
    ExitRectSauce.y = 781;
    ExitRectSauce.w = 128;
    ExitRectSauce.h = 28;

    ExitRectDest.x = SCREEN_WIDTH/2 - ExitRectSauce.w/2;
    ExitRectDest.y = SCREEN_HEIGHT/2 + ExitRectSauce.h;
    ExitRectDest.w = 128;
    ExitRectDest.h = 28;


    return success;
}

void closeMainMenu(){
	SDL_FreeSurface(menu_image);
    menu_image = NULL;

    SDL_DestroyTexture(menu_texture);
    menu_texture = NULL;


    //SDL_FillRect(gScreenSurface, NULL, 0x000000);
}

int OpenMainMenu(){
	quitMainMenu = false;
	int exitStatus = 0;

	SDL_SetWindowTitle(gWindow, "Main Menu");

    if(!loadMainMenu()){
		quitMainMenu = true;
        exitStatus = -1;
    }


    while(!quitMainMenu){
        while( SDL_PollEvent(&e) != 0 ){

            if( e.type == SDL_QUIT ){
                quitMainMenu = true;
            }

            else if(e.type == SDL_KEYDOWN){
                printf("key pressed: %s \n", SDL_GetKeyName(e.key.keysym.sym) );
                if(e.key.keysym.sym == SDLK_ESCAPE){
                    quitMainMenu = true;
                }
            }
            else if(e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT){
                SDL_Point mousepos = {e.button.x, e.button.y};
                //printf( "het is een mouseup event met linkermuisknop!\n" );
                //printf( "X: %i\n Y: %i\n", mousepos.x, mousepos.y );
                if(isPointInsideRect(mousepos, SinglePlayRectDest)){
					exitStatus = 1;
					quitMainMenu = true;
                }
                else if(isPointInsideRect(mousepos, OptionRectDest)){
                    printf( "het is binnen de options rectangle!" );
                }
                else if(isPointInsideRect(mousepos, ExitRectDest)){

                    quitMainMenu = true;
                }
            }

        }
		/*
		SDL_BlitSurface(menu_image, &SinglePlayRectSauce, gScreenSurface, &SinglePlayRectDest);
		SDL_BlitSurface(menu_image, &OptionRectSauce, gScreenSurface, &OptionRectDest);
		SDL_BlitSurface(menu_image, &ExitRectSauce, gScreenSurface, &ExitRectDest);

        SDL_UpdateWindowSurface( gWindow );
        */

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, menu_texture, &SinglePlayRectSauce, &SinglePlayRectDest);
		SDL_RenderCopy(renderer, menu_texture, &OptionRectSauce, &OptionRectDest);
		SDL_RenderCopy(renderer, menu_texture, &ExitRectSauce, &ExitRectDest);

		SDL_RenderPresent(renderer);


    }

	closeMainMenu();
    return exitStatus;
}


