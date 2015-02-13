#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#define MENU_IMAGE "BrikzMenu.png"

const int SCREEN_WIDTH;
const int SCREEN_HEIGHT;
SDL_Window* gWindow;
SDL_Surface* gScreenSurface;
SDL_Renderer* renderer;
SDL_Surface* menu_image;
SDL_Texture* menu_texture;



int OpenMainMenu();
int StartPongGame();

bool quit;

bool isPointInsideRect(SDL_Point, SDL_Rect);
bool init();
bool loadMedia();
void close();
SDL_Event e;

SDL_Rect bmprect;
SDL_Rect pngrect;

SDL_Rect SinglePlayRectSauce; //25, 458 -> 248, 485
SDL_Rect OptionRectSauce; // 25, 563 -> 248, 590
SDL_Rect ExitRectSauce; //307, 781 -> 434, 808


SDL_Rect SinglePlayRectDest;
SDL_Rect OptionRectDest;
SDL_Rect ExitRectDest;


