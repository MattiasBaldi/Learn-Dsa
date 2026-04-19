/**
 * https://www.geeksforgeeks.org/dsa/graph-and-its-representations/
 */


 /*
 [ 
  0, 

We use an adjacency matrix to represent connections between vertices.
Initially, the entire matrix is filled with 0s, meaning no edges exist.
There is an edge between vertex 0 and vertex 1,so we set mat[0][1] = 1 and mat[1][0] = 1.
There is an edge between vertex 0 and vertex 2,so we set mat[0][2] = 1 and mat[2][0] = 1.
There is an edge between vertex 1 and vertex 2,so we set mat[1][2] = 1 and mat[2][1] = 1.
  
 ]
 */