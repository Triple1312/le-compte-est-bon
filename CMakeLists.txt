cmake_minimum_required(VERSION 3.21)
project(le_compte_est_bon)

set(CMAKE_CXX_STANDARD 14)

add_executable(le_compte_est_bon main.cpp src/Problem.cpp src/Problem.h src/State.cpp src/State.h src/Tree.cpp src/Tree.h src/Operation.cpp src/Operation.h src/Agent.cpp src/Agent.h src/Input.cpp src/Input.h src/random.hpp)

add_executable(rand rand.cpp src/Problem.cpp src/Problem.h src/State.cpp src/State.h src/Tree.cpp src/Tree.h src/Operation.cpp src/Operation.h src/Agent.cpp src/Agent.h src/Input.cpp src/Input.h )

add_executable(test test.cpp src/Problem.cpp src/Problem.h src/State.cpp src/State.h src/Tree.cpp src/Tree.h src/Operation.cpp src/Operation.h src/Agent.cpp src/Agent.h src/Input.cpp src/Input.h )
