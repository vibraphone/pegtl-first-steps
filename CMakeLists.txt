cmake_minimum_required(VERSION 3.11)
project(curly)

set(PEGTL_BUILD_EXAMPLES OFF CACHE BOOL "Nope" FORCE)
set(PEGTL_BUILD_TESTS OFF CACHE BOOL "Nope" FORCE)
add_subdirectory(pegtl)

add_executable(ex1 ex1.cxx)
target_link_libraries(ex1 LINK_PUBLIC taocpp::pegtl)

add_executable(ex2 ex2.cxx)
target_link_libraries(ex2 LINK_PUBLIC taocpp::pegtl)

add_executable(ex3 ex3.cxx)
target_link_libraries(ex3 LINK_PUBLIC taocpp::pegtl)
