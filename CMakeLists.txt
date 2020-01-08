cmake_minimum_required(VERSION 3.15)
project(ccc)

set(CMAKE_CXX_STANDARD 11)

add_executable(ccc Playground/main.cpp bits/stdc++.h)

add_executable(breakfast Playground/breakfast.cpp "Dec 15th/backpack.cpp")
add_executable(backpack "Dec 15th/backpack.cpp" "Dec 15th/bag2.cpp" "Dec 15th Homework/number_theory.cpp" "Dec 15th Homework/triangles.cpp" "Dec 15th/concatenate_parenthesis.cpp")
add_executable(bag2 "Dec 15th/bag2.cpp")
add_executable(number_theory "Dec 15th Homework/number_theory.cpp")
add_executable(triangles "Dec 15th Homework/triangles.cpp")
add_executable(1-2 Dec3/小胖老师ccc高级/1-2.cpp)
add_executable(ccc16s1 "Dec 22nd Homework/ccc16s1.cpp")
add_executable(ccc16s2 "Dec 22nd Homework/ccc16s2.cpp")
add_executable(ccc17s1 "Dec 15th Homework/ccc17s1.cpp")
add_executable(ccc17s2 "Dec 15th Homework/ccc17s2.cpp")
add_executable(ccc16s3 "Dec 22nd Homework/ccc16s3.cpp")
add_executable(ccc16s4 "Dec 22nd Homework/ccc16s4.cpp")