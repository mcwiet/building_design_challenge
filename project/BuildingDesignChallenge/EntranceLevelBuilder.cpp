#include "EntranceLevelBuilder.h"
#include "LevelBuilder.h"

namespace BuildingChallenge {
	namespace Builders {
		std::shared_ptr<Level> EntranceLevelBuilder::Build(const std::shared_ptr<const Blueprints::EntranceLevelBlueprint> bp) {
			auto level = std::make_shared<Level>();
			Build(bp, level);
			return level;
		}

		void EntranceLevelBuilder::Build(const std::shared_ptr<const Blueprints::EntranceLevelBlueprint> bp, const std::shared_ptr<Level> level) {
			for (unsigned i = 0; i < bp->Entrances.second; ++i) {
				level->AddOn(bp->Entrances.first);
			}
			LevelBuilder().Build(bp, level);
		}
	}
}