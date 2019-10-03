#pragma once
#include <string>
#include <iostream>

namespace BuildingChallenge {
	class Buildable {
	public:
		std::string GetName();
		void Build();
	protected:
		Buildable(const std::string&);
		virtual std::string OnGetName();
		virtual void OnAfterBuild() = 0;
		virtual void OnBuild();

		std::string name_;
	};
}
