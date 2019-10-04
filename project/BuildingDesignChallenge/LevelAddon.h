#pragma once
#include "Level.h"
#include <memory>
namespace BuildingChallenge {
	namespace Addons {
		class LevelAddon : public Buildable {
		protected:
			LevelAddon(const std::string& name) : Buildable(name) {}
		};
	}
}
