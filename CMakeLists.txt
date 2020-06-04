cmake_minimum_required(VERSION 3.1)
project(ibus LANGUAGES C)

add_subdirectory(stm8spl)

add_executable(ibus)

add_dependencies(ibus stm8spl)
target_link_libraries(ibus stm8spl)

target_sources(ibus PRIVATE main.c)

target_include_directories(ibus PRIVATE stm8spl/include)
