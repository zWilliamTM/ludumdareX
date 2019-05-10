#pragma once
#ifndef _LEVEL_H
#define _LEVEL_H

#include <string>

#include "layer.h"

using namespace graphics::layers;

namespace level
{
    class Level
    {
    public:
        Level(int width, int height);
        Level(const std::string& path);

        void update();
        void onEvent(const Event& event);
        bool tileCollision(int x, int y, int size, int xOffset, int yOffset);

    protected:
        void generateLevel();
        virtual void loadLevel(const std::string& path) = 0;
        virtual void initNpc() = 0;

    private:
        void remove();
        void time();

    };
}

#endif /* end of include guard:  */
