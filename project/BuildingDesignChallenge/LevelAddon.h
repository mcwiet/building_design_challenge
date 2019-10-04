#pragma once
#include "Level.h"
#include <memory>
namespace BuildingChallenge {
	namespace LevelAddons {
		class LevelAddon : public Buildable {
		protected:
			LevelAddon(const std::string& name) : Buildable(name) {}
		};
	}
}
