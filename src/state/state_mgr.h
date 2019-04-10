#pragma once
#ifndef _STATE_MGR_H
#define _STATE_MGR_H

// Forward
namespace graphics { class Screen; }
using namespace graphics;
namespace input { class InputListener; }
using namespace input;

namespace state
{
	// Forward
	class State;

	// Enums
	enum StateID
	{
		LOADING=0,
		MENU,
		GAME,
		PAUSE,

		TESTING,
	};

	class StateManager
	{
	public:
		StateManager(StateID state);
		~StateManager();

		void handleEvent(InputListener *il);
		void update(float dt);
		void change(StateID state);
		void render(Screen *screen);

	private:
		void release_state(State *state);
		void load_state(State *state);

	private:
		bool is_ready;
		StateID curr_state;
		State *current;
	};
}

#endif
