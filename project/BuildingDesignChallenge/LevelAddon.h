#pragma once
#include "Buildable.h"
#include <string>

namespace BuildingChallenge {
	namespace LevelAddons {
		class LevelAddon : public Buildable {
		public:
			virtual ~LevelAddon() = default;
		protected:
			explicit LevelAddon(const std::string& name) : Buildable(name) {}
		};
	}
}
