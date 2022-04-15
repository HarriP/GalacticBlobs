void Game();

class Vec2{
public:
    float x;
    float y;
    Vec2();
    Vec2(float aX, float aY);
    Vec2 operator+(const Vec2& b) const;
    Vec2& operator+=(const Vec2& b);
    Vec2 operator-(const Vec2& b) const;
    Vec2& operator-=(const Vec2& b);
    Vec2 operator*(const Vec2& b) const;
    Vec2& operator*=(const Vec2& b);
    Vec2 operator*(float b) const;
    bool WithinRange(const Vec2& b, float diameter) const;
    Vec2& Normalize();
};

class Blob{
public:
    Vec2 position;
    Vec2 velocity;
    int size;
    Blob();
    Blob(float posX, float posY, float velX, float velY, int aSize);
};

class Player : public Blob{
public:
    float direction;
    int iceFuel;
    int rechargingFuel;
    int orbitDrawSteps;
    Player();
};
