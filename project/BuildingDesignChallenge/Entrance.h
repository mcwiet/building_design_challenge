#pragma once
#include "LevelAddon.h"

namespace BuildingChallenge {
	namespace LevelAddons {
		class Entrance : public LevelAddon {
		public:
			Entrance() : Entrance("Entrance") {};
			explicit Entrance(const std::string& name) : LevelAddon(name) {}
			virtual void OnAfterBuild() override {};
			virtual void OnBuild() override {
				std::cout << "Building " << name_ << " Entrance..." << std::endl;
			}
		};
	}
}