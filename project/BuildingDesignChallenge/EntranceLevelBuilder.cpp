#include "EntranceLevelBuilder.h"
#include "LevelBuilder.h"
#include "Clone.h"

namespace BuildingChallenge {
	namespace Builders {
		Level EntranceLevelBuilder::Build(const Blueprints::EntranceLevelBlueprint& bp) {
			Level level;
			Build(bp, level);
			return level;
		}

		void EntranceLevelBuilder::Build(const Blueprints::EntranceLevelBlueprint& bp, Level& level) {
			for (unsigned i = 0; i < bp.Entrances.Amount; ++i) {
				level.AddOn(Clone(&bp.Entrances.Item));
			}
			LevelBuilder().Build(bp, level);
		}
	}
}