cmake_minimum_required(VERSION 3.16)

project(uninstall_tools)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED COMPONENTS filesystem)

add_executable(uninstall_manifest src/uninstall_manifest.cpp)
target_link_libraries(uninstall_manifest Boost::filesystem)
install(TARGETS uninstall_manifest DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/../../../bin/)