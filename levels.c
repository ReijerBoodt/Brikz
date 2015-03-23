#include "header.h"
#include "Brikz.h"

void loadLevel1(){

	bricksInLevel = 256;

	bricks = (Brick*) realloc(bricks, bricksInLevel*sizeof(Brick));

	int i;
	int p=0;
	for(i=0; i<16; i++){
		int n;
		for(n=0; n<16; n++){
            if( n == i ||i+n ==15 || i==0 || i==15 || n==0 || n==15 ){
                *(bricks + p) = (Brick){50+i*72, 50+n*22,2};
                //printf("*(bricks + %i) = (Brick){50+ %i*72, 50+ %i*22,2};\n",p,i,n);
            }
            else{
                *(bricks + p) = (Brick){50+i*72, 50+n*22,1};
                //printf("*(bricks + %i) = (Brick){50+ %i*72, 50+ %i*22,1};\n",p,i,n);
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
void loadLevelGeneric(){
    bricksInLevel = 256;
    bricks = (Brick*) realloc(bricks, bricksInLevel*sizeof(Brick));

    *(bricks + 0) = (Brick){50+ 0*72, 50+ 0*22,1};
    *(bricks + 1) = (Brick){50+ 0*72, 50+ 1*22,1};
    *(bricks + 2) = (Brick){50+ 0*72, 50+ 2*22,1};
    *(bricks + 3) = (Brick){50+ 0*72, 50+ 3*22,1};
    *(bricks + 4) = (Brick){50+ 0*72, 50+ 4*22,1};
    *(bricks + 5) = (Brick){50+ 0*72, 50+ 5*22,1};
    *(bricks + 6) = (Brick){50+ 0*72, 50+ 6*22,1};
    *(bricks + 7) = (Brick){50+ 0*72, 50+ 7*22,1};
    *(bricks + 8) = (Brick){50+ 0*72, 50+ 8*22,1};
    *(bricks + 9) = (Brick){50+ 0*72, 50+ 9*22,1};
    *(bricks + 10) = (Brick){50+ 0*72, 50+ 10*22,1};
    *(bricks + 11) = (Brick){50+ 0*72, 50+ 11*22,1};
    *(bricks + 12) = (Brick){50+ 0*72, 50+ 12*22,1};
    *(bricks + 13) = (Brick){50+ 0*72, 50+ 13*22,1};
    *(bricks + 14) = (Brick){50+ 0*72, 50+ 14*22,1};
    *(bricks + 15) = (Brick){50+ 0*72, 50+ 15*22,1};
    *(bricks + 16) = (Brick){50+ 1*72, 50+ 0*22,1};
    *(bricks + 17) = (Brick){50+ 1*72, 50+ 1*22,1};
    *(bricks + 18) = (Brick){50+ 1*72, 50+ 2*22,1};
    *(bricks + 19) = (Brick){50+ 1*72, 50+ 3*22,1};
    *(bricks + 20) = (Brick){50+ 1*72, 50+ 4*22,1};
    *(bricks + 21) = (Brick){50+ 1*72, 50+ 5*22,1};
    *(bricks + 22) = (Brick){50+ 1*72, 50+ 6*22,1};
    *(bricks + 23) = (Brick){50+ 1*72, 50+ 7*22,1};
    *(bricks + 24) = (Brick){50+ 1*72, 50+ 8*22,1};
    *(bricks + 25) = (Brick){50+ 1*72, 50+ 9*22,1};
    *(bricks + 26) = (Brick){50+ 1*72, 50+ 10*22,1};
    *(bricks + 27) = (Brick){50+ 1*72, 50+ 11*22,1};
    *(bricks + 28) = (Brick){50+ 1*72, 50+ 12*22,1};
    *(bricks + 29) = (Brick){50+ 1*72, 50+ 13*22,1};
    *(bricks + 30) = (Brick){50+ 1*72, 50+ 14*22,1};
    *(bricks + 31) = (Brick){50+ 1*72, 50+ 15*22,1};
    *(bricks + 32) = (Brick){50+ 2*72, 50+ 0*22,1};
    *(bricks + 33) = (Brick){50+ 2*72, 50+ 1*22,1};
    *(bricks + 34) = (Brick){50+ 2*72, 50+ 2*22,1};
    *(bricks + 35) = (Brick){50+ 2*72, 50+ 3*22,1};
    *(bricks + 36) = (Brick){50+ 2*72, 50+ 4*22,1};
    *(bricks + 37) = (Brick){50+ 2*72, 50+ 5*22,1};
    *(bricks + 38) = (Brick){50+ 2*72, 50+ 6*22,1};
    *(bricks + 39) = (Brick){50+ 2*72, 50+ 7*22,1};
    *(bricks + 40) = (Brick){50+ 2*72, 50+ 8*22,1};
    *(bricks + 41) = (Brick){50+ 2*72, 50+ 9*22,1};
    *(bricks + 42) = (Brick){50+ 2*72, 50+ 10*22,1};
    *(bricks + 43) = (Brick){50+ 2*72, 50+ 11*22,1};
    *(bricks + 44) = (Brick){50+ 2*72, 50+ 12*22,1};
    *(bricks + 45) = (Brick){50+ 2*72, 50+ 13*22,1};
    *(bricks + 46) = (Brick){50+ 2*72, 50+ 14*22,1};
    *(bricks + 47) = (Brick){50+ 2*72, 50+ 15*22,1};
    *(bricks + 48) = (Brick){50+ 3*72, 50+ 0*22,1};
    *(bricks + 49) = (Brick){50+ 3*72, 50+ 1*22,1};
    *(bricks + 50) = (Brick){50+ 3*72, 50+ 2*22,1};
    *(bricks + 51) = (Brick){50+ 3*72, 50+ 3*22,1};
    *(bricks + 52) = (Brick){50+ 3*72, 50+ 4*22,1};
    *(bricks + 53) = (Brick){50+ 3*72, 50+ 5*22,1};
    *(bricks + 54) = (Brick){50+ 3*72, 50+ 6*22,1};
    *(bricks + 55) = (Brick){50+ 3*72, 50+ 7*22,1};
    *(bricks + 56) = (Brick){50+ 3*72, 50+ 8*22,1};
    *(bricks + 57) = (Brick){50+ 3*72, 50+ 9*22,1};
    *(bricks + 58) = (Brick){50+ 3*72, 50+ 10*22,1};
    *(bricks + 59) = (Brick){50+ 3*72, 50+ 11*22,1};
    *(bricks + 60) = (Brick){50+ 3*72, 50+ 12*22,1};
    *(bricks + 61) = (Brick){50+ 3*72, 50+ 13*22,1};
    *(bricks + 62) = (Brick){50+ 3*72, 50+ 14*22,1};
    *(bricks + 63) = (Brick){50+ 3*72, 50+ 15*22,1};
    *(bricks + 64) = (Brick){50+ 4*72, 50+ 0*22,1};
    *(bricks + 65) = (Brick){50+ 4*72, 50+ 1*22,1};
    *(bricks + 66) = (Brick){50+ 4*72, 50+ 2*22,1};
    *(bricks + 67) = (Brick){50+ 4*72, 50+ 3*22,1};
    *(bricks + 68) = (Brick){50+ 4*72, 50+ 4*22,1};
    *(bricks + 69) = (Brick){50+ 4*72, 50+ 5*22,1};
    *(bricks + 70) = (Brick){50+ 4*72, 50+ 6*22,1};
    *(bricks + 71) = (Brick){50+ 4*72, 50+ 7*22,1};
    *(bricks + 72) = (Brick){50+ 4*72, 50+ 8*22,1};
    *(bricks + 73) = (Brick){50+ 4*72, 50+ 9*22,1};
    *(bricks + 74) = (Brick){50+ 4*72, 50+ 10*22,1};
    *(bricks + 75) = (Brick){50+ 4*72, 50+ 11*22,1};
    *(bricks + 76) = (Brick){50+ 4*72, 50+ 12*22,1};
    *(bricks + 77) = (Brick){50+ 4*72, 50+ 13*22,1};
    *(bricks + 78) = (Brick){50+ 4*72, 50+ 14*22,1};
    *(bricks + 79) = (Brick){50+ 4*72, 50+ 15*22,1};
    *(bricks + 80) = (Brick){50+ 5*72, 50+ 0*22,1};
    *(bricks + 81) = (Brick){50+ 5*72, 50+ 1*22,1};
    *(bricks + 82) = (Brick){50+ 5*72, 50+ 2*22,1};
    *(bricks + 83) = (Brick){50+ 5*72, 50+ 3*22,1};
    *(bricks + 84) = (Brick){50+ 5*72, 50+ 4*22,1};
    *(bricks + 85) = (Brick){50+ 5*72, 50+ 5*22,1};
    *(bricks + 86) = (Brick){50+ 5*72, 50+ 6*22,1};
    *(bricks + 87) = (Brick){50+ 5*72, 50+ 7*22,1};
    *(bricks + 88) = (Brick){50+ 5*72, 50+ 8*22,1};
    *(bricks + 89) = (Brick){50+ 5*72, 50+ 9*22,1};
    *(bricks + 90) = (Brick){50+ 5*72, 50+ 10*22,1};
    *(bricks + 91) = (Brick){50+ 5*72, 50+ 11*22,1};
    *(bricks + 92) = (Brick){50+ 5*72, 50+ 12*22,1};
    *(bricks + 93) = (Brick){50+ 5*72, 50+ 13*22,1};
    *(bricks + 94) = (Brick){50+ 5*72, 50+ 14*22,1};
    *(bricks + 95) = (Brick){50+ 5*72, 50+ 15*22,1};
    *(bricks + 96) = (Brick){50+ 6*72, 50+ 0*22,1};
    *(bricks + 97) = (Brick){50+ 6*72, 50+ 1*22,1};
    *(bricks + 98) = (Brick){50+ 6*72, 50+ 2*22,1};
    *(bricks + 99) = (Brick){50+ 6*72, 50+ 3*22,1};
    *(bricks + 100) = (Brick){50+ 6*72, 50+ 4*22,1};
    *(bricks + 101) = (Brick){50+ 6*72, 50+ 5*22,1};
    *(bricks + 102) = (Brick){50+ 6*72, 50+ 6*22,1};
    *(bricks + 103) = (Brick){50+ 6*72, 50+ 7*22,1};
    *(bricks + 104) = (Brick){50+ 6*72, 50+ 8*22,1};
    *(bricks + 105) = (Brick){50+ 6*72, 50+ 9*22,1};
    *(bricks + 106) = (Brick){50+ 6*72, 50+ 10*22,1};
    *(bricks + 107) = (Brick){50+ 6*72, 50+ 11*22,1};
    *(bricks + 108) = (Brick){50+ 6*72, 50+ 12*22,1};
    *(bricks + 109) = (Brick){50+ 6*72, 50+ 13*22,1};
    *(bricks + 110) = (Brick){50+ 6*72, 50+ 14*22,1};
    *(bricks + 111) = (Brick){50+ 6*72, 50+ 15*22,1};
    *(bricks + 112) = (Brick){50+ 7*72, 50+ 0*22,1};
    *(bricks + 113) = (Brick){50+ 7*72, 50+ 1*22,1};
    *(bricks + 114) = (Brick){50+ 7*72, 50+ 2*22,1};
    *(bricks + 115) = (Brick){50+ 7*72, 50+ 3*22,1};
    *(bricks + 116) = (Brick){50+ 7*72, 50+ 4*22,1};
    *(bricks + 117) = (Brick){50+ 7*72, 50+ 5*22,1};
    *(bricks + 118) = (Brick){50+ 7*72, 50+ 6*22,1};
    *(bricks + 119) = (Brick){50+ 7*72, 50+ 7*22,1};
    *(bricks + 120) = (Brick){50+ 7*72, 50+ 8*22,1};
    *(bricks + 121) = (Brick){50+ 7*72, 50+ 9*22,1};
    *(bricks + 122) = (Brick){50+ 7*72, 50+ 10*22,1};
    *(bricks + 123) = (Brick){50+ 7*72, 50+ 11*22,1};
    *(bricks + 124) = (Brick){50+ 7*72, 50+ 12*22,1};
    *(bricks + 125) = (Brick){50+ 7*72, 50+ 13*22,1};
    *(bricks + 126) = (Brick){50+ 7*72, 50+ 14*22,1};
    *(bricks + 127) = (Brick){50+ 7*72, 50+ 15*22,1};
    *(bricks + 128) = (Brick){50+ 8*72, 50+ 0*22,1};
    *(bricks + 129) = (Brick){50+ 8*72, 50+ 1*22,1};
    *(bricks + 130) = (Brick){50+ 8*72, 50+ 2*22,1};
    *(bricks + 131) = (Brick){50+ 8*72, 50+ 3*22,1};
    *(bricks + 132) = (Brick){50+ 8*72, 50+ 4*22,1};
    *(bricks + 133) = (Brick){50+ 8*72, 50+ 5*22,1};
    *(bricks + 134) = (Brick){50+ 8*72, 50+ 6*22,1};
    *(bricks + 135) = (Brick){50+ 8*72, 50+ 7*22,1};
    *(bricks + 136) = (Brick){50+ 8*72, 50+ 8*22,1};
    *(bricks + 137) = (Brick){50+ 8*72, 50+ 9*22,1};
    *(bricks + 138) = (Brick){50+ 8*72, 50+ 10*22,1};
    *(bricks + 139) = (Brick){50+ 8*72, 50+ 11*22,1};
    *(bricks + 140) = (Brick){50+ 8*72, 50+ 12*22,1};
    *(bricks + 141) = (Brick){50+ 8*72, 50+ 13*22,1};
    *(bricks + 142) = (Brick){50+ 8*72, 50+ 14*22,1};
    *(bricks + 143) = (Brick){50+ 8*72, 50+ 15*22,1};
    *(bricks + 144) = (Brick){50+ 9*72, 50+ 0*22,1};
    *(bricks + 145) = (Brick){50+ 9*72, 50+ 1*22,1};
    *(bricks + 146) = (Brick){50+ 9*72, 50+ 2*22,1};
    *(bricks + 147) = (Brick){50+ 9*72, 50+ 3*22,1};
    *(bricks + 148) = (Brick){50+ 9*72, 50+ 4*22,1};
    *(bricks + 149) = (Brick){50+ 9*72, 50+ 5*22,1};
    *(bricks + 150) = (Brick){50+ 9*72, 50+ 6*22,1};
    *(bricks + 151) = (Brick){50+ 9*72, 50+ 7*22,1};
    *(bricks + 152) = (Brick){50+ 9*72, 50+ 8*22,1};
    *(bricks + 153) = (Brick){50+ 9*72, 50+ 9*22,1};
    *(bricks + 154) = (Brick){50+ 9*72, 50+ 10*22,1};
    *(bricks + 155) = (Brick){50+ 9*72, 50+ 11*22,1};
    *(bricks + 156) = (Brick){50+ 9*72, 50+ 12*22,1};
    *(bricks + 157) = (Brick){50+ 9*72, 50+ 13*22,1};
    *(bricks + 158) = (Brick){50+ 9*72, 50+ 14*22,1};
    *(bricks + 159) = (Brick){50+ 9*72, 50+ 15*22,1};
    *(bricks + 160) = (Brick){50+ 10*72, 50+ 0*22,1};
    *(bricks + 161) = (Brick){50+ 10*72, 50+ 1*22,1};
    *(bricks + 162) = (Brick){50+ 10*72, 50+ 2*22,1};
    *(bricks + 163) = (Brick){50+ 10*72, 50+ 3*22,1};
    *(bricks + 164) = (Brick){50+ 10*72, 50+ 4*22,1};
    *(bricks + 165) = (Brick){50+ 10*72, 50+ 5*22,1};
    *(bricks + 166) = (Brick){50+ 10*72, 50+ 6*22,1};
    *(bricks + 167) = (Brick){50+ 10*72, 50+ 7*22,1};
    *(bricks + 168) = (Brick){50+ 10*72, 50+ 8*22,1};
    *(bricks + 169) = (Brick){50+ 10*72, 50+ 9*22,1};
    *(bricks + 170) = (Brick){50+ 10*72, 50+ 10*22,1};
    *(bricks + 171) = (Brick){50+ 10*72, 50+ 11*22,1};
    *(bricks + 172) = (Brick){50+ 10*72, 50+ 12*22,1};
    *(bricks + 173) = (Brick){50+ 10*72, 50+ 13*22,1};
    *(bricks + 174) = (Brick){50+ 10*72, 50+ 14*22,1};
    *(bricks + 175) = (Brick){50+ 10*72, 50+ 15*22,1};
    *(bricks + 176) = (Brick){50+ 11*72, 50+ 0*22,1};
    *(bricks + 177) = (Brick){50+ 11*72, 50+ 1*22,1};
    *(bricks + 178) = (Brick){50+ 11*72, 50+ 2*22,1};
    *(bricks + 179) = (Brick){50+ 11*72, 50+ 3*22,1};
    *(bricks + 180) = (Brick){50+ 11*72, 50+ 4*22,1};
    *(bricks + 181) = (Brick){50+ 11*72, 50+ 5*22,1};
    *(bricks + 182) = (Brick){50+ 11*72, 50+ 6*22,1};
    *(bricks + 183) = (Brick){50+ 11*72, 50+ 7*22,1};
    *(bricks + 184) = (Brick){50+ 11*72, 50+ 8*22,1};
    *(bricks + 185) = (Brick){50+ 11*72, 50+ 9*22,1};
    *(bricks + 186) = (Brick){50+ 11*72, 50+ 10*22,1};
    *(bricks + 187) = (Brick){50+ 11*72, 50+ 11*22,1};
    *(bricks + 188) = (Brick){50+ 11*72, 50+ 12*22,1};
    *(bricks + 189) = (Brick){50+ 11*72, 50+ 13*22,1};
    *(bricks + 190) = (Brick){50+ 11*72, 50+ 14*22,1};
    *(bricks + 191) = (Brick){50+ 11*72, 50+ 15*22,1};
    *(bricks + 192) = (Brick){50+ 12*72, 50+ 0*22,1};
    *(bricks + 193) = (Brick){50+ 12*72, 50+ 1*22,1};
    *(bricks + 194) = (Brick){50+ 12*72, 50+ 2*22,1};
    *(bricks + 195) = (Brick){50+ 12*72, 50+ 3*22,1};
    *(bricks + 196) = (Brick){50+ 12*72, 50+ 4*22,1};
    *(bricks + 197) = (Brick){50+ 12*72, 50+ 5*22,1};
    *(bricks + 198) = (Brick){50+ 12*72, 50+ 6*22,1};
    *(bricks + 199) = (Brick){50+ 12*72, 50+ 7*22,1};
    *(bricks + 200) = (Brick){50+ 12*72, 50+ 8*22,1};
    *(bricks + 201) = (Brick){50+ 12*72, 50+ 9*22,1};
    *(bricks + 202) = (Brick){50+ 12*72, 50+ 10*22,1};
    *(bricks + 203) = (Brick){50+ 12*72, 50+ 11*22,1};
    *(bricks + 204) = (Brick){50+ 12*72, 50+ 12*22,1};
    *(bricks + 205) = (Brick){50+ 12*72, 50+ 13*22,1};
    *(bricks + 206) = (Brick){50+ 12*72, 50+ 14*22,1};
    *(bricks + 207) = (Brick){50+ 12*72, 50+ 15*22,1};
    *(bricks + 208) = (Brick){50+ 13*72, 50+ 0*22,1};
    *(bricks + 209) = (Brick){50+ 13*72, 50+ 1*22,1};
    *(bricks + 210) = (Brick){50+ 13*72, 50+ 2*22,1};
    *(bricks + 211) = (Brick){50+ 13*72, 50+ 3*22,1};
    *(bricks + 212) = (Brick){50+ 13*72, 50+ 4*22,1};
    *(bricks + 213) = (Brick){50+ 13*72, 50+ 5*22,1};
    *(bricks + 214) = (Brick){50+ 13*72, 50+ 6*22,1};
    *(bricks + 215) = (Brick){50+ 13*72, 50+ 7*22,1};
    *(bricks + 216) = (Brick){50+ 13*72, 50+ 8*22,1};
    *(bricks + 217) = (Brick){50+ 13*72, 50+ 9*22,1};
    *(bricks + 218) = (Brick){50+ 13*72, 50+ 10*22,1};
    *(bricks + 219) = (Brick){50+ 13*72, 50+ 11*22,1};
    *(bricks + 220) = (Brick){50+ 13*72, 50+ 12*22,1};
    *(bricks + 221) = (Brick){50+ 13*72, 50+ 13*22,1};
    *(bricks + 222) = (Brick){50+ 13*72, 50+ 14*22,1};
    *(bricks + 223) = (Brick){50+ 13*72, 50+ 15*22,1};
    *(bricks + 224) = (Brick){50+ 14*72, 50+ 0*22,1};
    *(bricks + 225) = (Brick){50+ 14*72, 50+ 1*22,1};
    *(bricks + 226) = (Brick){50+ 14*72, 50+ 2*22,1};
    *(bricks + 227) = (Brick){50+ 14*72, 50+ 3*22,1};
    *(bricks + 228) = (Brick){50+ 14*72, 50+ 4*22,1};
    *(bricks + 229) = (Brick){50+ 14*72, 50+ 5*22,1};
    *(bricks + 230) = (Brick){50+ 14*72, 50+ 6*22,1};
    *(bricks + 231) = (Brick){50+ 14*72, 50+ 7*22,1};
    *(bricks + 232) = (Brick){50+ 14*72, 50+ 8*22,1};
    *(bricks + 233) = (Brick){50+ 14*72, 50+ 9*22,1};
    *(bricks + 234) = (Brick){50+ 14*72, 50+ 10*22,1};
    *(bricks + 235) = (Brick){50+ 14*72, 50+ 11*22,1};
    *(bricks + 236) = (Brick){50+ 14*72, 50+ 12*22,1};
    *(bricks + 237) = (Brick){50+ 14*72, 50+ 13*22,1};
    *(bricks + 238) = (Brick){50+ 14*72, 50+ 14*22,1};
    *(bricks + 239) = (Brick){50+ 14*72, 50+ 15*22,1};
    *(bricks + 240) = (Brick){50+ 15*72, 50+ 0*22,1};
    *(bricks + 241) = (Brick){50+ 15*72, 50+ 1*22,1};
    *(bricks + 242) = (Brick){50+ 15*72, 50+ 2*22,1};
    *(bricks + 243) = (Brick){50+ 15*72, 50+ 3*22,1};
    *(bricks + 244) = (Brick){50+ 15*72, 50+ 4*22,1};
    *(bricks + 245) = (Brick){50+ 15*72, 50+ 5*22,1};
    *(bricks + 246) = (Brick){50+ 15*72, 50+ 6*22,1};
    *(bricks + 247) = (Brick){50+ 15*72, 50+ 7*22,1};
    *(bricks + 248) = (Brick){50+ 15*72, 50+ 8*22,1};
    *(bricks + 249) = (Brick){50+ 15*72, 50+ 9*22,1};
    *(bricks + 250) = (Brick){50+ 15*72, 50+ 10*22,1};
    *(bricks + 251) = (Brick){50+ 15*72, 50+ 11*22,1};
    *(bricks + 252) = (Brick){50+ 15*72, 50+ 12*22,1};
    *(bricks + 253) = (Brick){50+ 15*72, 50+ 13*22,1};
    *(bricks + 254) = (Brick){50+ 15*72, 50+ 14*22,1};
    *(bricks + 255) = (Brick){50+ 15*72, 50+ 15*22,1};

    bricksLeft = bricksInLevel;
}

bool loadLevelFromFile(const char *filename){
    FILE *levelFile = fopen(filename, "rb");
    if(levelFile == NULL){
        return false;
    }
    int numbricks;
    fread(numbricks, sizeof(int), 1, levelFile);

    free(bricks);
    bricks = (Brick*) calloc(numbricks, sizeof(Brick));

    bricksInLevel = fread(bricks, sizeof(Brick), numbricks, levelFile);
    bricksLeft = bricksInLevel;

    fclose(levelFile);
    levelFile = NULL;
    return true;
}

bool writeLevelToFile(const char *filename){
    FILE *levelFile = fopen(filename, "w");
    if(levelFile == NULL){
        return false;
    }
    Brick *bricksBuffer = calloc(bricksInLevel, sizeof(Brick));
    int newBricksInLevel = 0;

    for(int i=0; i<bricksInLevel; i++){
        if( !bricks[i].damage == 0 ){
            bricksBuffer[newBricksInLevel] == bricks[i];
            newBricksInLevel++;
        }
    }
    fseek(levelFile, 0, SEEK_SET);
    fwrite(&newBricksInLevel, sizeof(int), 1, levelFile);
    fseek(levelFile, sizeof(int), SEEK_SET);
    fwrite(bricksBuffer, szieof(Brick), newBricksInLevel, levelFile);

    free(bricksBuffer);
    bricksBuffer = NULL;
    fclose(levelFile);
    levelFile = NULL;
    return true;
}
