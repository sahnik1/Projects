#ifndef PARTICLE_2D_H
#define PARTICLE_2D_H

#include <math.h>
#include "mathLib2D.h"
#include <tuple>

struct color{
    float r;
    float g;
    float b;
};

class Particle{

public:
    Particle();
    Particle(Point2D position, int size, Vec2D direction, float range, float speed, color c);
    Point2D position;
    int size;
    Vec2D direction;
    float range;
    float speed;
    color colour;
};

#endif