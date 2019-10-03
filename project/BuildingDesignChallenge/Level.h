#pragma once
#include "Buildable.h"
namespace BuildingChallenge {
	class Level : public Buildable {
	public:
		Level();
	protected:
		virtual void OnBeforeBuild() {};
		Level(const std::string&);
	};
}
