# Cereal-Optional-NVP
Implementation of optionally loading  name value pairs if they exist for [Cereal](http://uscilab.github.io/cereal/).

## Usage
Include the single header `cereal_optional_nvp.h`

In you serialization `load` function you can use either `load_optional_nvp` or the macro `CEREAL_OPTIONAL_NVP` which will use the variable name as the NVP name.

For example:
```C++
template <class Archive>
void load(Archive & ar)
{
  ar(CEREAL_NVP(x));
  CEREAL_OPTIONAL_NVP(ar, y);
  cereal::load_optional_nvp(ar, "z", z);
}
```

Loading objects must be done in the same order they're saved.

## License
MIT
