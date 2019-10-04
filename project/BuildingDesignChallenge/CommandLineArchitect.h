#pragma once
#include "StandardBuildingBlueprint.h"
namespace BuildingChallenge {
	namespace Architects {
		class CommandLineArchitect {
		public:
			std::shared_ptr<Blueprints::StandardBuildingBlueprint> DesignStandardBuilding();
		private:
			std::shared_ptr<Blueprints::EntranceLevelBlueprint> GetEntranceLevelBlueprint(unsigned);
			std::shared_ptr<Blueprints::LevelBlueprint> GetLevelBlueprint(unsigned);
			template<typename AddonType>
			std::pair<std::shared_ptr<AddonType>, unsigned> GetAddon(unsigned, std::string);
			unsigned GetNumberOfLevels();
			unsigned GetValueGreaterThanZero();
			unsigned GetValueGreaterThanOrEqualZero();
			std::string GetUserInput();
		};
	}
}