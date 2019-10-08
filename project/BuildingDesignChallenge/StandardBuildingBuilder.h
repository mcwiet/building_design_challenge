#pragma once
#include "StandardBuildingBlueprint.h"
#include "Building.h"

namespace BuildingChallenge {
	namespace Builders {
		class StandardBuildingBuilder {
		public:
			Building Build(const Blueprints::StandardBuildingBlueprint&);
		};
	}
}