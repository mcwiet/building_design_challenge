#pragma once
#include "LevelAddon.h"
namespace BuildingChallenge {
	namespace LevelAddons {
		namespace Entrances {
			class Entrance : public Addons::LevelAddon {
			protected:
				Entrance(const std::string& name) : LevelAddon(name) {}
				virtual void OnAfterBuild() override {};
				virtual void OnBuild() override {
					std::cout << "Building " << name_ << " Entrance..." << std::endl;
				}
			};

			struct DoubleDoor : public Entrance { DoubleDoor() : Entrance("Double Door") {} };
			struct SingleDoor : public Entrance { SingleDoor() : Entrance("Single Door") {} };
			struct RevolvingDoor : public Entrance { RevolvingDoor() : Entrance("Revolving Door") {} };
			struct GarageDoor : public Entrance { GarageDoor() : Entrance("Garage Door") {} };
		}
	}
}