#pragma once
#include "EntranceLevelBlueprint.h"
#include "LevelBlueprint.h"
#include "Building.h"
#include <exception>

namespace BuildingChallenge {
	namespace Blueprints {
		class StandardBuildingBlueprint {
		public:
			class NullFirstLevelException : public std::exception {};
			class EntryLevelAsAdditionalFloorException : public std::exception {};

			StandardBuildingBlueprint(std::shared_ptr<EntranceLevelBlueprint> first_level) :
				first_level_(first_level)
			{
				if (first_level_ == nullptr) {
					throw NullFirstLevelException();
				}
			}

			void AddLevelBlueprint(std::shared_ptr<LevelBlueprint> level) {
				additional_levels_.push_back(level);
			}

			const std::shared_ptr<const EntranceLevelBlueprint> GetFirstLevel() const {
				return first_level_;
			}

			const std::vector<std::shared_ptr<const LevelBlueprint>>& GetAdditionalLevels() const {
				return additional_levels_;
			}

		private:
			const std::shared_ptr<const EntranceLevelBlueprint> first_level_;
			std::vector<std::shared_ptr<const LevelBlueprint>> additional_levels_;
		};
	}
}