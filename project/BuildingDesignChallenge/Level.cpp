#include "Level.h"
#include <iostream>

namespace BuildingChallenge {
	Level::Level() :
		Buildable("Level") {}
	Level::Level(const std::string& name) :
		Buildable(name) {}
}