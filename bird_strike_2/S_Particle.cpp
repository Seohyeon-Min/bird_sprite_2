#include "raylib.h"
#include <vector>
#include "H_Particle.h"
#include "iostream"

std::vector<Particle*> Particle::particles = { };
std::vector<Effect*> Effect::effects = { };

const Color outline_color{ 255,255,255,200 };
const Color effect_color{ 0,0,0,100 };

int x = 10;
int frameX = x;

void Particle::make_particle(Vector2 position) {
    for (int i = 0; i < 20; i++) {
        Particle* newParticle = new Particle;
        newParticle->position = { position.x, position.y };
        newParticle->speed = { (float)(-2 + rand() % 5),(float)(-2 + rand() % 5) };
        newParticle->size = { float(5 + rand() % 10) };
        newParticle->color = { BLACK };
        particles.push_back(newParticle);
    }
}

void Effect::make_effect() { 
    if (frameX > 0) {
        frameX--;
    }
    else {
        frameX = x;
        Effect* newEffect = new Effect;
        newEffect->postion = { float(GetRandomValue(-5,GetScreenWidth())),float(GetScreenHeight()) };
        newEffect->speed = { float(1 + rand() % 4) / 6 };
        newEffect->size = { float(5 + rand() % 10) };
        newEffect->color = effect_color;
        effects.push_back(newEffect);
    }
        
}

void Particle::update_particle() {
    for (int i = 0; i < particles.size(); i++) {
        Particle* particle = particles[i];

        particle->position.x += particle->speed.x;
        particle->position.y += particle->speed.y;
        if (particle->size > 0) {
            particle->size -= 0.25;
        }
        else {
            particle->size = 0;
        }


        //DrawCircle(particle->position.x, particle->position.y, particle->size, particle->color);
        DrawRectangle(particle->position.x, particle->position.y, particle->size, particle->size, particle->color);
        DrawRectangleLines(particle->position.x, particle->position.y, particle->size, particle->size, outline_color);
    }


    for (int i = particles.size() - 1; i >= 0; i--) {
        Particle* particle = particles[i];

        if (particle->position.x < 0 || particle->position.x > GetScreenWidth() ||
            particle->position.y < 0 || particle->position.y > GetScreenHeight() || particle->size <= 0) {
            particles.erase(particles.begin() + i);
        }
    }
}

void Effect::update_effect() {
    for (int i = 0; i < effects.size(); i++) {
        Effect* effect = effects[i];

        effect->postion.y -= effect->speed;
        if (effect->size > 0) {
            effect->size -= 0.02;
        }
        else {
            effect->size = 0;
        }

        DrawRectangle(effect->postion.x, effect->postion.y, effect->size, effect->size, effect->color);
    }
    for (int i = effects.size() - 1; i >= 0; i--) {
        Effect* effect = effects[i];

        if (effect->size < 0) {
            effects.erase(effects.begin() + 1);
        }
    }
}