#pragma once
#include "Factory.h"
#include <memory>

namespace BuildingChallenge {
	namespace Blueprints {
		template <typename T>
		struct Blueprint {
			std::weak_ptr<AbstractFactory<T>> Factory;
			unsigned Amount = 0;
		};
	}
}