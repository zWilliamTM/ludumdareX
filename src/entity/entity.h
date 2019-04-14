#pragma once
#ifndef _ENTITY_H
#define _ENTITY_H

#include <tuple>

namespace graphics { class Screen; class Sprite; }
using namespace graphics;

namespace entity 
{
    class Entity 
    {
    public:
        Entity();
        Entity(int x, int y, Sprite *sprite);
        ~Entity();

        virtual void update() = 0;
        virtual void render(Screen *screen);
        void remove();

        int getX();
        int getY();

        Sprite *getSprite();

        bool isRemoved();

        // void init()

    protected:
        int x;
        int y;

        Sprite *sprite;
        // Level *level;

    private:
        bool removed;
    };
}

#endif 

