#include "CommandLineArchitect.h"
#include "EntranceFactory.h"
#include "WindowFactory.h"
#include <exception>
#include <iostream>

namespace BuildingChallenge {
	namespace Architects {
		std::shared_ptr<Blueprints::StandardBuildingBlueprint> CommandLineArchitect::DesignStandardBuilding() {
			unsigned levels = GetNumberOfLevels();
			auto building = std::make_shared<Blueprints::StandardBuildingBlueprint>(GetEntranceLevelBlueprint(1));
			for (unsigned level = 2; level <= levels; ++level) {
				building->AddLevelBlueprint(GetLevelBlueprint(level));
			}
			return building;
		}

		std::shared_ptr<Blueprints::EntranceLevelBlueprint> CommandLineArchitect::GetEntranceLevelBlueprint(unsigned level) {
			auto bp = std::make_shared<Blueprints::EntranceLevelBlueprint>();
			return bp;
		}

		std::shared_ptr<Blueprints::LevelBlueprint> CommandLineArchitect::GetLevelBlueprint(unsigned level) {
			return nullptr;
		}

		std::pair<std::shared_ptr<Buildable>, unsigned> CommandLineArchitect::GetAddon(
			unsigned level,
			std::string addon_type,
			bool zero_valid,
			const std::map<std::string, std::shared_ptr<AbstractBuildableFactory>, CaseInsensitiveCompare>& factory_map)
		{
			std::pair<std::shared_ptr<Buildable>, unsigned> addon;

			std::cout << "Level " << level << ": " << addon_type << " Options: How many?" << std::endl;
			addon.second = GetPositiveValue(zero_valid);
			std::cout << "Level " << level << ": " << addon_type << " Options: What style would you like to use?" << std::endl;
			std::cout << "Level " << level << ": " << addon_type << " Options: ";
			for (auto pair : factory_map) { std::cout << pair.first << ", "; }

			bool valid = false;
			while (!valid) {
				std::cout << std::endl << "Level " << level << ": ";
				std::string input = GetUserInput();
				auto it = factory_map.find(input);
				if (it == factory_map.end()) {
					std::cout << "That style is not valid. Please select a valid style.";
				}
				else {
					addon.first = it->second->Create();
					valid = true;
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