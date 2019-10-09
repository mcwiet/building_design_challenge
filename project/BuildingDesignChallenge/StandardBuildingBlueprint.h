#pragma once
#include "EntranceLevelBlueprint.h"
#include "LevelBlueprint.h"
#include "Building.h"
#include <exception>

namespace BuildingChallenge {
	namespace Blueprints {
		class StandardBuildingBlueprint {
		public:
			explicit StandardBuildingBlueprint(const EntranceLevelBlueprint& first_level);
			explicit StandardBuildingBlueprint(EntranceLevelBlueprint&& first_level);
			void AddLevelBlueprint(const LevelBlueprint& level);
			void AddLevelBlueprint(LevelBlueprint&& level);
			const EntranceLevelBlueprint& GetFirstLevel() const;
			const std::vector<LevelBlueprint>& GetAdditionalLevels() const;

		private:
			EntranceLevelBlueprint first_level_;
			std::vector<LevelBlueprint> additional_levels_;
		};
	}
}