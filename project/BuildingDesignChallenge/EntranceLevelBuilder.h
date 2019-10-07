#pragma once
#include "EntranceLevelBlueprint.h"
#include "Level.h"
#include <memory>

namespace BuildingChallenge {
	namespace Builders {
		class EntranceLevelBuilder {
		public:
			std::shared_ptr<Level> Build(const std::shared_ptr<const Blueprints::EntranceLevelBlueprint>);
		};
	}
}
