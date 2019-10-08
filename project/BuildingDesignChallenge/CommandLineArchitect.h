#pragma once
#include "StandardBuildingBlueprint.h"
#include "EntranceLevelBlueprint.h"
#include "LevelBlueprint.h"
#include "Factory.h"

namespace BuildingChallenge {
	namespace Architects {
		class CommandLineArchitect {
		public:
			Blueprints::StandardBuildingBlueprint DesignStandardBuilding();

		private:
			Blueprints::EntranceLevelBlueprint GetEntranceLevelBlueprint(unsigned);
			Blueprints::LevelBlueprint GetLevelBlueprint(unsigned);
			template <typename T>
			Blueprints::Blueprint<T> GetAddon(unsigned, std::string, bool,
				const std::map<std::string, std::shared_ptr<AbstractFactory<T>>, CaseInsensitiveCompare>&);
			unsigned GetNumberOfLevels();
			unsigned GetPositiveValue(bool zero_valid);
			std::string GetUserInput();
		};
	}
}