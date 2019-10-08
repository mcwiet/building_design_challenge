#include "CommandLineArchitect.h"
#include "EntranceFactory.h"
#include "WindowFactory.h"
#include "RoomFactory.h"
#include <exception>
#include <iostream>

namespace BuildingChallenge {
	namespace Architects {
		Blueprints::StandardBuildingBlueprint CommandLineArchitect::DesignStandardBuilding() {
			unsigned levels = GetNumberOfLevels();
			Blueprints::StandardBuildingBlueprint bp(GetEntranceLevelBlueprint(1));
			std::cout << "------------LEVEL 1 COMPLETE!------------" << std::endl;
			for (unsigned level = 2; level <= levels; ++level) {
				bp.AddLevelBlueprint(GetLevelBlueprint(level));
				std::cout << "------------LEVEL " << level << " COMPLETE!------------" << std::endl;
			}
			return bp;
		}

		Blueprints::EntranceLevelBlueprint CommandLineArchitect::GetEntranceLevelBlueprint(unsigned level) {
			Blueprints::EntranceLevelBlueprint bp;
			bp.Entrances = GetAddon<LevelAddons::Entrances::Entrance>(level, "Entrance", false, LevelAddons::Entrances::FactoryMap);
			bp.Windows = GetAddon<LevelAddons::Windows::Window>(level, "Window", true, LevelAddons::Windows::FactoryMap);
			bp.Rooms = GetAddon<LevelAddons::Rooms::Room>(level, "Room", false, LevelAddons::Rooms::FactoryMap);
			return bp;
		}

		Blueprints::LevelBlueprint CommandLineArchitect::GetLevelBlueprint(unsigned level) {
			Blueprints::LevelBlueprint bp;
			bp.Windows = GetAddon<LevelAddons::Windows::Window>(level, "Window", true, LevelAddons::Windows::FactoryMap);
			bp.Rooms = GetAddon<LevelAddons::Rooms::Room>(level, "Room", false, LevelAddons::Rooms::FactoryMap);
			return bp;
		}

		template <typename T>
		Blueprints::Blueprint<T> CommandLineArchitect::GetAddon(
			unsigned level,
			std::string addon_type,
			bool zero_valid,
			const std::map<std::string, std::shared_ptr<AbstractFactory<T>>, CaseInsensitiveCompare>& factory_map)
		{
			Blueprints::Blueprint<T> addon;

			std::cout << "Level " << level << ": " << addon_type << " Options: How many?" << std::endl;
			std::cout << "Level " << level << ": " << addon_type << " Options: ";
			addon.Amount = GetPositiveValue(zero_valid);
			std::cout << "Level " << level << ": " << addon_type << " Options: What style would you like to use?" << std::endl;
			std::cout << "Level " << level << ": " << addon_type << " Options: ";
			for (auto pair : factory_map) { std::cout << pair.first << ", "; }

			bool need_style = (addon.Amount != 0) || (addon.Amount == 0) && (!zero_valid);
			while (need_style) {
				std::cout << std::endl;
				std::cout << "Level " << level << ": " << addon_type << " Options: ";
				std::string input = GetUserInput();
				auto it = factory_map.find(input);
				if (it == factory_map.end()) {
					std::cout << "That style is not valid. Please select a valid style.";
				}
				else {
					addon.Factory = it->second;
					need_style = false;
				}
			}

			return addon;
		}

		unsigned CommandLineArchitect::GetNumberOfLevels() {
			std::cout << "How many floors will the building have?" << std::endl;
			return GetPositiveValue(false);
		}

		unsigned CommandLineArchitect::GetPositiveValue(bool zero_valid) {
			long num;
			bool valid = false;
			while (!valid) {
				std::string input = GetUserInput();
				try {
					num = std::stol(input);
					if ((num < 0) || ((num == 0) && (!zero_valid)))
						throw std::exception();
					valid = true;
				}
				catch (...) {
					std::string zero_valid_string = (zero_valid) ? "or equal to " : "";
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