#include "StandardBuildingBlueprint.h"

namespace BuildingChallenge {
	namespace Blueprints {
		StandardBuildingBlueprint::StandardBuildingBlueprint(const EntranceLevelBlueprint& first_level) :
			first_level_(first_level) {}

		StandardBuildingBlueprint::StandardBuildingBlueprint(EntranceLevelBlueprint&& first_level) :
			first_level_(first_level) {}

		void StandardBuildingBlueprint::AddLevelBlueprint(const LevelBlueprint& level) {
			additional_levels_.push_back(level);
		}

		void StandardBuildingBlueprint::AddLevelBlueprint(LevelBlueprint&& level) {
			additional_levels_.push_back(level);
		}

		const EntranceLevelBlueprint& StandardBuildingBlueprint::GetFirstLevel() const {
			return first_level_;
		}

		const std::vector<LevelBlueprint>& StandardBuildingBlueprint::GetAdditionalLevels() const {
			return additional_levels_;
		}
	}
}