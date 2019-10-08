#pragma once
#include "LevelAddon.h"
#include <string>
#include <map>
#include <memory>

namespace BuildingChallenge {
	namespace Architects {
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

		enum class Minimum {
			Zero,
			One
		};

		template <typename T>
		using AddonMap = std::map<std::string /*Addon Name*/, std::shared_ptr<T> /*Prototype*/, CaseInsensitiveCompare /*Search Modifier*/>;

		template <typename T>
		struct AddonQuestionnaire {
			explicit AddonQuestionnaire(std::string type_name, AddonMap<T> map, Minimum min) :
				AddonTypeName(type_name),
				TypeMap(map),
				MinAmount(min) {}

			std::string AddonTypeName;
			AddonMap<T> TypeMap;
			Minimum MinAmount;
		};
	}
}