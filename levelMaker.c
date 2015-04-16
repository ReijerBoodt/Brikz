#include "header.h"
#include "levelMaker.h"

/*SDL_Surface* breakout_image = NULL;
SDL_Texture* breakout_texture = NULL;
const Uint8* KeyBoardState = NULL;
TTF_Font* font = NULL;
bool debugging = true;
Brick *bricks = NULL;
*/

bool quitLevelMaker = false;
bool *previouslyChanged = NULL;

bool loadLevelMaker(){
	bool success = true;
	srand(time(NULL));

	KeyBoardState = SDL_GetKeyboardState(NULL);

	breakout_image = IMG_Load(BRIKZ_IMAGE);
    if(breakout_image == NULL){
        printf( "Unable to load image %s! IMG Error: %s\n", BRIKZ_IMAGE, IMG_GetError() );
        success = false;
        return success;
    }
    breakout_texture = SDL_CreateTextureFromSurface(renderer, breakout_image);
	SDL_FreeSurface(breakout_image);
	breakout_image = NULL;

	font = TTF_OpenFont(DEBUG_FONT, 16);
	if (font == NULL){
		printf( "Unable to load font! SDL_ttf Error: %s\n", TTF_GetError() );
		success = false;
        return success;
	}

	bricks = (Brick*) calloc(1, sizeof(Brick));

    BrickLevel1RectSauce = (SDL_Rect){0,20,70,20};
    BrickLevel2RectSauce = (SDL_Rect){71,20,70,20};

	return success;
}

void levelMakerUpdateLogic(){
    SDL_PumpEvents();
	bool ctrlDown = false;
	bool sDown = false;
    while( SDL_PollEvent(&e) ){
        if( e.type == SDL_QUIT ){
            quit = true;
            quitLevelMaker = true;
        }

        else if(e.type == SDL_KEYDOWN){
            printf("key pressed: %s \n", SDL_GetKeyName(e.key.keysym.sym) );
            if(e.key.keysym.sym == SDLK_ESCAPE){
                quitLevelMaker = true;
                continue;
            }

            else if( KeyBoardState[SDL_SCANCODE_LCTRL] && KeyBoardState[SDL_SCANCODE_S] ){
				if( e.key.keysym.sym == SDLK_0 ){
                    saveLevel(0);
				}
				else if( e.key.keysym.sym == SDLK_1 ){
					saveLevel(1);
				}
				else if( e.key.keysym.sym == SDLK_2 ){
					saveLevel(2);
				}
				else if( e.key.keysym.sym == SDLK_3 ){
					saveLevel(3);
				}
				else if( e.key.keysym.sym == SDLK_4 ){
					saveLevel(4);
				}

            }
            else if( KeyBoardState[SDL_SCANCODE_LCTRL] && KeyBoardState[SDL_SCANCODE_O] ){
				if( e.key.keysym.sym == SDLK_0 ){
					loadLevel(0);
				}
				else if( e.key.keysym.sym == SDLK_1 ){
					loadLevel(1);
				}
				else if( e.key.keysym.sym == SDLK_2 ){
					loadLevel(2);
				}
				else if( e.key.keysym.sym == SDLK_3 ){
					loadLevel(3);
				}
				else if( e.key.keysym.sym == SDLK_4 ){
					loadLevel(4);
				}
            }

        }
        else if(e.button.button == SDL_BUTTON_LEFT || e.button.button == SDL_BUTTON_RIGHT){
            if(e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONUP){
                break;
            }

            //printf("er is geklikt...\n");
            SDL_Point mousepos = {e.button.x, e.button.y};

            for(int i=0;i<bricksInLevel;i++){
                //printf("checked a brick\n");
                SDL_Rect temprect = {bricks[i].x, bricks[i].y, BRICK_WIDTH, BRICK_HEIGHT};
                if(SDL_EnclosePoints(&mousepos, 1, &temprect, NULL) && !previouslyChanged[i] ){
                    if( e.button.button == SDL_BUTTON_LEFT && bricks[i].damage>0 ){
                        bricks[i].damage--;
                        previouslyChanged[i]=true;
                    }
                    if( e.button.button == SDL_BUTTON_RIGHT && bricks[i].damage<2 ){
                        bricks[i].damage++;
                        previouslyChanged[i]=true;
                    }
                }
            }
        }
    }
}

void closeLevelMaker(){
	SDL_FreeSurface(breakout_image);
	breakout_image = NULL;

	SDL_DestroyTexture(breakout_texture);
	breakout_texture = NULL;

	free(bricks);
	bricks = NULL;

	free(previouslyChanged);
	previouslyChanged = NULL;

	TTF_CloseFont(font);
	font = NULL;

	KeyBoardState = NULL;

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

void levelMakerRenderBricks(){
	for(int i=0; i<bricksInLevel; i++){
		if(bricks[i].damage==0){continue;}
		SDL_Rect temprect = {bricks[i].x, bricks[i].y, BRICK_WIDTH, BRICK_HEIGHT};

		if(bricks[i].damage==1){
            SDL_RenderCopy(renderer, breakout_texture, &BrickLevel1RectSauce, &temprect);
		}
		if(bricks[i].damage==2){
            SDL_RenderCopy(renderer, breakout_texture, &BrickLevel2RectSauce, &temprect);
		}

		//SDL_RenderCopyEx(renderer, breakout_texture, &BrickLevel1RectSauce, &temprect, 45, NULL, SDL_FLIP_NONE);
	}
}

void levelMakerDoRendering(){
	//Used Gray:
	//RGB(50,50,50)
	//Hex(323232)
	//Int(3289650)

	SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
	SDL_RenderClear(renderer);

	levelMakerRenderBricks();

	if(debugging){
		SDL_Surface* textSurface = NULL;
		SDL_Texture* textTexture = NULL;
		char textToRender[80];

		sprintf(textToRender, "Framerate: %f fps", framerate);

		textSurface = TTF_RenderText_Solid(font, textToRender, (SDL_Color){50,50,255} );

		textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
		SDL_RenderCopy(renderer, textTexture, NULL, &((SDL_Rect){10,10,textSurface->w,textSurface->h}) );

		SDL_DestroyTexture(textTexture);
		textTexture = NULL;
		SDL_FreeSurface(textSurface);
		textSurface = NULL;

		sprintf(textToRender, "Tickrate: %f",tickrate);

		textSurface = TTF_RenderText_Solid(font, textToRender, (SDL_Color){255,255,255} );

		textTexture = NULL;
		textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
		SDL_RenderCopy(renderer, textTexture, NULL, &((SDL_Rect){10,50,textSurface->w,textSurface->h}) );

		SDL_DestroyTexture(textTexture);
		textTexture = NULL;
		SDL_FreeSurface(textSurface);
		textSurface = NULL;
	}

	SDL_RenderPresent(renderer);

}


int startLevelMaker(){

	quitLevelMaker = false;
	int exitStatus = 0;

	Uint32 previousTick;
	Uint32 tickBeforeThat;

	bool update = true;

	Uint32 previousFrame;
	Uint32 frameBeforeThat;

	bool render = true;

	Uint32 previousClear;
	Uint32 clearBeforeThat;

	SDL_SetWindowTitle(gWindow, "Brikz Levelmaker");

	if( !loadLevelMaker() ){
		quitLevelMaker = true;
		exitStatus = -1;
	}
	loadLevelGeneric();
	previouslyChanged = (bool*) calloc(bricksInLevel, sizeof(bool));

	previousTick = SDL_GetTicks();
	previousFrame = previousTick;
	previousClear = previousTick;
	while(!quitLevelMaker){

		if( SDL_GetTicks()-previousTick < 10 ){
			update = false;
		}
		if( SDL_GetTicks()-previousFrame < 10 ){
			render = false;
		}
		if( SDL_GetTicks()-previousClear > 200 ){
            free(previouslyChanged);
            previouslyChanged = NULL;
            previouslyChanged = (bool*) calloc(bricksInLevel, sizeof(bool));
		}

		if(update){
			tickBeforeThat = previousTick;
			previousTick = SDL_GetTicks();
			tickrate = 1000.0/(previousTick - tickBeforeThat);
			if(tickrate != 100.0){
					printf("%f Ticks per Second\n", tickrate );
			}
			levelMakerUpdateLogic();
		}

		if(render){
			frameBeforeThat = previousFrame;
			previousFrame = SDL_GetTicks();
			framerate = 1000.0/(previousFrame - frameBeforeThat);
			if(framerate != 100.0){
				printf("%f Frames per Second\n", framerate );
			}
			levelMakerDoRendering();
		}

		if(update){


			/*if( KeyBoardState[SDL_SCANCODE_RIGHT] ){ movePaddle(true); }
			if( KeyBoardState[SDL_SCANCODE_LEFT] ){ movePaddle(false); }
			if( KeyBoardState[SDL_SCANCODE_UP] ){ paddleDest.y=paddleDest.y-PADDLE_STEP; }
			if( KeyBoardState[SDL_SCANCODE_DOWN] ){ paddleDest.y=paddleDest.y+PADDLE_STEP; }
			if( KeyBoardState[SDL_SCANCODE_RSHIFT] ){ paddleRotation+=5; }
			if( KeyBoardState[SDL_SCANCODE_LSHIFT] ){ paddleRotation-=5; }*/
		}

		render=true;
		update=true;


	}

	closeLevelMaker();
	return exitStatus;
}

