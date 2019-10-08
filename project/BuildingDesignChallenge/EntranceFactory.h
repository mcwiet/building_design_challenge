#pragma once
#include "Entrances.h"
#include "Factory.h"

namespace BuildingChallenge {
	namespace LevelAddons {
		namespace Entrances {
			static const std::map<std::string, std::shared_ptr<AbstractFactory<Entrance>>, CaseInsensitiveCompare> FactoryMap = {
				{DoubleDoor().GetName(), std::make_shared<Factory<Entrance, DoubleDoor>>()},
				{SingleDoor().GetName(), std::make_shared<Factory<Entrance, SingleDoor>>()},
				{RevolvingDoor().GetName(), std::make_shared<Factory<Entrance, RevolvingDoor>>()},
				{GarageDoor().GetName(), std::make_shared<Factory<Entrance, GarageDoor>>()}
			};
		}
	}
}