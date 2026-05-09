/*
 * CSC-301
 * project2.hpp
 * Spring 2026
 *
 * Partner 1: Oleksandr Nerubay
 * Partner 2: Cora Sunsedeth
 * Date:
 */

#ifndef PROJECT2_HPP_
#define PROJECT2_HPP_

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include "Vertex.hpp"

std::vector<int> DFS(std::vector<Vertex> &adjList, Vertex &start, Vertex &exit);
std::vector<int> BFS(std::vector<Vertex> &adjList, Vertex &start, Vertex &exit);

#endif  // PROJECT2_HPP_