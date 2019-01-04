cmake_minimum_required(VERSION 3.12)
project(graph)

set(CMAKE_CXX_STANDARD 98)

add_executable(graph main.cpp)

#标题	来源	  正确  提交
#1253 Problem  A   DS图—图的邻接矩阵存储及度计算		569	1115
#1223 Problem  B   DS图遍历--深度优先搜索	BJC	574	848
#1224 Problem  C   DS图遍历--广度优先搜索	BJC	626	766
#1265 Problem  D   DS图—图的连通分量		286	499
#1231 Problem  E   DS树+图综合练习--构建邻接表

add_executable(dfs depth-first-search.cpp)
add_executable(bfs broad-first-search.cpp)
add_executable(connected_val subgraph.cpp)
add_executable(connect_chain related_linked_list.cpp)
add_executable(ddms dfs_inline.cxx)