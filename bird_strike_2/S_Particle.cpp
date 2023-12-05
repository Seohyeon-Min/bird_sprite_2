#include "raylib.h"
#include <vector>
#include "H_Particle.h"

std::vector<Particle*> Particle::particles = { };

const Color outline_color{ 255,255,255,200 };

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

void Particle::update_all() {

    for (int i = 0; i < particles.size(); i++) {
        Particle* particle = particles[i];

        particle->position.x += particle->speed.x;
        particle->position.y += particle->speed.y;
        if (particle->size > 0) {
            particle->size -= 0.25;
        }
        else {
            particle->size == 0;
        }



        //DrawCircle(particle->position.x, particle->position.y, particle->size, particle->color);
        DrawRectangle(particle->position.x, particle->position.y, particle->size, particle->size, particle->color);
        DrawRectangleLines(particle->position.x, particle->position.y, particle->size, particle->size, outline_color);
    }


    for (int i = particles.size() - 1; i >= 0; i--) {
        Particle* particle = particles[i];

        if (particle->position.x < 0 || particle->position.x > GetScreenWidth() ||
            particle->position.y < 0 || particle->position.y > GetScreenHeight()) {
            particles.erase(particles.begin() + i);
        }
    }
}