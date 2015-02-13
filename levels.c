#include "header.h"
#include "Brikz.h"

void loadLevel1(){

	bricksInLevel = 256;

	bricks = (Brick*) realloc(bricks, bricksInLevel*sizeof(Brick));

	*(bricks + 0) = (Brick){0, 0, 1};

	*(bricks + 1) = (Brick){50, 100, 1};
	*(bricks + 2) = (Brick){122, 100, 1};
	*(bricks + 3) = (Brick){194, 100, 1};
	*(bricks + 4) = (Brick){266, 100, 1};
	*(bricks + 5) = (Brick){338, 100, 1};
	*(bricks + 6) = (Brick){410, 100, 1};
	*(bricks + 7) = (Brick){482, 100, 1};
	*(bricks + 8) = (Brick){554, 100, 1};
	*(bricks + 9) = (Brick){626, 100, 1};
	*(bricks + 10) = (Brick){698, 100, 1};
	*(bricks + 11) = (Brick){770, 100, 1};
	int i;
	int p=0;
	for(i=0; i<16; i++){
		int n;
		for(n=0; n<16; n++){
            if( n == i ||i+n ==15 || i==0 || i==15 || n==0 || n==15 ){
                *(bricks + p) = (Brick){50+i*72, 50+n*22,2};
            }
            else{
                *(bricks + p) = (Brick){50+i*72, 50+n*22,1};
			}
			p++;
		}
	}




	//*(bricks + 12) = (Brick){600, 300, 1};

	/* *(bricks + 8) = (Brick){rand()%1280, rand()%720, 1};
	*(bricks + 9) = (Brick){rand()%1280, rand()%720, 1};
	*(bricks + 10) = (Brick){rand()%1280, rand()%720, 1};
	*(bricks + 11) = (Brick){rand()%1280, rand()%720, 1};
	*/
	//bricks = (Brick*) realloc(bricks, (sizeof(bricks)/sizeof(Brick)+1)*sizeof(Brick) );
	bricksLeft = bricksInLevel;

}
