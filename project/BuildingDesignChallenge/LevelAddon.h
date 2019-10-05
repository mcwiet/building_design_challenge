#pragma once
#include "Buildable.h"
#include <string>
namespace BuildingChallenge {
	namespace LevelAddons {
		class LevelAddon : public Buildable {
		protected:
			LevelAddon(const std::string& name) : Buildable(name) {}
		};
	}
}
