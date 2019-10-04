#pragma once
#include "EntranceLevelOrder.h"
#include "LevelOrder.h"
#include "Building.h"
#include <exception>

namespace BuildingChallenge {
	namespace Orders {
		class StandardBuildingOrder {
		public:
			class NullFirstLevelException : public std::exception {};
			class EntryLevelAsAdditionalFloorException : public std::exception {};

			StandardBuildingOrder(std::shared_ptr<EntranceLevelOrder> first_level) :
				first_level_(first_level)
			{
				if (first_level_ == nullptr) {
					throw NullFirstLevelException();
				}
			}

			void AddLevelOrder(std::shared_ptr<LevelOrder> level) {
				additional_levels_.push_back(level);
			}

			const std::shared_ptr<const EntranceLevelOrder> GetFirstLevel() {
				return first_level_;
			}

			const std::vector<std::shared_ptr<const LevelOrder>>& GetAdditionalLevels() {
				return additional_levels_;
			}

		private:
			const std::shared_ptr<const EntranceLevelOrder> first_level_;
			std::vector<std::shared_ptr<const LevelOrder>> additional_levels_;
		};
	}
}