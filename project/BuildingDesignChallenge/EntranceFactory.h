#pragma once
#include "Entrances.h"
namespace BuildingChallenge {
	namespace LevelAddons {
		namespace Entrances {
			class InvalidEntranceException : public std::exception {
			public:
				InvalidEntranceException(const std::string& type) :
					type_(type) {};
				const char* what() const throw() {
					return "Invalid entrance type";
				}
				const char* get_type() {
					return type_.c_str();
				}
			private:
				std::string type_;
			};

			std::shared_ptr<LevelAddon> Create(const std::string& name) {
				for (auto it : LookupTable) {
					auto entrance = it.second;
					if (!_strcmpi(name.c_str(), entrance->GetName().c_str())) {
						return entrance;
					}
				}
				throw InvalidEntranceException(name);
			}
		}
	}
}