#include "LevelBuilder.h"

namespace BuildingChallenge {
	namespace Builders {
		std::shared_ptr<Level> LevelBuilder::Build(const std::shared_ptr<const Blueprints::LevelBlueprint> bp) {
			auto level = std::make_shared<Level>();
			for (unsigned i = 0; i < bp->Windows.second; ++i) {
				level->AddOn(bp->Windows.first);
			}
			level->Build();
			return level;
		}
	}
}