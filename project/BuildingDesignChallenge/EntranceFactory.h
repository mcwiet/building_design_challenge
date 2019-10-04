#pragma once
#include "Entrances.h"
#include "BuildableFactory.h"
namespace BuildingChallenge {
	namespace LevelAddons {
		namespace Entrances {
			static const std::map<std::string, std::shared_ptr<AbstractBuildableFactory>, CaseInsensitiveCompare> FactoryMap = {
				{DoubleDoor().GetName(), std::make_shared<BuildableFactory<DoubleDoor>>()},
				{SingleDoor().GetName(), std::make_shared<BuildableFactory<SingleDoor>>()},
				{RevolvingDoor().GetName(), std::make_shared<BuildableFactory<RevolvingDoor>>()},
				{GarageDoor().GetName(), std::make_shared<BuildableFactory<GarageDoor>>()}
			};
		}
	}
}