#include "Building.h"

namespace BuildingChallenge {
	Building::Building() :
		Buildable("Building") {};

	void Building::OnBuild() {
		for (auto level : levels_) {
			level.get().Build();
		}
	}

	void Building::AddLevel(Level& level) {
		std::reference_wrapper<Level>y(level);
		levels_.push_back(y);
	}
}