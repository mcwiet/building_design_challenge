#pragma once
#include "Entrances.h"
#include "BuildableFactory.h"
namespace BuildingChallenge {
	namespace LevelAddons {
		namespace Entrances {
			namespace {
				template<typename T>
				class EntranceFactory : public BuildableFactory {
					virtual T* CreateDerived() override { return new T; }
				};
			}

			static const std::map<std::string, std::shared_ptr<BuildableFactory>, CaseInsensitiveCompare> FactoryMap = {
				{DoubleDoor().GetName(), std::make_shared<EntranceFactory<DoubleDoor>>()},
				{SingleDoor().GetName(), std::make_shared<EntranceFactory<SingleDoor>>()},
				{RevolvingDoor().GetName(), std::make_shared<EntranceFactory<RevolvingDoor>>()},
				{GarageDoor().GetName(), std::make_shared<EntranceFactory<GarageDoor>>()}
			};
		}
	}
}