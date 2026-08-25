#pragma once

class GameTime {
public:
	static float delta;

	static void updateDelta(float newDelta) {
		delta = newDelta;
	}
};
