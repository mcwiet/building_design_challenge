#pragma once
#include <memory>

namespace BuildingChallenge {
	namespace Blueprints {
		template <typename T>
		struct Blueprint {
			T Item;
			unsigned Amount = 0;
		};
	}
}