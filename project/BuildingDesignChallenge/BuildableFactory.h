#pragma once
#include "Buildable.h"
#include <string>
#include <map>
#include <memory>
namespace BuildingChallenge {
	struct CaseInsensitiveCompare {
		struct NoCase {
			bool operator() (const unsigned char& c1, const unsigned char& c2) const {
				return tolower(c1) < tolower(c2);
			}
		};
		bool operator() (const std::string& s1, const std::string& s2) const {
			return std::lexicographical_compare(
				s1.begin(), s1.end(), s2.begin(), s2.end(), NoCase());
		}
	};

	class BuildableFactory {
	public:
		virtual ~BuildableFactory() = default;
		std::shared_ptr<Buildable> Create() { return std::shared_ptr<Buildable>(CreateDerived()); }

	protected:
		virtual Buildable* CreateDerived() = 0;
	};
}