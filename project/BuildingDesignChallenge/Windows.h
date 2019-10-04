#pragma once
#include "LevelAddon.h"
#include <map>
#include <typeindex>
namespace BuildingChallenge {
	namespace LevelAddons {
		namespace Windows {
			class Window : public LevelAddon {
			protected:
				Window(const std::string& name) : LevelAddon(name) {}
				virtual void OnAfterBuild() override {};
				virtual void OnBuild() override {
					std::cout << "Building " << name_ << " Window..." << std::endl;
				}
			};

			struct DoublePane : public Window { DoublePane() : Window("Double Pane") {} };
			struct SinglePane : public Window { SinglePane() : Window("Single Pane") {} };
			struct EnergyEfficient : public Window { EnergyEfficient() : Window("Energy Efficient") {} };
			struct StainedGlass : public Window { StainedGlass() : Window("Stained Glass") {} };

			static const std::map<std::type_index, std::shared_ptr<Window>> LookupTable{
				{typeid(DoublePane()), std::make_shared<DoublePane>()},
				{typeid(SinglePane()), std::make_shared<SinglePane>()},
				{typeid(EnergyEfficient()), std::make_shared<EnergyEfficient>()},
				{typeid(StainedGlass()), std::make_shared<StainedGlass>()}
			};
		}
	}
}