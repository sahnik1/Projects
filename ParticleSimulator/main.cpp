#ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
#else
#  include <GL/gl.h>
#  include <GL/glu.h>
#  include <GL/freeglut.h>
#endif

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include "particle.h"
#include "mathLib2D.h"

using namespace std;

int gWidth = 720; // Width of Initial Size Window
int gHeight = 720; // Height of Initial Size Window
float posx = 0.0; // X Coordinate of Mouse Position
float posy = 0.0; // Y Coordinate of Mouse Position
bool pause = false; // Captures State, ie if Simulation Paused or Playing
vector<Particle> allPars; // Vector of all Particles in Program
int lmbpressed = GLUT_UP; // Captures State, ie if Left Mouse Btn Pressed
int rmbpressed = GLUT_UP; // Captures State, ie if Right Mouse Btn Pressed
int parnum = 5000; // Total Number of Particles Generated
bool christmas = false; // Captures State, ie if Christmas Mode is ON
int tkey = 0; // Captures How many Times 't' key was pressed on keyboard
int bkey = 0; // Captures How many Times 'b' key was pressed on keyboard

// Updates Collide/Simulation Function Controlled by 't' key
void updateCollide(){
    srand(time(0));
    for (size_t i = 0; i < allPars.size(); i++){
        float speed = allPars[i].speed + 0.02;
        allPars[i].direction = Vec2D().createVector(allPars[i].position, Point2D());
        Vec2D tempvec = allPars[i].direction;
        allPars[i].position.mX += (speed)*(tempvec.mX);
        allPars[i].position.mY += (speed)*(tempvec.mY);
    }
}

// Launches User Towards Particles Illusion when 't' Pressed Twice
void explode(){
    for (size_t i = 0; i < allPars.size(); i++){
        float speed = 0.1;
             allPars[i].direction = Vec2D().createVector(Point2D(),allPars[i].position);
            Vec2D tempvec = allPars[i].direction;
            allPars[i].position.mX += (speed)*(tempvec.mX);
            allPars[i].position.mY += (speed)*(tempvec.mY);
    }
}

// Bounces/Moves Particles in Random Formations when 'b' key Pressed Once
void bounce(){
    for (size_t i = 0; i < allPars.size(); i++){
        Point2D tempoint = Point2D(posx, posy);
        float speed = allPars[i].speed;
        Vec2D tempvec = allPars[i].direction;
        if(allPars[i].position.distanceTo(tempoint) < 0.01){
            tempvec = (Vec2D().createVector(tempoint, allPars[i].position)).normalize();
            speed = 0.05;
            allPars[i].position.mX += (speed)*(tempvec.mX);
            allPars[i].position.mY += (speed)*(tempvec.mY);
        }
        allPars[i].position.mX += (speed)*(tempvec.mX);
        allPars[i].position.mY += (speed)*(tempvec.mY);
    }
}

// Draws All Particles in allPars Vector to Screen
void drawParticle(){
    if (tkey == 1 && !pause)
        updateCollide();
    else if (tkey == 2 && !pause)
        explode();
    else if (bkey == 1 && !pause)
        bounce();
    glClear(GL_COLOR_BUFFER_BIT);
    srand(time(0));
    for (size_t i = 0; i < allPars.size(); i++){
        Particle dot = allPars[i];
        color c = allPars[i].colour;
        if (christmas){
        c.r = ((float)rand()) / ((float)RAND_MAX);
        c.g = ((float)rand()) / ((float)RAND_MAX);
        c.b = ((float)rand()) / ((float)RAND_MAX);
        }
        glPointSize(dot.size);
        glBegin(GL_POINTS);
            glColor3f(c.r, c.g, c.b);       
            glVertex2f(dot.position.mX, dot.position.mY);
        glEnd();
    }
    //glFlush();
    glutSwapBuffers();
}

// Generates Initial Particles up to 'parnum'
void genParticle(){
    srand(time(0));
    allPars.clear();
    for (int i=0; i<parnum; i++){
        color c;
        c.r = ((float)rand()) / ((float)RAND_MAX);
        c.g = ((float)rand()) / ((float)RAND_MAX);
        c.b = ((float)rand()) / ((float)RAND_MAX);
        double x = ((float)rand()) / ((float)RAND_MAX)*2.0 - 1.0;
        double y = ((float)rand()) / ((float)RAND_MAX)*2.0 - 1.0;
        float range = ((float)rand()/(float)RAND_MAX);
        float speed = ((float)rand()/(float)RAND_MAX) / 70;
        int size = (rand()%5) + 1;
        Point2D pos = Point2D(x,y);
        Particle temp = Particle(pos, size, Vec2D(), range, speed, c);
        allPars.push_back(temp);
    }
}

// Adds a Particle to the Vector allPars at Mouse Position when 'a' key is Pressed
void addPar(){
    srand(time(0));
    color c;
    c.r = ((float)rand()) / ((float)RAND_MAX);
    c.g = ((float)rand()) / ((float)RAND_MAX);
    c.b = ((float)rand()) / ((float)RAND_MAX);
    float range = ((float)rand()/(float)RAND_MAX);
    float speed = ((float)rand()/(float)RAND_MAX) / 50;
    int size = (rand()%5) + 1;
    Point2D pos = Point2D(posx,posy);
    Particle temp = Particle(pos, size, Vec2D(), range, speed, c);
    allPars.push_back(temp);
}

// Deletes Particle Closest to Mouse Position when 'd' key is Pressed
void delPar(){
    size_t min = 0;
    for (size_t i = 0; i < allPars.size(); i++){
        Point2D currmousepos = Point2D(posx, posy);
        float currposdist = allPars[i].position.distanceTo(currmousepos);
        if (currposdist <= allPars[min].position.distanceTo(currmousepos))
            min = i;
    }
    allPars.erase(allPars.begin()+min);
}

// Changes Range Based on Which Key Pressed of '+' or '='
void changeRange(int stat){
    for (size_t i = 0; i < allPars.size(); i++){
        if(stat == 0){
            allPars[i].range += 0.01;
        }
        if (stat == 1)
        {
            allPars[i].range -= 0.01;
        }
    }
}

// Changes Range Based on Which Key Pressed of up or down
void changeSpeed(int btn){
    for (size_t i = 0; i < allPars.size(); i++){
        if(btn == GLUT_KEY_UP){
            allPars[i].speed += 0.002;
        }
        if (btn == GLUT_KEY_DOWN && (allPars[i].speed - 0.001) > 0)
        {
            allPars[i].speed -= 0.001;
        }
    }
}

// Generates the X and Y Coordinates for Making Patrick
void genPatrick(){
    float a = 0.5;
    float b = 0.3;
    float d = 0.75;
    srand(time(0));
    float k = a - b;
    float m = (a - b) / b;
    for (size_t i = 0; i < allPars.size(); i++){
        float t = ((float)rand()/(float)RAND_MAX)*(6.0*3.1415);
        float x = k * cos(t) + d * cos(m * t);
        float y = k * sin(t) - d * sin(m * t);
        allPars[i].position.mX = x;
        allPars[i].position.mY = y;
    }
}

// Generates the X and Y Coordinates for Making a Flower
void genFlower(){
    float a = -0.03;
    float b = 1.0;
    float d = 5.4;
    srand(time(0));
    float k = a - b;
    float m = (a - b) / b;
    for (size_t i = 0; i < allPars.size(); i++){
        float t = ((float)rand()/(float)RAND_MAX)*(31.4);
        float x = (a + b*sin(d*t)) * cos(t);
        float y = (a + b*sin(d*t)) * sin(t);
        allPars[i].position.mX = x;
        allPars[i].position.mY = y;
    }
}

// Updates Particle Positions to Follow or Repel Cursor
void update(int btn){
    for (size_t i = 0; i < allPars.size(); i++){
        Point2D tempoint = Point2D(posx, posy);
        if(allPars[i].range > allPars[i].position.distanceTo(tempoint)){
            Vec2D tempvec = (Vec2D().createVector(allPars[i].position, tempoint)).normalize();
            float speed = allPars[i].speed;
            if(btn == GLUT_RIGHT_BUTTON){
                speed *= -1.0;
            }
            allPars[i].position.mX += (speed)*(tempvec.mX);
            allPars[i].position.mY += (speed)*(tempvec.mY);
        }
    }
}

// Generates Intial Vectors from Random Values for Particles
void genCollide(){
    srand(time(0));
    for (size_t i = 0; i < allPars.size(); i++){
        double x = ((float)rand()) / ((float)RAND_MAX)*2.0 - 1.0;
        double y = ((float)rand()) / ((float)RAND_MAX)*2.0 - 1.0;
        Point2D tempoint = Point2D(x, y);
        allPars[i].direction = (Vec2D().createVector(allPars[i].position, tempoint)).normalize();
    }
}

// Checks Which of Normal Keys are Pressed (ie any letter key)
void handleKeyboard(unsigned char key, int _x, int _y) {
    if (!pause){
        if (key == 'a')
            addPar();
        if (key == 'd')
            delPar();
        if (key == 'r'){
            allPars.clear();
            genParticle();
            genCollide();
        }
        if (key == '=' || key == '+')
            changeRange(0);
        if (key == '-')
            changeRange(1);
        if (key == 'p')
            genPatrick();
        if (key == 'f')
            genFlower();
        if (key == 'c')
            christmas = !christmas;
        if (key == 't' && tkey == 0)
            tkey += 1;
        else if (key == 't' && tkey == 1){
            tkey += 1;
        }
        else
            tkey = 0;
        if (key == 'b' && bkey == 0)
            bkey += 1;
        else
            bkey = 0;
        
    }
    if (key == 'q' || key == 27)
            exit(0);
    if (key == ' ')
        pause = !pause;
}

// Checks if any Special Key Pressed (ie UP or DOWN Buttons)
void specialKeyFunc(int key, int x, int y){
    if (!pause){
        if (key == GLUT_KEY_UP)
            changeSpeed(GLUT_KEY_UP);
        if (key == GLUT_KEY_DOWN)
            changeSpeed(GLUT_KEY_DOWN);
    }
}

// Handles Click and Drag Events (ie Calls Functions Based on Click)
void handleMouse(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && !pause){
        lmbpressed = GLUT_DOWN;
        update(GLUT_LEFT_BUTTON);
    }
    else if (state == GLUT_UP){
        lmbpressed = GLUT_UP;
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && !pause){
        rmbpressed = GLUT_DOWN;
        update(GLUT_RIGHT_BUTTON);
    }
    else if (state == GLUT_UP){
        rmbpressed = GLUT_UP;
    }
    
}

// Buttery Smooth 60 FPS
void FPS(int val){
    glutPostRedisplay();
    glutTimerFunc(17, FPS, 0); // 1sec = 1000, 60fps = 1000/60 = ~17
}

// Display Function Called in glutDisplayFunc
void display(void){
    if (!pause){
        drawParticle();
    }
}

// Passive Mouse Function for Getting Cursor Coordinates
void mousePos(int x, int y){
    float mx = x;
    float my = y;
    posx = (mx/(gWidth/2.0) - 1.0);
    posy = -(my/(gHeight/2.0) - 1.0);
    if (lmbpressed == GLUT_DOWN && !pause)
        update(GLUT_LEFT_BUTTON);
    else if (rmbpressed == GLUT_DOWN && !pause)
        update(GLUT_RIGHT_BUTTON);
}

// Reshapes Window with w & h
void reshape(int w, int h){
    gWidth = w;
    gHeight = h;

    glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, 0, 0, 0);
    glMatrixMode(GL_MODELVIEW);
        glViewport(0, 0, w, h);
}

void callBackInit(){
    //glutIdleFunc(idle);
    glutDisplayFunc(display);	//registers "display" as the display callback function
    glutKeyboardFunc(handleKeyboard);
    glutSpecialFunc(specialKeyFunc);
    glutPassiveMotionFunc(mousePos);
    glutMotionFunc(mousePos);
    glutMouseFunc(handleMouse);
    glutTimerFunc(0, FPS, 0);
    glutReshapeFunc(reshape);
}

int main(int argc, char** argv) {
    cout << "-------WELCOME TO MY SIMULATION!-------" << endl;
    cout << "Controls: " << endl;
    cout << "   q / ESC --- EXIT THE PROGRAM" << endl << endl;
    cout << "   a --------- ADD PARTICLE AT CURSOR POSITION" << endl << endl;
    cout << "   d --------- REMOVE PARTICLE CLOSEST TO CURSOR POSITION" << endl << endl;
    cout << "   r --------- RESET PARTICLES AND WIPE SCREEN" << endl << endl;
    cout << "   = / + ----- INCREASES RANGE OF ALL PARTICLES" << endl << endl;
    cout << "   '-' ------- MINUS KEY, DECREASES RANGE OF ALL PARTICLES" << endl << endl;
    cout << "   up  ------- UP ARROW KEY, INCREASES SPEED OF ALL PARTICLES" << endl << endl;
    cout << "   down  ----- DOWN ARROW KEY, DECREASES SPEED OF ALL PARTICLES" << endl << endl;
    cout << "   SPACEBAR -- PAUSES SIMULATION ON SCREEN" << endl << endl;
    cout << "   LMB ------- LMB AND MOVING MOUSE PULLS PARTICLES IN TOWARDS CURSOR" << endl << endl;
    cout << "   RMB ------- RMB AND MOVING MOUSE REPELS PARTICLES AWAY FROM CURSOR" << endl << endl;
    cout << "   t --------- **EXTRA FEATURE** BLASTOFF (OUTER SPACE)" << endl;
    cout << "               PRESS t ONCE: USER MOVES GETS PULLED BACK FOR LAUNCH" << endl;
    cout << "               PRESS t 2ND TIME: USER MOVES GETS LAUNCHED INTO SCREEN" << endl;
    cout << "               PRESS t 3RD TIME: EXITS BLASTOFF MODE" << endl << endl;
    cout << "   b --------- **EXTRA FEATURE** DISINTEGRATION OF PARTICLES" << endl;
    cout << "               PRESS t ONCE: PARTICLES START TO MOVE" << endl;
    cout << "               PRESS t 2ND TIME: EXITS DISINTEGRATION MODE" << endl << endl;
    cout << "   c --------- **EXTRA FEATURE** CHRISTMAS LIGHTS, TOGGLES IT ON & OFF" << endl << endl;
    cout << "   f --------- **EXTRA FEATURE** DRAWS A FLOWER ON THE SCREEN" << endl;
    cout << "               USING PARAMETRIC EQUATIONS" << endl << endl;
    cout << "   p --------- **EXTRA FEATURE** DRAWS PATRICK ON THE SCREEN" << endl;
    cout << "               USING PARAMETRIC EQUATIONS" << endl << endl;
    cout << "-----SCROLL UP TO SEE ALL CONTROLS-----" << endl;
    genParticle();
    genCollide();
    glutInit(&argc, argv);

    glutInitWindowSize(gWidth,gHeight);
    glutCreateWindow("DEMO");

    callBackInit();
    glutMainLoop();
    return 0;
}