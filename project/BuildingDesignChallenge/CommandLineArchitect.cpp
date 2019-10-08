#include "CommandLineArchitect.h"
#include "Entrance.h"
#include "Window.h"
#include "Room.h"
#include <exception>
#include <iostream>

namespace BuildingChallenge {
	namespace Architects {
		Blueprints::StandardBuildingBlueprint CommandLineArchitect::DesignStandardBuilding(
			const AddonQuestionnaire<LevelAddons::Entrance>& entrances,
			const AddonQuestionnaire<LevelAddons::Window>& windows,
			const AddonQuestionnaire<LevelAddons::Room>& rooms)
		{
			unsigned levels = GetNumberOfLevels();

			Blueprints::EntranceLevelBlueprint enter_bp;
			enter_bp.Entrances = GetAddon(1, entrances);
			enter_bp.Windows = GetAddon(1, windows);
			enter_bp.Rooms = GetAddon(1, rooms);
			Blueprints::StandardBuildingBlueprint bldg_bp(enter_bp);
			std::cout << "------------LEVEL 1 COMPLETE!------------" << std::endl;

			for (unsigned level = 2; level <= levels; ++level) {
				Blueprints::LevelBlueprint level_bp;
				level_bp.Windows = GetAddon(1, windows);
				level_bp.Rooms = GetAddon(1, rooms);
				bldg_bp.AddLevelBlueprint(level_bp);
				std::cout << "------------LEVEL " << level << " COMPLETE!------------" << std::endl;
			}
			return bldg_bp;
		}

		template <typename T>
		Blueprints::Blueprint<T> CommandLineArchitect::GetAddon(unsigned level, const AddonQuestionnaire<T>& quest) {
			Blueprints::Blueprint<T> bp;

			std::cout << "Level " << level << ": " << quest.AddonTypeName << " Options: How many?" << std::endl;
			std::cout << "Level " << level << ": " << quest.AddonTypeName << " Options: ";
			bp.Amount = GetPositiveValue(quest.MinAmount);
			std::cout << "Level " << level << ": " << quest.AddonTypeName << " Options: What style would you like to use?" << std::endl;
			std::cout << "Level " << level << ": " << quest.AddonTypeName << " Options: ";
			for (auto& addon : quest.TypeMap) { std::cout << addon.first << ", "; }

			bool need_style = (bp.Amount != 0) || ((bp.Amount == 0) && (quest.MinAmount == Minimum::One));
			while (need_style) {
				std::cout << std::endl;
				std::cout << "Level " << level << ": " << quest.AddonTypeName << " Options: ";
				std::string input = GetUserInput();
				auto it = quest.TypeMap.find(input);
				if (it == quest.TypeMap.end()) {
					std::cout << "That style is not valid. Please select a valid style.";
				}
				else {
					bp.Item = *(it->second);
					need_style = false;
				}
			}

			return bp;
		}

		unsigned CommandLineArchitect::GetNumberOfLevels() {
			std::cout << "How many floors will the building have?" << std::endl;
			return GetPositiveValue(Minimum::One);
		}

		unsigned CommandLineArchitect::GetPositiveValue(Minimum min) {
			long num;
			bool valid = false;
			while (!valid) {
				std::string input = GetUserInput();
				try {
					num = std::stol(input);
					if ((num < 0) || ((num == 0) && (min != Minimum::Zero)))
						throw std::exception();
					valid = true;
				}
				catch (...) {
					std::string zero_valid_string = (min == Minimum::Zero) ? "or equal to " : "";
					std::cout << "Please input a positive integer greater than " << zero_valid_string << "0." << std::endl;
				}
			}
			return static_cast<unsigned>(num);
		}

		std::string CommandLineArchitect::GetUserInput() {
			std::string input;
			std::getline(std::cin, input);
			return input;
		}
	}
}