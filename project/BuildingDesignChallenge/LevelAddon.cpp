#include "LevelAddon.h"

namespace BuildingChallenge {
	LevelAddon::LevelAddon(const std::string& name, Level& level) :
		Level(name),
		level_(level) {}
	void LevelAddon::OnAfterBuild()
	{
		level_.Build();
	}
}