#pragma once
#include <memory>

namespace BuildingChallenge {
	template <typename T>
	std::unique_ptr<T> Clone(const T* object) {
		return std::unique_ptr<T>(new T(*object));
	}
}
