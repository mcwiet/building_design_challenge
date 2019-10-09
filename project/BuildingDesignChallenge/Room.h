#pragma once
#include "LevelAddon.h"

namespace BuildingChallenge {
	namespace LevelAddons {
		class Room : public LevelAddon {
		public:
			Room() : Room("Room") {};
			explicit Room(const std::string& name) : LevelAddon(name) {}
			virtual void OnAfterBuild() override {};
			virtual void OnBuild() override {
				std::cout << "Building " << name_ << " Room..." << std::endl;
			}
		};
	}
}