#include "EntranceLevelBuilder.h"
#include "LevelBuilder.h"

namespace BuildingChallenge {
	namespace Builders {
		std::shared_ptr<Level> EntranceLevelBuilder::Build(const std::shared_ptr<const Blueprints::EntranceLevelBlueprint> bp) {
			auto level = LevelBuilder().Build(bp);
			for (unsigned i = 0; i < bp->Entrances.second; ++i) {
				level->AddOn(bp->Entrances.first);
			}
			level->Build();
			return level;
		}
	}
}