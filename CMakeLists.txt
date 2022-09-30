cmake_minimum_required (VERSION 3.0)
project (json2hpp)

set (CMAKE_CXX_STANDARD 23)

add_library(json2hpp_lib STATIC
  "${json2hpp_SOURCE_DIR}/json2hpp.hpp"
)

set_target_properties(json2hpp_lib PROPERTIES LINKER_LANGUAGE CXX)

add_executable(json2hpp
  "${json2hpp_SOURCE_DIR}/json2hpp.cpp"
)

add_subdirectory(example)