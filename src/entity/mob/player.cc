#include "player.h"
#include "screen.h"

namespace entity::mob
{
    Player::Player()
    {
    }

    Player::~Player()
    {
    }

    void Player::update(float dt)
    {
    }

    void Player::render(Screen *screen)
    {
        screen->render(sprite);
    }
}

