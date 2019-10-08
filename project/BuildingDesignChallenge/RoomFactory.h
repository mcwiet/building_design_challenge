#pragma once
#include "Rooms.h"
#include "Factory.h"
namespace BuildingChallenge {
	namespace LevelAddons {
		namespace Rooms {
			static const std::map<std::string, std::shared_ptr<AbstractFactory<Room>>, CaseInsensitiveCompare> FactoryMap = {
				{Office().GetName(), std::make_shared<Factory<Room, Office>>()},
				{Gym().GetName(), std::make_shared<Factory<Room, Gym>>()},
				{Suite().GetName(), std::make_shared<Factory<Room, Suite>>()},
				{Storage().GetName(), std::make_shared<Factory<Room, Storage>>()}
			};
		}
	}
}