#pragma once
#include "EntranceLevelBlueprint.h"
#include "Level.h"

namespace BuildingChallenge {
	namespace Builders {
		class EntranceLevelBuilder {
		public:
			std::shared_ptr<Level> Build(std::shared_ptr<Blueprints::EntranceLevelBlueprint>);
		};
	}
}
