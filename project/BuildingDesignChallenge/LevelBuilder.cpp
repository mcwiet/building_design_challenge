#include "LevelBuilder.h"

namespace BuildingChallenge {
	namespace Builders {
		Level LevelBuilder::Build(const Blueprints::LevelBlueprint& bp) {
			Level level;
			Build(bp, level);
			return level;
		}

		void LevelBuilder::Build(const Blueprints::LevelBlueprint& bp, Level& level) {
			for (unsigned i = 0; i < bp.Windows.Amount; ++i) {
				level.AddOn(bp.Windows.Factory.lock()->Create());
			}
			for (unsigned i = 0; i < bp.Rooms.Amount; ++i) {
				level.AddOn(bp.Rooms.Factory.lock()->Create());
			}
			level.Build();
		}
	}
}