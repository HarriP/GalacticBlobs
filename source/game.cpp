#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include "libraryWrapper.h"
#include "game.h"
#include "input.h"

float pi = atan(1) * 4.0f;
extern int resolutionX;
extern int resolutionY;
extern int targetFps;

Vec2::Vec2() : x(0.0f), y(0.0f) {}
Vec2::Vec2(float aX, float aY) : x(aX), y(aY) {}
Vec2 Vec2::operator+(const Vec2& b) const{
    Vec2 temp;
    temp.x = x + b.x;
    temp.y = y + b.y;
    return temp;
}
Vec2& Vec2::operator+=(const Vec2& b){
    x += b.x;
    y += b.y;
    return *this;
}
Vec2 Vec2::operator-(const Vec2& b) const{
    Vec2 temp;
    temp.x = x - b.x;
    temp.y = y - b.y;
    return temp;
}
Vec2& Vec2::operator-=(const Vec2& b){
    x -= b.x;
    y -= b.y;
    return *this;
}
Vec2 Vec2::operator*(const Vec2& b) const{
    Vec2 temp;
    temp.x = x * b.x;
    temp.y = y * b.y;
    return temp;
}
Vec2& Vec2::operator*=(const Vec2& b){
    x *= b.x;
    y *= b.y;
    return *this;
}
Vec2 Vec2::operator*(float b) const{
    Vec2 temp;
    temp.x = x * b;
    temp.y = y * b;
    return temp;
}
bool Vec2::WithinRange(const Vec2& b, float diameter) const{
    if(hypot(b.x-x, b.y-y) < diameter){
        return true;
    }
    return false;
}
Vec2& Vec2::Normalize(){
    float h = hypot(x, y);
    x /= h;
    y /= h;
    return *this;
}

Blob::Blob() : position(0, 0), velocity(0, 0), size(0) {}
Blob::Blob(float posX, float posY, float velX, float velY, int aSize) : position(posX, posY), velocity(velX, velY), size(aSize) {}

Player::Player() : direction(0.0f), iceFuel(0), rechargingFuel(2000), orbitDrawSteps(800) {}

void Simulate(Blob& blob, float gravity){
    blob.position += blob.velocity * GetFrameTime();
    blob.velocity += (Vec2(resolutionX/2, resolutionY/2) - blob.position).Normalize() * gravity * GetFrameTime();
}

void DrawOrbit(Blob blob, float gravity, int steps){
    for(int i=0; i<steps; i++){
        Simulate(blob, gravity);
        DrawPixel(blob.position.x, blob.position.y, {255, 0, 0, 255});
    }
}

void Game(){
    bool menu = false;
    bool quit = false;
    float gravity = 200.0f;
    int rechargingFuelMax = 100000;
    Player player;
    player.size = 20.0f;
    player.position.x = 250;
    player.position.y = 250;
    while(true){
        BeginDrawing();
        ClearBackground(Color(0, 0, 0, 255));
        DrawFPS(10, 1);
        Simulate(player, gravity);
        DrawOrbit(player, gravity, player.orbitDrawSteps);
        DrawCircle(player.position.x, player.position.y, player.size, {80, 80, 80, 255});
        DrawLine(player.position.x, player.position.y, player.position.x+cos(player.direction)*player.size, player.position.y+sin(player.direction)*player.size, {255, 0, 0, 255});
        CheckInput(player);
        if(player.direction > pi * 2){
            player.direction -= pi * 2;
        }
        else if(player.direction < -pi * 2){
            player.direction += pi * 2;
        }
        player.rechargingFuel += 1000 * GetFrameTime();
        if(player.rechargingFuel > rechargingFuelMax){
            player.rechargingFuel = rechargingFuelMax;
        }
        else if(player.rechargingFuel < 0){
            player.rechargingFuel = 0;
        }
        DrawRectangleGradientH(100, 1, 100*(player.rechargingFuel/(float)rechargingFuelMax), 10, {255, 0, 0, 255}, {(unsigned char)(255*(1-(player.rechargingFuel/(float)rechargingFuelMax))), (unsigned char)(255*(player.rechargingFuel/(float)rechargingFuelMax)), 0, 255});
        DrawRectangleLines(100, 1, 100, 10, {0, 255, 0, 255});
        // DrawText(std::to_string(player.rechargingFuel).c_str(), 300, 1, 20, {0, 255, 0, 255});
        // DrawText(std::to_string(player.orbitDrawSteps).c_str(), 700, 1, 20, {0, 255, 0, 255});
        if(menu){
            // Draw main menu
            DrawText("Main menu", resolutionX/2-100, 10, 40, {0, 255, 0, 255});
            if(IsKeyPressed('O')){
                quit = true;
            }
        }
        if(IsKeyPressed('M')){
            menu = !menu;
        }
        else if(quit){
            break;
        }
        if(WindowShouldClose()){
            break;
        }
        EndDrawing();
    }
}
