#pragma once
#include "LevelBlueprint.h"
#include "Entrances.h"

namespace BuildingChallenge {
	namespace Blueprints {
		struct EntranceLevelBlueprint : public LevelBlueprint {
			Blueprint<LevelAddons::Entrances::Entrance> Entrances;
		};
	}
}
