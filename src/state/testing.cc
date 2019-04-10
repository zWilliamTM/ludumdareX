#include "testing.h"
#include "screen.h"
#include "keyboard.h"

using namespace graphics;
namespace state
{
	Testing::Testing()
	{
		x = 0;
		y = 0;
		dir_x = 0;
	}

	Testing::~Testing()
	{
	}

	void Testing::release()
	{
	}

	void Testing::load()
	{
		sheet = std::make_unique<SpriteSheet>("res/sheet_test.png", 64, 64);
	}

	void Testing::handleEvent(InputListener *il)
	{
		Keyboard *kb = dynamic_cast<Keyboard*>(il);
		if (kb->left) dir_x = -1;
		else if (kb->right) dir_x = 1;
	}

	void Testing::update(float dt)
	{
		if (dir_x < 0) --x;
		else if (dir_x > 0) ++x;
		dir_x = 0;
	}

	void Testing::render(Screen *screen)
	{
		screen->render(sheet.get(), x, y, true);
	}
}
