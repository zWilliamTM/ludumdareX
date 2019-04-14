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

	void Testing::handleEvent()
	{
	}

	void Testing::update(float dt)
	{
	}

	void Testing::render(Screen *screen)
	{
		screen->render(sheet.get(), x, y, true);
	}
}
