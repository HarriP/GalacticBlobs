#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include "libraryWrapper.h"
#include "game.h"

extern int keyUp;
extern int keyLeft;
extern int keyDown;
extern int keyRight;

enum class Direction{
    None,
    Up,
    Left,
    Down,
    Right
};

bool ButtonHeld(Direction dir){
    if(dir == Direction::Up){
        if(IsKeyDown(keyUp) || IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)){
            return true;
        }
        return false;
    }
    else if(dir == Direction::Left){
        if(IsKeyDown(keyLeft) || IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)){
            return true;
        }
        return false;
    }
    else if(dir == Direction::Down){
        if(IsKeyDown(keyDown) || IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)){
            return true;
        }
        return false;
    }
    else if(dir == Direction::Right){
        if(IsKeyDown(keyRight) || IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)){
            return true;
        }
        return false;
    }
    return false;
}

void CheckInput(Player& player){
    if(ButtonHeld(Direction::Left)){
        player.direction -= 4.0f * GetFrameTime();
    }
    else if(ButtonHeld(Direction::Right)){
        player.direction += 4.0f * GetFrameTime();
    }
    if(ButtonHeld(Direction::Up)){
        if(player.rechargingFuel > 0){
            player.velocity.x += cos(player.direction) * 50.0f * GetFrameTime();
            player.velocity.y += sin(player.direction) * 50.0f * GetFrameTime();
            player.rechargingFuel -= 8000 * GetFrameTime();
        }
    }
    else if(ButtonHeld(Direction::Down)){
        if(player.rechargingFuel > 0){
            player.velocity.x -= cos(player.direction) * 50.0f * GetFrameTime();
            player.velocity.y -= sin(player.direction) * 50.0f * GetFrameTime();
            player.rechargingFuel -= 8000 * GetFrameTime();
        }
    }
    if(IsKeyPressed(KEY_KP_ADD) || IsKeyPressed(KEY_EQUAL)){
        player.orbitDrawSteps += 100;
    }
    else if(IsKeyPressed(KEY_KP_SUBTRACT) || IsKeyPressed(KEY_MINUS)){
        player.orbitDrawSteps -= 100;
    }
}
