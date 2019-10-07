#include "LevelBuilder.h"

namespace BuildingChallenge {
	namespace Builders {
		std::shared_ptr<Level> LevelBuilder::Build(const std::shared_ptr<const Blueprints::LevelBlueprint> bp) {
			auto level = std::make_shared<Level>();
			Build(bp, level);
			return level;
		}

		void LevelBuilder::Build(const std::shared_ptr<const Blueprints::LevelBlueprint> bp, const std::shared_ptr<Level> level) {
			for (unsigned i = 0; i < bp->Windows.second; ++i) {
				level->AddOn(bp->Windows.first);
			}
			for (unsigned i = 0; i < bp->Rooms.second; ++i) {
				level->AddOn(bp->Rooms.first);
			}
			level->Build();
		}
	}
}