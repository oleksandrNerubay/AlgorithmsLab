/*
 * CSC-301
 * project2.cpp
 * Spring 2026
 *
 * Partner 1: Oleksandr Nerubay
 * Partner 2: Cora Sunsedeth
 * Date: 5/9/2026
 * Aknowledgements: Topic 10 - DFS/BFS Eric A. Autry (c) Copyright 2020. (Autry notes)
 * Sunjae Kim for helping me out figuring out the BFS traversal during one of the mentor sessions
 */
#include "project2.hpp"
using namespace std;
/*
 * Depth First Search
 */
vector<int> DFS(vector<Vertex> &adjList, Vertex &start, Vertex &exit) {
    // presetting visited array to be empty and
    // defaulting previous visited field to -1(to account for risidual information)
    for (int i = 0; i < adjList.size(); i++) {
        adjList[i].visited = false;
        adjList[i].previous = -1;
    }
    vector<int> path;
    bool neighborPushed = false;

    // create empty stack
    stack<int> vertexStack;
    // push start node onto stack
    vertexStack.push(start.label);
    // vertexStackDistance.push_back(distanceFromStart);

    while (vertexStack.size() != 0) { 
        // while the stack is not empty
        neighborPushed = false;
        // set the current node equal to the top of the stack,
        int curr = vertexStack.top(); 
        // popping it from stack
        vertexStack.pop();            

        // set the current node to be visited
        adjList[curr].visited = true; 

        // process node by adding it to the path & checking if it's found the exit
        path.push_back(curr);
        if (adjList[curr] == exit) {
            return path;
        }
        // for each neighbor in node's adjacency list
        for (int i = 0; i < adjList[curr].neighbors.size(); i++) { 
            int neighbor = adjList[curr].neighbors[i];
            // if neighbor is not visited
            if (adjList[neighbor].visited == false) { 
                // update previous, push neighbor onto stack and mark as visited
                adjList[neighbor].previous = curr;
                vertexStack.push(neighbor);
                neighborPushed = true;
            }
        }
        // if no neighbors were added to the stack that means we're at a dead end
        // so we retrace our steps
        if (neighborPushed == false) {
            vertexStack.push(adjList[curr].previous);
            vertexStack.push(adjList[curr].previous);
            path.pop_back();
            path.pop_back();
        }
    }

    return path;
}
/*
 * Breadth First Search
 */
vector<int> BFS(vector<Vertex> &adjList, Vertex &start, Vertex &exit) {
    // presetting visited array to be empty and
    // defaulting previous visited field to -1(to account for risidual information)
    for (int i = 0; i < adjList.size(); i++) {
        adjList[i].visited = false;
        adjList[i].previous = -1;
    }
    vector<int> path;

    queue<int> q;

    // pushing the root vertex and marking as visited
    q.push(start.label);
    adjList[start.label].visited = true;

    // as long as queue is not empty
    while (!q.empty()) { 
        // set the current element to the front of the queue
        int curr = q.front(); 
        // remove it from the queue
        q.pop(); 
        
        // if exit is found, reconstruct and return path
        if (adjList[curr] == exit) {
            // reconstruct the path by tracing previous pointers
            int trace = curr;
            // as long as there are still elements to trace
            while (trace != -1) {
                // insert one by one to the path
                path.push_back(trace); 
                // access previous neighbor
                trace = adjList[trace].previous; 
            }
            //traverse back through the path
            reverse(path.begin(), path.end());
            return path;
        }

    // Visit each unvisited neighbor of the current vertex,
    // record how we got there, and add it to the queue.
       for (int i = 0; i < (int)adjList[curr].neighbors.size(); i++) { 
            int neighbor = adjList[curr].neighbors[i];
            // if vertex is not visited mark it as it is
            if (!adjList[neighbor].visited) { 
                //set visited to true 
                adjList[neighbor].visited = true;    
                //switch to next neighbor
                adjList[neighbor].previous = curr;     
                // push neighbor to the queue              
                q.push(neighbor);                                    

            }
        }
    }
    return path;
}
