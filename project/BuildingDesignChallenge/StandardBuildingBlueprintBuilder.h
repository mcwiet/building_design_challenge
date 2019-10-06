#pragma once
#include "StandardBuildingBlueprint.h"
#include "Level.h"

namespace BuildingChallenge {
	namespace Builders {
		class StandardBuildingBuilder {
		public:
			std::shared_ptr<Level> Build(std::shared_ptr<Blueprints::StandardBuildingBlueprint>);
		};
	}
}