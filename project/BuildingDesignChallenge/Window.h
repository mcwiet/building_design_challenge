#pragma once
#include "LevelAddon.h"

namespace BuildingChallenge {
	namespace LevelAddons {
		class Window : public LevelAddon {
		public:
			Window() : Window("Window") {};
			explicit Window(const std::string& name) : LevelAddon(name) {}
			virtual void OnAfterBuild() override {};
			virtual void OnBuild() override {
				std::cout << "Building " << name_ << " Window..." << std::endl;
			}
		};
	}
}