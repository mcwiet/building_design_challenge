#include "Building.h"

namespace BuildingChallenge {
	Building::Building() :
		Buildable("Building") {};

	void Building::OnAfterBuild() {
		for (auto& level : levels_) {
			level->Build();
		}
	}

	void Building::AddLevel(std::unique_ptr<Level> level) {
		levels_.push_back(std::move(level));
	}
}