Input

First line contains positive integers n, m, s and f (n ≤ 5000, m ≤ 105, 1 ≤ s, f ≤ n, s ≠ f) - the number of vertices and edges in the graph and the numbers of vertices between which the length of the minimum path should be found.

Each of the next m lines contains three positive integers bi, ei и wi - the ends of the i-th edge and its weight (1 ≤ bi, ei ≤ n, 0 ≤ wi ≤ 105).

Output

Print in the first line the minimum weight of the path between vertices s and f. In the second line print the vertices on the shortest path from s to f in the bypass order, space separated. If the route from s to f does not exist, print -1.


Input example #1
4 4 1 3
1 2 1
2 3 2
3 4 5
4 1 4

Output example #1
3
1 2 3