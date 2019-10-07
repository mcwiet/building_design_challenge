#pragma once
#include "LevelAddon.h"
namespace BuildingChallenge {
	namespace LevelAddons {
		namespace Rooms {
			class Room : public LevelAddon {
			protected:
				Room(const std::string& name) : LevelAddon(name) {}
				virtual void OnAfterBuild() override {};
				virtual void OnBuild() override {
					std::cout << "Building " << name_ << " Room..." << std::endl;
				}
			};

			struct Office : public Room { Office() : Room("Office") {} };
			struct Gym : public Room { Gym() : Room("Gym") {} };
			struct Suite : public Room { Suite() : Room("Suite") {} };
			struct Storage : public Room { Storage() : Room("Storage") {} };
		};
	}
}