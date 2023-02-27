#include "Engine.h"

#include <iostream>
#include <exception>

int main(){
	auto ral = new RAL::Engine;

	ral->init();
	ral->init();

	ral->run();

	ral->release();
	
	delete ral;

	return 0;
}