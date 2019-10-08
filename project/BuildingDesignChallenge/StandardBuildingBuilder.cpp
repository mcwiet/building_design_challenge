#include "StandardBuildingBuilder.h"
#include "EntranceLevelBuilder.h"
#include "LevelBuilder.h"

namespace BuildingChallenge {
	namespace Builders {
		Building StandardBuildingBuilder::Build(const Blueprints::StandardBuildingBlueprint& bp) {
			Building bldg;
			bldg.AddLevel(std::make_unique<Level>(EntranceLevelBuilder().Build(bp.GetFirstLevel())));
			for (auto level : bp.GetAdditionalLevels()) {
				bldg.AddLevel(std::make_unique<Level>(LevelBuilder().Build(level)));
			}
			return bldg;
		}
	}
}