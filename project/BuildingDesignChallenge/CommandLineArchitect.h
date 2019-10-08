#pragma once
#include "StandardBuildingBlueprint.h"
#include "EntranceLevelBlueprint.h"
#include "LevelBlueprint.h"
#include "AddonQuestionnaire.h"
#include <string>

namespace BuildingChallenge {
	namespace Architects {
		class CommandLineArchitect {
		public:
			Blueprints::StandardBuildingBlueprint DesignStandardBuilding(
				const AddonQuestionnaire<LevelAddons::Entrance>& entrance,
				const AddonQuestionnaire<LevelAddons::Window>& windows,
				const AddonQuestionnaire<LevelAddons::Room>& rooms);

		private:
			template <typename T>
			Blueprints::Blueprint<T> GetAddon(unsigned level, const AddonQuestionnaire<T>& quest);
			unsigned GetNumberOfLevels();
			unsigned GetPositiveValue(Minimum);
			std::string GetUserInput();
		};
	}
}