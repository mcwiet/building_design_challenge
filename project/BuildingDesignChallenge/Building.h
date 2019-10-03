#pragma once
#include "Buildable.h"
#include "Level.h"
#include <vector>

namespace BuildingChallenge {
	class Building : public Buildable {
	public:
		Building();
		virtual void OnBuild() override;
		void AddLevel(Level&);

	private:
		virtual void OnAfterBuild() override {};
		std::vector<std::reference_wrapper<Level>> levels_;
	};
}
