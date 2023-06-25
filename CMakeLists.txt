cmake_minimum_required(VERSION 3.25)
project(cmake)

set(CMAKE_CXX_STANDARD 17)

add_executable(cmake Menu/Main.cpp Menu/Main.cpp Menu/MST.cpp Graph/GraphMatrix.cpp Graph/GraphList.cpp Time/Time.cpp Time/AutomaticTest.cpp Algorithms/Join.cpp Algorithms/Kruskal.cpp Algorithms/Prim.cpp Algorithms/Dijkstra.cpp Algorithms/BellmanFord.cpp Menu/ShortestPathMenu.cpp Menu/MST.cpp)
