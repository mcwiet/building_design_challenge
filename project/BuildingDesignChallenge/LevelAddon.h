#pragma once
#include "Level.h"
#include <memory>
namespace BuildingChallenge {
	class LevelAddon : public Buildable {
	protected:
		LevelAddon(const std::string& name) : Buildable(name) {}
	};
}
