#pragma once
#include "Window.h"
#include "Room.h"
#include "Blueprint.h"

namespace BuildingChallenge {
	namespace Blueprints {
		struct LevelBlueprint {
			LevelBlueprint() = default;
			virtual ~LevelBlueprint() = default;
			Blueprint<LevelAddons::Window> Windows;
			Blueprint<LevelAddons::Room> Rooms;
		};
	}
}