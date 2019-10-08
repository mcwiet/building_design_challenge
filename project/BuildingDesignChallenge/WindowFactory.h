#pragma once
#include "Windows.h"
#include "Factory.h"
namespace BuildingChallenge {
	namespace LevelAddons {
		namespace Windows {
			static const std::map<std::string, std::shared_ptr<AbstractFactory<Window>>, CaseInsensitiveCompare> FactoryMap = {
				{DoublePane().GetName(), std::make_shared<Factory<Window, DoublePane>>()},
				{SinglePane().GetName(), std::make_shared<Factory<Window, SinglePane>>()},
				{EnergyEfficient().GetName(), std::make_shared<Factory<Window, EnergyEfficient>>()},
				{StainedGlass().GetName(), std::make_shared<Factory<Window, StainedGlass>>()}
			};
		}
	}
}