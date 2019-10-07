#pragma once
#include "StandardBuildingBlueprint.h"
#include "Building.h"

namespace BuildingChallenge {
	namespace Builders {
		class StandardBuildingBuilder {
		public:
			std::shared_ptr<Building> Build(const std::shared_ptr<const Blueprints::StandardBuildingBlueprint>);
		};
	}
}