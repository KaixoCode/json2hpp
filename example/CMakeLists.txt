set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/example/cmake/modules/")

add_executable(json2hpp_example
  "${json2hpp_SOURCE_DIR}/example/example.cpp"
  "${json2hpp_SOURCE_DIR}/example/assets/data.json"
)

include(json2hpp)

json2hpp(json2hpp_example
  "data" 
  "${json2hpp_SOURCE_DIR}/example/assets/data.json" 
  "${json2hpp_SOURCE_DIR}/example/generated/data.hpp"
)

target_include_directories(json2hpp_example PUBLIC
  "${json2hpp_SOURCE_DIR}/example/generated"
)