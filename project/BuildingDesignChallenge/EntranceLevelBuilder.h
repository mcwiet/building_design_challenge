#pragma once
#include "EntranceLevelBlueprint.h"
#include "Level.h"
#include <memory>

namespace BuildingChallenge {
	namespace Builders {
		class EntranceLevelBuilder {
		public:
			Level Build(const Blueprints::EntranceLevelBlueprint&);
			void Build(const Blueprints::EntranceLevelBlueprint&, Level&);
		};
	}
}
