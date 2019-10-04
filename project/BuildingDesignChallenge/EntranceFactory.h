#pragma once
#include "Entrances.h"
namespace BuildingChallenge {
	namespace LevelAddons {
		namespace Entrances {
			class InvalidEntranceException : public std::exception {
			public:
				InvalidEntranceException(const std::string& type) :
					type_(type) {};
				const char* what() const throw() {
					return "Invalid Entrance type";
				}
				const char* get_type() {
					return type_.c_str();
				}
			private:
				std::string type_;
			};

			std::shared_ptr<Addons::LevelAddon> Create(const std::string& name) {
				if (!_strcmpi(name.c_str(), DoubleDoor().GetName().c_str())) {
					return std::make_shared<DoubleDoor>();
				}
				else if (!_strcmpi(name.c_str(), SingleDoor().GetName().c_str())) {
					return std::make_shared<SingleDoor>();
				}
				else if (!_strcmpi(name.c_str(), RevolvingDoor().GetName().c_str())) {
					return std::make_shared<RevolvingDoor>();
				}
				else if (!_strcmpi(name.c_str(), GarageDoor().GetName().c_str())) {
					return std::make_shared<GarageDoor>();
				}
				else {
					throw InvalidEntranceException(name);
				}
			}
		}
	}
}