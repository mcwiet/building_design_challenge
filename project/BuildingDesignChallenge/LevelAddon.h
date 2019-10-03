#pragma once
#include "Level.h"
namespace BuildingChallenge {
	class LevelAddon : public Level {
	protected:
		LevelAddon(const std::string&, Level&);
		virtual void OnAfterBuild() override;
		Level& level_;
	};
}
