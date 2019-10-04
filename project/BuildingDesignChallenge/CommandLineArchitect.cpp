//#include "CommandLineArchitect.h"
//#include "EntranceFactory.h"
//#include "WindowFactory.h"
//#include <exception>
//#include <iostream>
//
//namespace BuildingChallenge {
//	namespace Architects {
//		std::shared_ptr<Blueprints::StandardBuildingBlueprint> CommandLineArchitect::DesignStandardBuilding() {
//			unsigned levels = GetNumberOfLevels();
//			auto building = std::make_shared<Blueprints::StandardBuildingBlueprint>(GetEntranceLevelBlueprint(1));
//			for (unsigned level = 2; level <= levels; ++level) {
//				building->AddLevelBlueprint(GetLevelBlueprint(level));
//			}
//			return building;
//		}
//
//		std::shared_ptr<Blueprints::EntranceLevelBlueprint> CommandLineArchitect::GetEntranceLevelBlueprint(unsigned level) {
//			auto bp = std::make_shared<Blueprints::EntranceLevelBlueprint>();
//			return bp;
//		}
//
//		std::shared_ptr<Blueprints::LevelBlueprint> CommandLineArchitect::GetLevelBlueprint(unsigned level) {
//		}
//
//		template<typename AddonType>
//		std::pair<std::shared_ptr<AddonType>, unsigned> CommandLineArchitect::GetAddon(unsigned level, std::string addon_type) {
//			std::pair<std::shared_ptr<AddonType>, unsigned> addon;
//
//			std::cout << "Level " << level << ": " << addon_type << " Options: How many?";
//			addon.second = GetValueGreaterThanZero();
//			std::cout << "Level " << level << ": " << addon_type << " Options: What style would you like to use?";
//			std::cout << "Level " << level << ": " << addon_type << " Options: ";
//			for (auto map_val : LevelAddons::LookupTable) {
//				std::cout << map_val.second->GetName() << ", ";
//			}
//
//			bool valid = false;
//			while (!valid) {
//				try {
//					addon.first = LevelAddons::Windows::Create(GetUserInput());
//					valid = true;
//				}
//				catch (LevelAddons::Entrances::InvalidEntranceException& e) {
//					std::cout << "That style is not valid. Please select a valid style." << std::endl;
//				}
//			}
//
//			return addon;
//		}
//
//		unsigned CommandLineArchitect::GetNumberOfLevels() {
//			unsigned levels;
//			std::cout << "How many floors will the building have?" << std::endl;
//			levels = GetValueGreaterThanZero();
//		}
//
//		unsigned CommandLineArchitect::GetValueGreaterThanZero() {
//			unsigned num;
//			bool valid = false;
//			while (!valid) {
//				std::string input = GetUserInput();
//				try {
//					num = static_cast<unsigned>(std::stoul(input));
//					if (num == 0) {
//						throw std::exception();
//					}
//					valid = true;
//				}
//				catch (...) {
//					std::cout << "Please input a positive integer greater than 0." << std::endl;
//				}
//			}
//		}
//
//		unsigned CommandLineArchitect::GetValueGreaterThanOrEqualZero() {
//			unsigned num;
//			bool valid = false;
//			while (!valid) {
//				std::string input = GetUserInput();
//				try {
//					num = static_cast<unsigned>(std::stoul(input));
//					valid = true;
//				}
//				catch (...) {
//					std::cout << "Please input a positive integer greater than or equal to 0." << std::endl;
//				}
//			}
//		}
//
//		std::string CommandLineArchitect::GetUserInput() {
//			std::string input;
//			std::getline(std::cin, input);
//			return input;
//		}
//	}
//}