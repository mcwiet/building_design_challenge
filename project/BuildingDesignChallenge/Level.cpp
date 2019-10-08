#include "Level.h"
#include <iostream>

namespace BuildingChallenge {
	Level::Level() :
		Buildable("Level") {}

	void Level::AddOn(std::unique_ptr<LevelAddons::LevelAddon> addon) {
		addons_.push_back(std::move(addon));
	}

	void Level::OnAfterBuild() {
		for (auto& addon : addons_) {
			addon->Build();
		}
	}
}