cmake_minimum_required(VERSION 3.20)
project(SearchInJson)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(SearchInJson main.cpp)

target_link_libraries(SearchInJson PRIVATE nlohmann_json::nlohmann_json)
