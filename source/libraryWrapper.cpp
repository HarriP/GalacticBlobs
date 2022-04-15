#include "libraryWrapper.h"

Color::Color(unsigned char aR, unsigned char aG, unsigned char aB, unsigned char aA) : r(aR), g(aG), b(aB), a(aA){}

namespace Raylib{
    #include "raylib.h"
}

void InitWindow(int resolutionX, int resolutionY, const char* windowTitle){
    Raylib::InitWindow(resolutionX, resolutionY, windowTitle);
}
void CloseWindow(){
    Raylib::CloseWindow();
}
void SetTargetFPS(int fps){
    Raylib::SetTargetFPS(fps);
}
float GetFrameTime(){
    return Raylib::GetFrameTime();
}
bool WindowShouldClose(){
    return Raylib::WindowShouldClose();
}
void BeginDrawing(){
    Raylib::BeginDrawing();
}
void EndDrawing(){
    Raylib::EndDrawing();
}
void ClearBackground(const Color& c){
    Raylib::ClearBackground((Raylib::Color){c.r, c.g, c.b, c.a});
}
void DrawFPS(int posX, int posY){
    Raylib::DrawFPS(posX, posY);
}
void DrawText(const std::string& text, int posX, int posY, int fontSize, const Color& c){
    Raylib::DrawText(text.c_str(), posX, posY, fontSize, (Raylib::Color){c.r, c.g, c.b, c.a});
}
void DrawRectangle(int posX, int posY, int width, int height, const Color& c){
    Raylib::DrawRectangle(posX, posY, width, height, (Raylib::Color){c.r, c.g, c.b, c.a});
}
void DrawRectangleLines(int posX, int posY, int width, int height, const Color& c){
    Raylib::DrawRectangleLines(posX, posY, width, height, (Raylib::Color){c.r, c.g, c.b, c.a});
}
void DrawRectangleGradientV(int posX, int posY, int width, int height, const Color& c1, const Color& c2){
    Raylib::DrawRectangleGradientV(posX, posY, width, height, (Raylib::Color){c1.r, c1.g, c1.b, c1.a}, (Raylib::Color){c2.r, c2.g, c2.b, c2.a});
}
void DrawRectangleGradientH(int posX, int posY, int width, int height, const Color& c1, const Color& c2){
    Raylib::DrawRectangleGradientH(posX, posY, width, height, (Raylib::Color){c1.r, c1.g, c1.b, c1.a}, (Raylib::Color){c2.r, c2.g, c2.b, c2.a});
}
void DrawSquare(int posX, int posY, int width, const Color& c){
    Raylib::DrawRectangle(posX, posY, width, width, (Raylib::Color){c.r, c.g, c.b, c.a});
}
void DrawCircle(int centerX, int centerY, float radius, const Color& c){
    Raylib::DrawCircle(centerX, centerY, radius, (Raylib::Color){c.r, c.g, c.b, c.a});
}
void DrawLine(int startPosX, int startPosY, int endPosX, int endPosY, const Color& c){
    Raylib::DrawLine(startPosX, startPosY, endPosX, endPosY, (Raylib::Color){c.r, c.g, c.b, c.a});
}
void DrawPixel(int posX, int posY, const Color& c){
    Raylib::DrawPixel(posX, posY, (Raylib::Color){c.r, c.g, c.b, c.a});
}
bool IsKeyPressed(int key){
    return Raylib::IsKeyPressed(key);
}
bool IsKeyReleased(int key){
    return Raylib::IsKeyReleased(key);
}
bool IsKeyDown(int key){
    return Raylib::IsKeyDown(key);
}
bool IsKeyUp(int key){
    return Raylib::IsKeyUp(key);
}
