#pragma once
#include "LevelAddon.h"

namespace BuildingChallenge {
	namespace Addons {
		namespace Entrances {
			struct DoubleDoor : public LevelAddon { DoubleDoor(Level& level) :LevelAddon("Double Door", level) {} };
			struct SingleDoor : public LevelAddon { SingleDoor(Level& level) :LevelAddon("Single Door", level) {} };
			struct RevolvingDoor : public LevelAddon { RevolvingDoor(Level& level) :LevelAddon("Revolving Door", level) {} };
			struct GarageDoor : public LevelAddon { GarageDoor(Level& level) :LevelAddon("Garage Door", level) {} };
		}
	}
}