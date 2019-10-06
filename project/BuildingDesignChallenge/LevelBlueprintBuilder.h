#pragma once
#include "LevelBlueprint.h"
#include "Level.h"

namespace BuildingChallenge {
	namespace Builders {
		class LevelBuilder {
		public:
			std::shared_ptr<Level> Build(std::shared_ptr<Blueprints::LevelBlueprint>);
		};
	}
}
