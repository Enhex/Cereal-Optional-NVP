#include "cereal_optional_nvp.h"
#include <cereal/archives/json.hpp>
#include <fstream>


struct A
{
	int x, y, z;

	template <class Archive>
	void save(Archive & ar) const
	{
		ar(CEREAL_NVP(x),
			CEREAL_NVP(y),
			CEREAL_NVP(z));
	}

	template <class Archive>
	void load(Archive & ar)
	{
		CEREAL_OPTIONAL_NVP(ar, x);
		ar(CEREAL_NVP(y));
		cereal::load_optional_nvp(ar, "z", z);
	}
};

struct B
{
	int x, y, z;

	template <class Archive>
	void serialize(Archive & ar)
	{
		cereal::make_optional_nvp(ar, "x", x, []() {return true; });
		CEREAL_OPTIONAL_NVP(ar, y, []() {return true; });
		CEREAL_OPTIONAL_NVP(ar, z, []() {return true; });
	}
};


int main()
{
	{
		A a;
		a.x = a.y = a.z = 0; // Initialize with 0

		std::ifstream is("a.json");
		// load the file
		if (is.is_open())
		{
			cereal::JSONInputArchive inAr(is);
			inAr(CEREAL_NVP(a));
		}
		// generate structure example
		else
		{
			a.x = a.y = a.z = 1; // Save with value different from initial value to indicate when loading occured
			std::ofstream os("a.json");
			cereal::JSONOutputArchive outAr(os);
			outAr(CEREAL_NVP(a));
		}

		std::cout << a.x << " " << a.y << " " << a.z << '\n';
	}


	{
		B b;
		b.x = b.y = b.z = 0;	// Initialize with 0

		std::ifstream is("b.json");
		// load the file
		if (is.is_open())
		{
			cereal::JSONInputArchive inAr(is);
			inAr(CEREAL_NVP(b));
		}
		// generate structure example
		else
		{
			b.x = b.y = b.z = 1;	// Save with value different from initial value to indicate when loading occured
			std::ofstream os("b.json");
			cereal::JSONOutputArchive outAr(os);
			outAr(CEREAL_NVP(b));
		}

		std::cout << b.x << " " << b.y << " " << b.z << '\n';
	}
}