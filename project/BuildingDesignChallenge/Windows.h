#pragma once
#include "LevelAddon.h"
#include <exception>
namespace BuildingChallenge {
	namespace LevelAddons {
		namespace Windows {
			class Window : public Addons::LevelAddon {
			protected:
				Window(const std::string& name) : Addons::LevelAddon(name) {}
				virtual void OnBuild() override {
					std::cout << "Building " << name_ << " Window..." << std::endl;
				}
				virtual void OnAfterBuild() override {};
			};

			struct DoublePane : public Window { DoublePane() : Window("Double Pane") {} };

			struct SinglePane : public Window { SinglePane() : Window("Single Pane") {} };
			struct EnergyEfficient : public Window { EnergyEfficient() : Window("Energy Efficient") {} };
			struct StainedGlass : public Window { StainedGlass() : Window("Stained Glass") {} };
		}
	}
}