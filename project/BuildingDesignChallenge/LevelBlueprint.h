#pragma once
#include "Windows.h"

namespace BuildingChallenge {
	namespace Blueprints {
		struct LevelBlueprint {
			std::pair<std::shared_ptr<LevelAddons::Windows::Window>, unsigned> Windows;
		};
	}
}