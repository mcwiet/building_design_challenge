#pragma once
#include "LevelBlueprint.h"
#include "Entrances.h"

namespace BuildingChallenge {
	namespace Blueprints {
		struct EntranceLevelBlueprint : public LevelBlueprint {
			std::pair<std::shared_ptr<LevelAddons::Entrances::Entrance>, unsigned> Entrances;
		};
	}
}
