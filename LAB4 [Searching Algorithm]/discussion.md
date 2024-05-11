# Performance Analysis of Graph Searching Algorithms

## Overview
This README provides insights into the runtime performance of two fundamental graph searching algorithms: Breadth First Search (BFS) and Depth First Search (DFS).

## Graph Representation
The graph utilized in this analysis consists of randomly generated edges with sizes ranging from 10,000 to 100,000.

## Observations
- The graph illustrates the comparative runtime of BFS and DFS.
- Notably, DFS exhibits faster performance than BFS within the specified range of random edge sizes.
- A key factor contributing to DFS's speed advantage is its propensity for depth-first traversal, which offers reduced memory overhead and the potential for early termination, particularly in graphs with numerous nodes or edges.

## Considerations
- While DFS proves advantageous in terms of speed, it's essential to acknowledge the tradeoff between the two algorithms.
- BFS remains preferable in scenarios where the primary objective is to find the shortest path or when the target node is expected to be in close proximity. Despite DFS's efficiency, BFS's ability to prioritize breadth ensures optimal outcomes in such cases.

This analysis underscores the significance of selecting the appropriate graph searching algorithm based on the specific requirements and characteristics of the problem at hand.