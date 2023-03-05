#include "application.h"

int main(int argc, char** argv)
{	
	// TODO: memory class
	auto engine = new RAL::Application(argc, argv);

	engine->run();

	delete engine;
}