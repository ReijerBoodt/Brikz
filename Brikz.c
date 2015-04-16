#include "header.h"
#include "Brikz.h"

bool quitBreakoutGame = false;
bool waiting = false;
int waitTicks = 0;
int waitedTicks = 0;
float speedAmplifier = 0.20;
int paddleRotation = 0;
SDL_Surface* breakout_image = NULL;
SDL_Texture* breakout_texture = NULL;

const Uint8* KeyBoardState = NULL;

TTF_Font* font = NULL;

int ScoreA = 0;

bool motionBlur = false;
bool debugging = true;

struct Ball{
	float x;
	float y;
	float XSpeed;
	float YSpeed;
}ball;

//Brick bricks[8];
Brick *bricks = NULL;


bool loadBreakoutGame(){
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


	BreakoutPaddleRectSauce.x = 0;
    BreakoutPaddleRectSauce.y = 0;
    BreakoutPaddleRectSauce.w = 150;
    BreakoutPaddleRectSauce.h = 20;

    BreakoutPaddleRectSauce = (SDL_Rect) {0,0,150,20};

    BreakoutBallRectSauce.x = 380;
    BreakoutBallRectSauce.y = 20;
    BreakoutBallRectSauce.w = 20;
    BreakoutBallRectSauce.h = 20;

    BrickLevel1RectSauce.x = 0;
    BrickLevel1RectSauce.y = 20;
    BrickLevel1RectSauce.w = 70;
    BrickLevel1RectSauce.h = 20;

    BrickLevel1RectSauce = (SDL_Rect){0,20,70,20};

    BrickLevel2RectSauce = (SDL_Rect){71,20,70,20};

	paddleDest.y = SCREEN_HEIGHT-40;
    paddleDest.w = 150;
    paddleDest.h = 20;

	BreakoutBall1RectDest.w = BALL_WIDTH;
	BreakoutBall1RectDest.h = BALL_HEIGHT;

	return success;
}

void closeBreakoutGame(){
	SDL_FreeSurface(breakout_image);
	breakout_image = NULL;

	SDL_DestroyTexture(breakout_texture);
	breakout_texture = NULL;

	free(bricks);
	bricks = NULL;

	TTF_CloseFont(font);
	font = NULL;

	KeyBoardState = NULL;

	waiting = false;
	waitTicks = 0;
	waitedTicks = 0;

	speedAmplifier = 0.20;

	paddleRotation = 0;

	ScoreA = 0;

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

void movePaddle(bool right){
	if(!right){
		if(paddleDest.x <= 0){
			if(paddleDest.x < 0){
				paddleDest.x = 0;
			}
			return;
		}
		paddleDest.x = paddleDest.x - PADDLE_STEP;
		//paddleDest.y = paddleDest.y - PADDLE_STEP;
		//paddleRotation -= PADDLE_STEP;
	}
	else{
		if(paddleDest.x+paddleDest.w >= SCREEN_WIDTH){
			if(paddleDest.x+paddleDest.w > SCREEN_WIDTH){
				paddleDest.x = SCREEN_WIDTH-paddleDest.w;
			}
			return;
		}
		paddleDest.x = paddleDest.x + PADDLE_STEP;
		//paddleDest.y = paddleDest.y + PADDLE_STEP;
		//paddleRotation += PADDLE_STEP;
	}
}


void startNewRound(){

	speedAmplifier = 0.20;
	int randInt = rand();
	float randFloat = (float)rand()/(float)(RAND_MAX/10) + 11;
	//ball.XSpeed = (rand()%20 + 1);
	//ball.YSpeed = BALL_INITIAL_SPEED_Y*speedAmplifier;
	ball.YSpeed = -sqrtf(-( randFloat*randFloat )+BALL_SPEED_CONSTANT);
    if(rand()%20+1 < 11){
		ball.XSpeed = -randFloat;
    }
    else{
		ball.XSpeed = randFloat;
    }

	//Reset speed amplifier


	//Reset paddle position
    paddleDest.x = SCREEN_WIDTH/2 - paddleDest.w/2;

    //Reset ball position
	ball.x = paddleDest.x + paddleDest.w/2 - BALL_WIDTH/2;
	ball.y = paddleDest.y-BALL_HEIGHT-1;

	BreakoutBall1RectDest.x = ball.x;
	BreakoutBall1RectDest.y = ball.y;

	BreakoutBall2RectDest = BreakoutBall1RectDest;

	loadLevel(1);

	//bricksLeft = sizeof(*bricks)/sizeof(Brick);
	printf("%i bricks left \n", bricksLeft);

	wait(40);

}

void updateLogic(){
	//printf("got into updateLogic");
	if(waiting && waitedTicks < waitTicks){
		waitedTicks++;
		//printf( "%i\n", waitedTicks );
		return;
	}
	else if(waiting){
		waiting = false;
		waitedTicks = 0;
		waitTicks = 0;
	}

	if(ball.y+BALL_HEIGHT >= paddleDest.y){
		if(SDL_HasIntersection(&paddleDest, &BreakoutBall1RectDest)){
			//Ball hits Paddle.

			ball.YSpeed = 0 - SDL_abs(ball.YSpeed);

			if(BreakoutBall1RectDest.x >= paddleDest.x+paddleDest.w-40){
				int Movement = ball.XSpeed*ball.XSpeed + ball.YSpeed*ball.YSpeed;
				ball.XSpeed += 3;
				while(-(ball.XSpeed*ball.XSpeed)+Movement < 0){
					ball.XSpeed -=0.1;
				}
				ball.YSpeed = -sqrtf( -(ball.XSpeed*ball.XSpeed)+Movement );
			}
			if(BreakoutBall1RectDest.x+BALL_WIDTH <= paddleDest.x+40){
				int Movement = ball.XSpeed*ball.XSpeed + ball.YSpeed*ball.YSpeed;
				ball.XSpeed -= 3;
				while(-(ball.XSpeed*ball.XSpeed)+Movement < 0){
					ball.XSpeed +=0.1;
				}
				ball.YSpeed = -sqrtf( -(ball.XSpeed*ball.XSpeed)+Movement );
			}
		}
		else if(ball.y >= paddleDest.y){
			//Ball goes 'out of bounds'.
			startNewRound();
			return;
		}
	}

	updateBrickLogic();

	if(ball.x <= 0 || ball.x+BALL_WIDTH >= SCREEN_WIDTH){
		ball.XSpeed = 0 - ball.XSpeed;
	}
	else if(ball.y <= 0){
		ball.YSpeed = 0 + SDL_abs(ball.YSpeed);
	}

	ball.x += ball.XSpeed*speedAmplifier;
	ball.y += ball.YSpeed*speedAmplifier;

	BreakoutBall2RectDest = BreakoutBall1RectDest;

	BreakoutBall1RectDest.x = ball.x;
	BreakoutBall1RectDest.y = ball.y;

}

void updateBrickLogic(){
	//printf("got into updateBrickLogic  ");
	for(int i=0; i<bricksInLevel; i++){
		if(bricks[i].damage==0){continue;}
		bool hit = false;

		SDL_Rect belowRect = {bricks[i].x, bricks[i].y+BRICK_HEIGHT, BRICK_WIDTH, 1};
		SDL_Rect aboveRect = {bricks[i].x, bricks[i].y, BRICK_WIDTH, 1};
		SDL_Rect rightRect = {bricks[i].x+BRICK_WIDTH-1, bricks[i].y, 1, BRICK_HEIGHT};
		SDL_Rect leftRect = {bricks[i].x, bricks[i].y, 1, BRICK_HEIGHT};

		SDL_Rect intersectionRect;

		if(SDL_IntersectRect(&BreakoutBall1RectDest, &rightRect, &intersectionRect)){
			printf("ball is right of brick \n");
			ball.XSpeed = 0+fabs(ball.XSpeed);
			hit = true;
		}
		else if(SDL_IntersectRect(&BreakoutBall1RectDest, &leftRect, &intersectionRect)){
			printf("ball is left of brick \n");
			ball.XSpeed = 0-fabs(ball.XSpeed);
			hit = true;
		}
		else if(SDL_IntersectRect(&BreakoutBall1RectDest, &aboveRect, &intersectionRect)){
			printf("ball is above brick \n");
			ball.YSpeed = 0-fabs(ball.YSpeed);
			hit = true;
		}
		else if(SDL_IntersectRect(&BreakoutBall1RectDest, &belowRect, &intersectionRect)){
			printf("ball is below brick \n");
			ball.YSpeed = 0+fabs(ball.YSpeed);
			hit = true;
		}

		SDL_Rect brickRect = {bricks[i].x, bricks[i].y, BRICK_WIDTH, BRICK_HEIGHT};
		if(SDL_IntersectRect(&brickRect, &BreakoutBall1RectDest, &intersectionRect)){
			//TODO: determine side of collision.
			//hit = true;
		}

		if(hit){
			bricks[i].damage--;
			if(bricks[i].damage == 0){
				bricksLeft--;
			}
			speedAmplifier += 0.01;

            ball.x += ball.XSpeed*speedAmplifier;
            ball.y += ball.YSpeed*speedAmplifier;
		}


	}
}


void wait(int WaitTicks){
    waitedTicks = 0;
    waiting = true;
    waitTicks = WaitTicks;
}

void renderBricks(){
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

void doRendering(){
	//Using surfaces, OLD.
/*	SDL_FillRect(gScreenSurface, NULL, 9868950);
	SDL_BlitSurface(breakout_image, &BreakoutBallRectSauce, gScreenSurface, &BreakoutBall1RectDest);
	if(motionBlur){
		SDL_BlitSurface(breakout_image, &BreakoutBallRectSauce, gScreenSurface, &BreakoutBall2RectDest);
	}
	SDL_BlitSurface(breakout_image, &BreakoutPaddleRectSauce, gScreenSurface, &paddleDest);
	SDL_UpdateWindowSurface( gWindow );
	*/

	//Used Gray:
	//RGB(50,50,50)
	//Hex(323232)
	//Int(3289650)

	//Using Renderer
	SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, breakout_texture, &BreakoutBallRectSauce, &BreakoutBall1RectDest);
	//filledCircleRGBA(renderer, BreakoutBall1RectDest.x+BreakoutBall1RectDest.w/2, BreakoutBall1RectDest.y+BreakoutBall1RectDest.w/2, BreakoutBall1RectDest.w/2, 100, 0, 0, 255);
	//filledCircleRGBA(renderer, BreakoutBall1RectDest.x+BreakoutBall1RectDest.w/2, BreakoutBall1RectDest.y+BreakoutBall1RectDest.h/2, BreakoutBall1RectDest.w/2, 0, 0, 0, 255);

	if(motionBlur){
		aacircleRGBA(renderer, BreakoutBall2RectDest.x+BreakoutBall2RectDest.w/2, BreakoutBall2RectDest.y+BreakoutBall2RectDest.h/2
				, BreakoutBall2RectDest.w/2, 0, 0, 0, 255);
	}
	//SDL_RenderCopy(renderer, breakout_texture, &BreakoutPaddleRectSauce, &paddleDest);
	SDL_Point screenCenter = {SCREEN_WIDTH*1.3/4, SCREEN_HEIGHT*1.3/4};

	SDL_RenderCopyEx(renderer, breakout_texture, &BreakoutPaddleRectSauce, &paddleDest, paddleRotation, NULL, SDL_FLIP_NONE);

	renderBricks();

	if(debugging){
		SDL_Surface* textSurface = NULL;
		SDL_Texture* textTexture = NULL;
		char textToRender[80];

		sprintf(textToRender, "Framerate: %f fps", framerate);

		textSurface = TTF_RenderText_Solid(font, textToRender, (SDL_Color){0,0,0} );

		textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
		SDL_RenderCopy(renderer, textTexture, NULL, &((SDL_Rect){10,10,textSurface->w,textSurface->h}) );

		SDL_DestroyTexture(textTexture);
		textTexture = NULL;
		SDL_FreeSurface(textSurface);
		textSurface = NULL;

		sprintf(textToRender, "Speed amplifier: %f  XSpeed: %f  YSpeed: %f  Tickrate: %f",speedAmplifier, ball.XSpeed, ball.YSpeed, tickrate);

		textSurface = TTF_RenderText_Solid(font, textToRender, (SDL_Color){0,0,0} );

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


int startBreakoutGame(){

	quitBreakoutGame = false;
	int exitStatus = 0;

	Uint32 previousTick;
	Uint32 tickBeforeThat;

	bool update = true;

	Uint32 previousFrame;
	Uint32 frameBeforeThat;

	bool render = true;

	SDL_SetWindowTitle(gWindow, "Brikz");

	if( !loadBreakoutGame() ){
		quitBreakoutGame = true;
		exitStatus = -1;
	}
	startNewRound();

	previousTick = SDL_GetTicks();
	previousFrame = previousTick;
	while(!quitBreakoutGame){

		if( SDL_GetTicks()-previousTick < 10 ){
			update = false;
		}
		if( SDL_GetTicks()-previousFrame < 10 ){
			render = false;
		}

		if(update){
			tickBeforeThat = previousTick;
			previousTick = SDL_GetTicks();
			tickrate = 1000.0/(previousTick - tickBeforeThat);
			if(tickrate != 100.0){
					printf("%f Ticks per Second\n", tickrate );
			}
			updateLogic();
		}

		if(render){
			frameBeforeThat = previousFrame;
			previousFrame = SDL_GetTicks();
			framerate = 1000.0/(previousFrame - frameBeforeThat);
			if(framerate != 100.0){
				printf("%f Frames per Second\n", framerate );
			}
			doRendering();
		}

		if(update){
			while( SDL_PollEvent(&e) ){
				if( e.type == SDL_QUIT ){
					quit = true;
					quitBreakoutGame = true;
				}

				else if(e.type == SDL_KEYDOWN){
					printf("key pressed: %s \n", SDL_GetKeyName(e.key.keysym.sym) );
					if(e.key.keysym.sym == SDLK_ESCAPE){
						quitBreakoutGame = true;
						continue;
					}
					else if(e.key.keysym.sym == SDLK_LEFT || e.key.keysym.sym == SDLK_RIGHT){
						continue;
					}
					else if(e.key.keysym.sym == SDLK_m){
						motionBlur = !motionBlur;
					}
					else if(e.key.keysym.sym == SDLK_EQUALS){

						speedAmplifier = speedAmplifier + 0.05;
					}
					else if(e.key.keysym.sym == SDLK_MINUS){
						speedAmplifier = speedAmplifier - 0.05;
					}

				}
			}

			if( KeyBoardState[SDL_SCANCODE_RIGHT] ){ movePaddle(true); }
			if( KeyBoardState[SDL_SCANCODE_LEFT] ){ movePaddle(false); }
			if( KeyBoardState[SDL_SCANCODE_UP] ){ paddleDest.y=paddleDest.y-PADDLE_STEP; }
			if( KeyBoardState[SDL_SCANCODE_DOWN] ){ paddleDest.y=paddleDest.y+PADDLE_STEP; }
			if( KeyBoardState[SDL_SCANCODE_RSHIFT] ){ paddleRotation+=5; }
			if( KeyBoardState[SDL_SCANCODE_LSHIFT] ){ paddleRotation-=5; }
		}

		render=true;
		update=true;


	}

	closeBreakoutGame();
	return exitStatus;
}
