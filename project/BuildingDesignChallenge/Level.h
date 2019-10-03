#pragma once
#include "Buildable.h"
namespace BuildingChallenge {
	class Level : public Buildable {
	public:
		Level();
	protected:
		virtual void OnAfterBuild() {};
		Level(const std::string&);
	};
}
