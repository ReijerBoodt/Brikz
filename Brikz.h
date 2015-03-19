#define BRIKZ_IMAGE "BrikzSprites.png"
#define PADDLE_STEP 10
#define BALL_INITIAL_SPEED_X 20
#define BALL_INITIAL_SPEED_Y 10
#define BALL_SPEED_CONSTANT 500
#define BRICK_WIDTH 70
#define BRICK_HEIGHT 20
#define BALL_WIDTH 20
#define BALL_HEIGHT 20
#define DEBUG_FONT "Monaco.ttf"

typedef struct{
	float x;
	float y;
	int damage;
}Brick;

bool quitBreakoutGame;
bool waiting;
int waitTicks;
int waitedTicks;
float speedAmplifier;
SDL_Surface* breakout_image;
SDL_Texture* breakout_texture;
const Uint8* KeyBoardState;
int ScoreA;
int bricksLeft;
int bricksInLevel;
Brick *bricks;

float tickrate;
float framerate;
bool debugging;

TTF_Font* font;

void wait(int WaitTicks);
void updateBrickLogic();
void renderBricks();
void doRendering();

void loadLevel1();
void loadLevelGeneric();


SDL_Rect BreakoutPaddleRectSauce; // 0, 0 -> 27, 223
SDL_Rect BreakoutBallRectSauce;
SDL_Rect BrickLevel1RectSauce;
SDL_Rect BrickLevel2RectSauce;
SDL_Rect BreakoutBall1RectDest;
SDL_Rect BreakoutBall2RectDest;

SDL_Rect paddleDest;


