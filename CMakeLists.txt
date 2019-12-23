cmake_minimum_required(VERSION 3.15)
project(ccc)

set(CMAKE_CXX_STANDARD 11)

add_executable(ccc main.cpp bits/stdc++.h)

add_executable(breakfast breakfast.cpp "Dec 15th/backpack.cpp")
add_executable(backpack "Dec 15th/backpack.cpp" "Dec 15th/bag2.cpp" "Dec 15th Homework/number_theory.cpp" "Dec 15th Homework/triangles.cpp" "Dec 15th/concatenate_parenthesis.cpp")
add_executable(bag2 "Dec 15th/bag2.cpp")
add_executable(number_theory "Dec 15th Homework/number_theory.cpp")