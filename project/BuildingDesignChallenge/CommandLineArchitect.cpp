#include "CommandLineArchitect.h"
#include "EntranceFactory.h"
#include "WindowFactory.h"
#include "RoomFactory.h"
#include <exception>
#include <iostream>

namespace BuildingChallenge {
	namespace Architects {
		std::shared_ptr<Blueprints::StandardBuildingBlueprint> CommandLineArchitect::DesignStandardBuilding() {
			unsigned levels = GetNumberOfLevels();
			auto bp = std::make_shared<Blueprints::StandardBuildingBlueprint>(GetEntranceLevelBlueprint(1));
			std::cout << "------------LEVEL 1 COMPLETE!------------" << std::endl;
			for (unsigned level = 2; level <= levels; ++level) {
				bp->AddLevelBlueprint(GetLevelBlueprint(level));
				std::cout << "------------LEVEL " << level << " COMPLETE!------------" << std::endl;
			}
			return bp;
		}

		std::shared_ptr<Blueprints::EntranceLevelBlueprint> CommandLineArchitect::GetEntranceLevelBlueprint(unsigned level) {
			auto bp = std::make_shared<Blueprints::EntranceLevelBlueprint>();
			auto entrances = GetAddon(level, "Entrance", false, LevelAddons::Entrances::FactoryMap);
			auto windows = GetAddon(level, "Window", true, LevelAddons::Windows::FactoryMap);
			auto rooms = GetAddon(level, "Room", false, LevelAddons::Rooms::FactoryMap);
			bp->Entrances = { std::dynamic_pointer_cast<LevelAddons::Entrances::Entrance>(entrances.first), entrances.second };
			bp->Windows = { std::dynamic_pointer_cast<LevelAddons::Windows::Window>(windows.first), windows.second };
			bp->Rooms = { std::dynamic_pointer_cast<LevelAddons::Rooms::Room>(rooms.first), rooms.second };
			return bp;
		}

		std::shared_ptr<Blueprints::LevelBlueprint> CommandLineArchitect::GetLevelBlueprint(unsigned level) {
			auto bp = std::make_shared<Blueprints::LevelBlueprint>();
			auto windows = GetAddon(level, "Window", true, LevelAddons::Windows::FactoryMap);
			auto rooms = GetAddon(level, "Room", false, LevelAddons::Rooms::FactoryMap);
			bp->Windows = { std::dynamic_pointer_cast<LevelAddons::Windows::Window>(windows.first), windows.second };
			bp->Rooms = { std::dynamic_pointer_cast<LevelAddons::Rooms::Room>(rooms.first), rooms.second };
			return bp;
		}

		std::pair<std::shared_ptr<Buildable>, unsigned> CommandLineArchitect::GetAddon(
			unsigned level,
			std::string addon_type,
			bool zero_valid,
			const std::map<std::string, std::shared_ptr<AbstractBuildableFactory>, CaseInsensitiveCompare>& factory_map)
		{
			std::pair<std::shared_ptr<Buildable>, unsigned> addon;

			std::cout << "Level " << level << ": " << addon_type << " Options: How many?" << std::endl;
			std::cout << "Level " << level << ": " << addon_type << " Options: ";
			addon.second = GetPositiveValue(zero_valid);
			std::cout << "Level " << level << ": " << addon_type << " Options: What style would you like to use?" << std::endl;
			std::cout << "Level " << level << ": " << addon_type << " Options: ";
			for (auto pair : factory_map) { std::cout << pair.first << ", "; }

			bool need_style = (addon.second != 0) || (addon.second == 0) && (!zero_valid);
			while (need_style) {
				std::cout << std::endl;
				std::cout << "Level " << level << ": " << addon_type << " Options: ";
				std::string input = GetUserInput();
				auto it = factory_map.find(input);
				if (it == factory_map.end()) {
					std::cout << "That style is not valid. Please select a valid style.";
				}
				else {
					addon.first = it->second->Create();
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