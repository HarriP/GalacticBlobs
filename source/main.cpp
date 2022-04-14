#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "libraryWrapper.h"
#include "game.h"

int resolutionX = 1024;
int resolutionY = 768;
int targetFps = 60;
int keyUp = 265;
int keyLeft = 263;
int keyDown = 264;
int keyRight = 262;
std::mt19937_64 rndGen(time(NULL));

int main(int argc, char** argv){
    if(argc > 1){
        std::cout << "Command-line arguments example: -resolution 1280 960 -targetFps 60 -keys w a s d" << std::endl;
        std::cout << "-keysNumeric can also be used instead of -keys to give keys in numeric format, for example -keysNumeric 265 263 264 262 for arrow keys." << std::endl;
    }
    for(int i=1; i<argc; i++){
        if(strcmp(argv[i], "-resolution") == 0 && argc > i+2){
            resolutionX = atoi(argv[i+1]);
            resolutionY = atoi(argv[i+2]);
        }
        else if(strcmp(argv[i], "-targetFps") == 0 && argc > i+1){
            targetFps = atoi(argv[i+1]);
        }
        else if(strcmp(argv[i], "-keys") == 0 && argc > i+4){
            keyUp = argv[i+1][0];
            keyLeft = argv[i+2][0];
            keyDown = argv[i+3][0];
            keyRight = argv[i+4][0];
        }
        else if(strcmp(argv[i], "-keysNumeric") == 0 && argc > i+4){
            keyUp = argv[i+1][0];
            keyLeft = argv[i+2][0];
            keyDown = argv[i+3][0];
            keyRight = argv[i+4][0];
        }
    }
    InitWindow(resolutionX, resolutionY, "GalacticBlobs");
    SetTargetFPS(targetFps);
    Game();
    CloseWindow();
    return 0;
}
