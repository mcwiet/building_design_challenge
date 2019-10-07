#pragma once
#include "Rooms.h"
#include "BuildableFactory.h"
namespace BuildingChallenge {
	namespace LevelAddons {
		namespace Rooms {
			static const std::map<std::string, std::shared_ptr<AbstractBuildableFactory>, CaseInsensitiveCompare> FactoryMap = {
				{Office().GetName(), std::make_shared<BuildableFactory<Office>>()},
				{Gym().GetName(), std::make_shared<BuildableFactory<Gym>>()},
				{Suite().GetName(), std::make_shared<BuildableFactory<Suite>>()},
				{Storage().GetName(), std::make_shared<BuildableFactory<Storage>>()}
			};
		}
	}
}