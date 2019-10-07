#include "StandardBuildingBuilder.h"
#include "EntranceLevelBuilder.h"
#include "LevelBuilder.h"

namespace BuildingChallenge {
	namespace Builders {
		std::shared_ptr<Building> StandardBuildingBuilder::Build(const std::shared_ptr<const Blueprints::StandardBuildingBlueprint> bp) {
			auto bldg = std::make_shared<Building>();
			bldg->AddLevel(EntranceLevelBuilder().Build(bp->GetFirstLevel()));
			for (auto level : bp->GetAdditionalLevels()) {
				bldg->AddLevel(LevelBuilder().Build(level));
			}
			return bldg;
		}
	}
}