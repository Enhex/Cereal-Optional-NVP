/*
The MIT License (MIT)

Copyright (c) 2017 Yehonatan Ballas

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef cereal_optional_nvp_h
#define cereal_optional_nvp_h


namespace cereal
{
	// Optionally load an NVP if its name equals to the current node's name
	// Loading members should be done in the same order they were saved
	template <class Archive, class T>
	void load_optional_nvp(Archive& ar, const char* name, T&& value)
	{
		const auto node_name = ar.getNodeName();
		if (!node_name)
			return;
		// if names are equal
		if (strcmp(name, node_name) == 0)
			ar(cereal::make_nvp(name, value));	// load the NVP. Advances to the next node
	}
}

#define CEREAL_OPTIONAL_NVP(ar, T) ::cereal::load_optional_nvp(ar, #T, T)


#endif//cereal_optional_nvp_h