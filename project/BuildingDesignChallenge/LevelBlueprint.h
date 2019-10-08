#pragma once
#include "Windows.h"
#include "Rooms.h"
#include "Blueprint.h"

namespace BuildingChallenge {
	namespace Blueprints {
		struct LevelBlueprint {
			LevelBlueprint() = default;
			virtual ~LevelBlueprint() = default;
			Blueprint<LevelAddons::Windows::Window> Windows;
			Blueprint<LevelAddons::Rooms::Room> Rooms;
		};
	}
}