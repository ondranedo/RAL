#define RAL_DEBUG
#include <RAL/RAL.h>
class Demo : public RAL::BaseGame {

public:
	void call() override
	{	
		RAL_LOG_INFO("Calling into demo game");
	}
};

// TODO: Wrap it in a class
RAL::BaseGame* RAL::createBaseGame() {
	return new Demo;
}
