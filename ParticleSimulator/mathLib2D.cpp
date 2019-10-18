#include <math.h>
#include "mathLib2D.h"

// Implement functions here.

// Don't write a main function, do that in main.cpp

Point2D::Point2D(){
    this->mX = 0;
    this->mY = 0;
}

Point2D::Point2D(float inX, float inY){
    this->mX = inX;
    this->mY = inY;
}

float Point2D::distanceTo(Point2D other){
    float diffX = (other.mX - this->mX);
    float diffY = (other.mY - this->mY);

    return (sqrt(pow(diffX,2) + pow(diffY,2)));
}

float Point2D::fastDistanceTo(Point2D other){
    float diffX = (other.mX - this->mX);
    float diffY = (other.mY - this->mY);

    return ((pow(diffX,2) + pow(diffY,2)));
}

/*-------------VEC2D STARTS-------------*/

Vec2D::Vec2D(){
    this->mX = 0;
    this->mY = 0;
}

Vec2D::Vec2D(float inX, float inY){
    this->mX = inX;
    this->mY = inY;
}

float Vec2D::length(){
    return sqrt(pow((this->mX),2) + pow((this->mY),2));
}

Vec2D Vec2D::normalize(){
    float leng = this->length();
    Vec2D tempVec = Vec2D( (this->mX)/leng, (this->mY)/leng);
    return tempVec;
}

Vec2D Vec2D::multiply(float scalar){
    Vec2D tempVec = Vec2D( (this->mX)*scalar, (this->mY)*scalar);
    return tempVec;
}

Point2D Vec2D::movePoint(Point2D source){
    Point2D tempPoint = Point2D(source.mX + this->mX, source.mY + this->mY);
    return tempPoint;
}

Vec2D Vec2D::createVector(Point2D p1, Point2D p2){
    Vec2D tempVec = Vec2D(p2.mX - p1.mX, p2.mY - p1.mY);
    return tempVec;
}