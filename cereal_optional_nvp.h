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