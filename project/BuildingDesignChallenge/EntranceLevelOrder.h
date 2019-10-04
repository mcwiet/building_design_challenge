#pragma once
#include "LevelOrder.h"
#include "Entrances.h"

namespace BuildingChallenge {
	namespace Orders {
		struct EntranceLevelOrder : public LevelOrder {
			std::pair<std::shared_ptr<LevelAddons::Entrances::Entrance>, unsigned> EntranceOrder;
		};
	}
}