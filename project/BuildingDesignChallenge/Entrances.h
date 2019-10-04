#pragma once
#include "LevelAddon.h"
#include <map>
#include <typeindex>
namespace BuildingChallenge {
	namespace LevelAddons {
		namespace Entrances {
			class Entrance : public LevelAddon {
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

			static const std::map<std::type_index, std::shared_ptr<Entrance>> LookupTable{
				{typeid(DoubleDoor()), std::make_shared<DoubleDoor>()},
				{typeid(SingleDoor()), std::make_shared<SingleDoor>()},
				{typeid(RevolvingDoor()), std::make_shared<RevolvingDoor>()},
				{typeid(GarageDoor()), std::make_shared<GarageDoor>()}
			};
		}
	}
}