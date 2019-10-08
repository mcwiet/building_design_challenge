#include "EntranceLevelBuilder.h"
#include "LevelBuilder.h"

namespace BuildingChallenge {
	namespace Builders {
		Level EntranceLevelBuilder::Build(const Blueprints::EntranceLevelBlueprint& bp) {
			Level level;
			Build(bp, level);
			return level;
		}

		void EntranceLevelBuilder::Build(const Blueprints::EntranceLevelBlueprint& bp, Level& level) {
			for (unsigned i = 0; i < bp.Entrances.Amount; ++i) {
				level.AddOn(bp.Entrances.Factory.lock()->Create());
			}
			LevelBuilder().Build(bp, level);
		}
	}
}