#pragma once
#include "LevelBlueprint.h"
#include "Level.h"

namespace BuildingChallenge {
	namespace Builders {
		class LevelBuilder {
		public:
			Level Build(const Blueprints::LevelBlueprint&);
			void Build(const Blueprints::LevelBlueprint&, Level&);
		};
	}
}
