#include "Level.h"
#include <iostream>

namespace BuildingChallenge {
	Level::Level() :
		Buildable("Level") {}
	void Level::AddOn(std::shared_ptr<LevelAddons::LevelAddon> addon) {
		addons_.push_back(addon);
	}
	void Level::OnAfterBuild() {
		for (auto addon : addons_) {
			addon->Build();
		}
	}
}