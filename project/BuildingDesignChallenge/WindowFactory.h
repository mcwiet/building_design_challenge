#pragma once
#include "Windows.h"
#include "BuildableFactory.h"
namespace BuildingChallenge {
	namespace LevelAddons {
		namespace Windows {
			std::map < std::string, std::shared_ptr<AbstractBuildableFactory>> FactoryMap = {
				{DoublePane().GetName(), std::make_shared<BuildableFactory<DoublePane>>()},
				{SinglePane().GetName(), std::make_shared<BuildableFactory<SinglePane>>()},
				{EnergyEfficient().GetName(), std::make_shared<BuildableFactory<EnergyEfficient>>()},
				{StainedGlass().GetName(), std::make_shared<BuildableFactory<StainedGlass>>()}
			};
		}
	}
}