#include <math.h>
#include <iostream>
#include "particle.h"

using namespace std;

Particle::Particle(){
    color temp;
    this->position = Point2D();
    this->size = 0;
    this->direction = Vec2D();
    this->range = 0;
    this->speed = 1;
    this->colour = temp;
}

Particle::Particle(Point2D position, int size, Vec2D direction, float range, float speed, color c){
    this->position = position;
    this->size = size;
    this->direction = direction;
    this->range = range;
    this->speed = speed;
    this->colour = c;
}
