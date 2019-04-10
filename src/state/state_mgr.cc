#include "state_mgr.h"
#include "screen.h"
#include "keyboard.h"

#include "loading.h"
#include "menu.h"
#include "game.h"
#include "testing.h"

using namespace graphics;
using namespace input;
namespace state
{
	StateManager::StateManager(StateID state)
	{
		change(state);
	}

	StateManager::~StateManager()
	{
		current->release();
		delete current;
	}

	void StateManager::handleEvent(InputListener *il)
	{
		current->handleEvent(il);
	}

	void StateManager::update(float dt)
	{
		current->update(dt);
	}

	void StateManager::change(StateID state)
	{
		if (current) if (curr_state != state) { release_state(current); delete current; };
		switch (state)
		{
			case LOADING: { current = new Loading(); } break;
			case MENU: { current = new Menu(); } break;
			case GAME: { current = new Game(); } break;
			case PAUSE: {} break;
			case TESTING: { current = new Testing(); } break;
		}
		curr_state = state;
		load_state(current);
	}

	void StateManager::release_state(State *state)
	{
		is_ready = false;
		current->release();
	}

	void StateManager::load_state(State *state)
	{
		current->load();
		is_ready = true;
	}

	void StateManager::render(Screen *screen)
	{
		if (is_ready) current->render(screen);
	}
}
