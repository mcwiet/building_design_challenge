#include "Building.h"

namespace BuildingChallenge {
	Building::Building() :
		Buildable("Building") {};

	void Building::OnAfterBuild() {
		for (auto level : levels_) {
			level->Build();
		}
	}

	void Building::AddLevel(std::shared_ptr<Level> level) {
		levels_.push_back(std::shared_ptr<Level>(level));
	}
}