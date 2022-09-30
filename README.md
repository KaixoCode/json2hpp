# json2hpp
This simple CMake module can convert a json file straight into a header file containing a constexpr C++ object. Check the example folder for an example.

Usage in your CMakeLists.txt is very straightforward, just make sure you include `json2hpp`, and then it's a simple macro call:

```cmake

json2hpp(target
  "name" 
  "...path/to/json.json" 
  "...path/to/generated/header.hpp"
)

```
