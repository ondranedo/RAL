#pragma once

namespace RAL {
	class BaseGame {
	public:
		BaseGame();
		virtual ~BaseGame();
		virtual void call() = 0;
	};

	// TODO: Custom class
	extern BaseGame* createBaseGame();
}