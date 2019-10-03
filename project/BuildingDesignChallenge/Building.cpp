#include "Building.h"

namespace BuildingChallenge {
	Building::Building() :
		Buildable("Building") {};

	void Building::OnAfterBuild() {
		for (auto level : levels_) {
			level.get().Build();
		}
	}

	void Building::AddLevel(Level& level) {
		levels_.push_back(std::reference_wrapper<Level>(level));
	}
}