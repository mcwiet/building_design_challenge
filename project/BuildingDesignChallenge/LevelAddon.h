#pragma once
#include "Level.h"
namespace BuildingChallenge {
	class LevelAddon : public Level {
	protected:
		LevelAddon(const std::string&, Level&);
		virtual void OnBeforeBuild() override;
		Level& level_;
	};
}
