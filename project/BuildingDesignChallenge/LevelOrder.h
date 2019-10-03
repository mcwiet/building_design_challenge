#pragma once
#include "Windows.h"
#include <typeindex>

namespace BuildingChallenge {
	namespace Orders {
		struct LevelOrder {
			std::pair<LevelAddons::Windows::Window, unsigned> WindowOrder;
		};
	}
}