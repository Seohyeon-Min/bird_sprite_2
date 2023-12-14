/* GAM100

Seohyeon Min
Seokhwa Hong

All content © 2023 DigiPen (USA) Corporation, all rights reserved. */


#include "raylib.h"
#include <vector>

#ifndef PARTICLE_H
#define PARTICLE_H

class Particle {
public:
    static void make_particle(Vector2 position);
    static void update_particle();
    static std::vector<Particle*> particles;

private:
    Vector2 position;
    Vector2 speed;
    float size;
    Color color;
};

class Effect {
public:
    static void make_effect();
    static void make_effect2();
    static void update_effect();
    static std::vector<Effect*> effects;

private:
    Vector2 postion;
    float speed;
    float size;
    Color color;
};


class Light {
public:
    static void make_light();
    static void update_light();
    static std::vector<Light*> lights;

private:
    int life = 120;
    Vector2 postion;
    float size;
    Color color;
};


#endif PARTICLE_H


