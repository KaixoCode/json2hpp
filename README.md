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

## Example

Here's an example of how it converts json to a C++ object. When it encounters an array of objects it tries to combine all the elements of the array into a single object so it can be stored inside an `std::array`. When it can't do that, when for example 2 of the elements contain the same key but with a different type, it will simply generate a struct containing all the fields, and their names will be numbered like `_0`, `_1`, etc. Strings will be generated as raw literals, and will be surrounded by the sequence `##`.

json:
```json
{
  "menu": {
    "id": "file",
    "value": "File",
    "popup": {
      "menuitem": [
        {
          "value": "New",
          "onclick": "CreateNewDoc()"
        },
        {
          "value": "Open",
          "onclick": "OpenDoc()"
        },
        {
          "value": "Close",
          "onclick": "CloseDoc()"
        }
      ]
    }
  }
}
```


C++:

```cpp
struct menuitem_3_t {
  std::string_view onclick;
  std::string_view value;
};

struct popup_2_t {
  std::array<menuitem_3_t, 3> menuitem;
};

struct menu_1_t {
  std::string_view id;
  popup_2_t popup;
  std::string_view value;
};

struct data_0_t {
  menu_1_t menu;
};

constexpr data_0_t data = {
  .menu = {
    .id = R"##(file)##", 
    .popup = {
      .menuitem = {{
        {
          .onclick = R"##(CreateNewDoc())##", 
          .value = R"##(New)##", 
        }, 
        {
          .onclick = R"##(OpenDoc())##", 
          .value = R"##(Open)##", 
        }, 
        {
          .onclick = R"##(CloseDoc())##", 
          .value = R"##(Close)##", 
        }, 
      }}, 
    }, 
    .value = R"##(File)##", 
  }, 
};
```


## json Object

`json2hpp.hpp` can also be used as a single header include to do json parsing in your own projects. It has a static method `std::optional<json> json::parse(std::string_view)` that can parse any valid json into a `json` object. You can then use `std::string json2hpp::generate("name", json)` to generate C++ code.

```cpp
#include "json2hpp.hpp"

constexpr auto data = R"({ "value" : 10 })";

int main() {
  using namespace kaixo;
  
  auto result = json::parse(data);
  if (result) {
    auto code = json2hpp::generate("data", result.value());
    ...
  }
}
```
