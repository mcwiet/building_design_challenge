#pragma once
#include "LevelBlueprint.h"
#include "Level.h"

namespace BuildingChallenge {
	namespace Builders {
		class LevelBuilder {
		public:
			std::shared_ptr<Level> Build(const std::shared_ptr<const Blueprints::LevelBlueprint>);
		};
	}
}
