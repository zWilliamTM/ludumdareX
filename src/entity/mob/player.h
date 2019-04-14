#pragma once
#ifndef _PLAYER_H
#define _PLAYER_H

#include "mob.h"

namespace entity::mob
{
    class Player : public Mob
    {
    public:
        Player();
        ~Player();

        virtual void update(float);
        virtual void render(Screen *screen);

    private:
        Sprite *sprite;
    };
}

#endif

