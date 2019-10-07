#pragma once
#include "Windows.h"
#include "Rooms.h"

namespace BuildingChallenge {
	namespace Blueprints {
		struct LevelBlueprint {
			std::pair<std::shared_ptr<LevelAddons::Windows::Window>, unsigned> Windows;
			std::pair<std::shared_ptr<LevelAddons::Rooms::Room>, unsigned> Rooms;
		};
	}
}