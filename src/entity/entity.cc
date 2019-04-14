#include "entity.h"

namespace entity
{
    Entity::Entity()
    {
    }

    Entity::Entity(int x, int y, Sprite *sprite)
        : x(x), y(y), sprite(sprite)
    {
    }

    Entity::~Entity()
    {
    }

    void Entity::render(Screen *screen)
    {
        if (sprite != nullptr) 
            screen->render(sprite, x, y, true);
    }

    void Entity::remove() { removed = true; }

    int Entity::getX() { return x; }
    int Entity::getY() { return y; }    
    Sprite *Entity::getSprite() { return sprite; }
    bool Entity::isRemoved() { return removed; }
}
