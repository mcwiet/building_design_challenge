#pragma once
#include "StandardBuildingBlueprint.h"
#include "EntranceLevelBlueprint.h"
#include "LevelBlueprint.h"
#include "BuildableFactory.h"

namespace BuildingChallenge {
	namespace Architects {
		class CommandLineArchitect {
		public:
			std::shared_ptr<Blueprints::StandardBuildingBlueprint> DesignStandardBuilding();

		private:
			std::shared_ptr<Blueprints::EntranceLevelBlueprint> GetEntranceLevelBlueprint(unsigned);
			std::shared_ptr<Blueprints::LevelBlueprint> GetLevelBlueprint(unsigned);
			std::pair<std::shared_ptr<Buildable>, unsigned> GetAddon(unsigned, std::string, bool,
				const std::map<std::string, std::shared_ptr<AbstractBuildableFactory>, CaseInsensitiveCompare>&);
			unsigned GetNumberOfLevels();
			unsigned GetPositiveValue(bool zero_valid);
			std::string GetUserInput();
		};
	}
}