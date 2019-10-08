#pragma once
#include "LevelBlueprint.h"
#include "Entrance.h"

namespace BuildingChallenge {
	namespace Blueprints {
		struct EntranceLevelBlueprint : public LevelBlueprint {
			Blueprint<LevelAddons::Entrance> Entrances;
		};
	}
}
