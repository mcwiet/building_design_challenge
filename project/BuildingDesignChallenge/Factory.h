#pragma once
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

	template<typename Base>
	class AbstractFactory {
	public:
		virtual ~AbstractFactory() = default;
		std::unique_ptr<Base> Create() { return std::unique_ptr<Base>(CreateDerived()); }

	protected:
		virtual Base* CreateDerived() = 0;
	};

	template<typename Base, typename Derived>
	class Factory : public AbstractFactory<Base> {
	public:
		virtual ~Factory() = default;
		std::unique_ptr<Derived> Create() { return std::unique_ptr<Derived>(CreateDerived()); }
	private:
		virtual Derived* CreateDerived() override { return new Derived; }
	};
}