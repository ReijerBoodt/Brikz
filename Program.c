#include "header.h"


//Screen dimension constants
const int SCREEN_WIDTH = 1920/1.5;
const int SCREEN_HEIGHT = 1080/1.5;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

SDL_Renderer* renderer = NULL;


bool quit = false;

bool init(){
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;
		return success;
	}

    //Create window
    gWindow = SDL_CreateWindow( "Brikz", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                               SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( gWindow == NULL )
    {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        success = false;
        return success;
    }

    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        success = false;
        return success;
    }

    if (TTF_Init() != 0){
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
		success = false;
		return success;
	}


    //Create a renderer
    renderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL){
		printf( "Could not create a renderer! Error: %s\n", SDL_GetError() );
        success = false;
        return success;
    }


    //Get window surface
    gScreenSurface = SDL_GetWindowSurface( gWindow );



	return success;
}


bool isPointInsideRect(SDL_Point point, SDL_Rect rect){
    //printf( "X: %d\n Y: %d\n W: %d \n H: %d\n", rect.x, rect.y, rect.w, rect.h );

    if(point.x >= rect.x &&
       point.x <= rect.x+rect.w &&
       point.y >= rect.y &&
       point.y <= rect.y+rect.h)
    {
        return true;
    }
    else{
        return false;
    }
}

void close()
{
    SDL_FreeSurface(gScreenSurface);
    gScreenSurface = NULL;

    SDL_DestroyRenderer( renderer );
    renderer = NULL;

	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	IMG_Quit();

	TTF_Quit();

	SDL_Quit();
}

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
		close();
		return 1;
	}


	while(!quit){
		//StartPongGame();
		switch( OpenMainMenu() ){
			case -1:
				printf( "Failed to load menu!\n" );
				close();
				return 1;
				break;
			case 0:
				quit = true;
				break;
			case 1:
				startBreakoutGame();
				break;
			case 2:

				break;
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}
