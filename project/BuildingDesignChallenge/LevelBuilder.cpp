#include "LevelBuilder.h"
#include "Clone.h"

namespace BuildingChallenge {
	namespace Builders {
		Level LevelBuilder::Build(const Blueprints::LevelBlueprint& bp) {
			Level level;
			Build(bp, level);
			return level;
		}

		void LevelBuilder::Build(const Blueprints::LevelBlueprint& bp, Level& level) {
			for (unsigned i = 0; i < bp.Windows.Amount; ++i) {
				level.AddOn(Clone(&bp.Windows.Item));
			}
			for (unsigned i = 0; i < bp.Rooms.Amount; ++i) {
				level.AddOn(Clone(&bp.Rooms.Item));
			}
			level.Build();
		}
	}
}