#pragma once
#include "Buildable.h"
#include "Level.h"
#include <vector>

namespace BuildingChallenge {
	class Building : public Buildable {
	public:
		Building();
		virtual void OnAfterBuild() override;
		void AddLevel(Level&);

	private:
		std::vector<std::reference_wrapper<Level>> levels_;
	};
}
