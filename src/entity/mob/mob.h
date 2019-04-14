#pragma once
#ifndef _MOB_H
#define _MOB_H

#include "entity.h"

#include <string>

namespace graphics { class SpriteSheet; }
using namespace graphics;

namespace entity::mob
{
    class Mob : public Entity
    {
    protected:
        Mob(const std::string& name);

    public:
        void move(double xa, double ya);

        virtual void update() = 0;
        virtual void render(Screen *screen) = 0;

    protected:
        void shoot(int x, int y, double dir);

    private:
        int abs(double value);
        bool collision(double xa, double ya);
    };
}

#endif 

