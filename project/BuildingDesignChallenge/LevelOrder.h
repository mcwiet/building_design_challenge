#pragma once
#include "Windows.h"

namespace BuildingChallenge {
	namespace Orders {
		struct LevelOrder {
			std::pair<std::shared_ptr<LevelAddons::Windows::Window>, unsigned> WindowOrder;
		};
	}
}