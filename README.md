# Object Oriented Analysis of Algorithms Lab

This repository contains the source code developed for the Object Oriented Analysis of Algorithms lab. It demonstrates the use of object-oriented programming techniques in C++ to implement and analyze graph data structures. The project leverages operator overloading and the Standard Template Library (STL) to perform complex graph operations such as union, intersection, complement, and connectivity checks.

## Repository Structure

- lab3.cpp: The main source file that defines the Graph class and its methods. Key features include:
  - Operator Overloading:
    - '+' for merging (union) of two graphs.
    - '-' for computing the intersection of edges between two graphs.
    - '!' for generating the complement of the graph.
  - Core Graph Operations:
    - addEdge() and removeEdge() for modifying edges.
    - printGraph() for displaying the graph structure.
    - isReachable() for determining connectivity using breadth-first search (BFS).
  - Overloaded stream operators (>> and <<) for simple graph input/output.

## Compilation and Execution

To compile the project using g++, run:
    g++ lab3.cpp -o lab3 -std=c++11

To execute the program:
    ./lab3

## Runtime Commands

The application accepts the following commands to interact with the graph:
  - Graph: Initialize a new graph by specifying the number of vertices and edges.
  - printGraph: Display the current graph structure.
  - add_edge: Add an edge by providing two vertex indices.
  - remove_edge: Remove an edge between two specified vertices.
  - complement: Compute the complement of the graph.
  - isReachable: Check if there is a path between two vertices.
  - union: Merge another graph into the current graph.
  - intersection: Compute the intersection with another graph.
  - end: Terminate the program.

Explore and extend the functionalities as you experiment with diverse graph algorithms and techniques.

Happy coding!