/*
  "Reduction of LCA to RMQ Algorithm using Euler's Tour and Reduction to LCA itself!

Algorithms to Learn (Different Ways to do): Offline Tarjan, Sparse table based RMQ with and without Euler Tour or Segment Tree RMQ with and without Euler Tour .
Most Optimal Approach: Segment Tree RMQ but others are also optimal approaches. STreeRMQ has just a bit less pre-processing time and it can also handle online data! Sparse Table will struggle with online data.

Learning Guide (EXPLORE ALL BEFORE BEGINNING TO UNDERSTAND ANY SOLUTION OF THIS!):

Once you've broken down the problem to LCA (use hints on leetcode page!), use any of these approaches:

1. Off-line Tarjan's Algorithm: https://cp-algorithms.com/graph/lca_tarjan.html 

2. Sparse Table Based LCA Implementation: https://cp-algorithms.com/graph/lca_binary_lifting.html (shortest)

3. Euler's Tour Reduction to RMQ Approaches: Intuition and Reduction: https://www.geeksforgeeks.org/find-lca-in-binary-tree-using-rmq/ 
    a) Segment Tree RMQ [used in code in next cell]: https://www.geeksforgeeks.org/find-lca-in-binary-tree-using-rmq/ / https://www.geeksforgeeks.org/segment-tree-range-minimum-query/ 
    b) Sparse Table RMQ: https://www.geeksforgeeks.org/sparse-table/ 
    [Must Read for this] Pre-Req) Euler's Tour: https://www.geeksforgeeks.org/euler-tour-tree/ 

Segment Tree Beginners, look here: (this is what I referred to) https://www.geeksforgeeks.org/introduction-to-segment-trees-data-structure-and-algorithm-tutorials/ "

*/

class Solution {
public:
    vector<array<int, 27>> freq;    // Define frequency!
    vector<int> height, id, euler;  // For reduction to RMQ.
    vector<int> segmentTree;        // Faster pre-processing than 2d array based RMQ.

    void eulerTour(int node, int parent, vector<vector<pair<int, int>>> &adjList, array<int, 27> &freq, int height = 0) 
    {
        this->freq[node] = freq;
        this->height[node] = height;
        id[node] = euler.size();
        euler.push_back(node);    
        for (auto [j, w] : adjList[node]) 
        {
            if (j != parent) 
            {
                ++freq[w];
                eulerTour(j, node, adjList, freq, height + 1);
                euler.push_back(node);
                --freq[w];
            }
        }
    }

    void buildSegmentTree(int node, int start, int end)
    {
        if(start == end)
        {
            segmentTree[node] = euler[start];
        }

        else
        {
            int mid = (start + end)/2;
            buildSegmentTree(node << 1, start, mid); buildSegmentTree(node << 1 | 1, mid + 1, end);
            int left = segmentTree[node << 1], right = segmentTree[node << 1 | 1];
            segmentTree[node] = (height[left] < height[right]) ? left : right;
        }
    }

    int RMQ(int node, int start, int end, int leftNode, int rightNode)
    {
        if (start > rightNode || end < leftNode)
        {
            return -1;
        }

        if (start >= leftNode && end <= rightNode)
        {
            return segmentTree[node];
        }

        int mid = (start+end)/2;

        int left = RMQ(node << 1, start, mid, leftNode, rightNode);
        int right = RMQ(node << 1 | 1, mid+1, end, leftNode, rightNode);

        if (left == -1) 
        {
            return right;
        }
 
        else if (right == -1) 
        {
            return left;
        }
 
        return (height[left] < height[right]) ? left : right; 
    }

    int LCA(int u, int v)
    {
        int index = RMQ(1, 0, euler.size() - 1, min(id[u], id[v]), max(id[u], id[v]));
        return index;
    }

    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) 
    {
        // Reduction to RMQ - Euler's Tour

        vector<vector<pair<int, int>>> adjList(n);
        vector<int> answer;

        for (const auto &e : edges) 
        {
            adjList[e[0]].push_back({e[1], e[2]});
            adjList[e[1]].push_back({e[0], e[2]});
        }

        freq = vector<array<int, 27>>(n);
        height = id = vector<int>(n);
        eulerTour(0, -1, adjList, array<int, 27>() = {}); 
        segmentTree.resize(euler.size() * 4);
        buildSegmentTree(1, 0, euler.size() - 1);

        for(const auto &q: queries)
        {
            int u = q[0], v = q[1];
            int a = LCA(u, v);

            int total = 0, max_f = 0;
            for (int i = 1; i < 27; ++i) 
            {
                total += freq[u][i] + freq[v][i] - 2 * freq[a][i];
                max_f = max(max_f, freq[u][i] + freq[v][i] - 2 * freq[a][i]);
            }

            answer.push_back(total - max_f);
        }

        return answer;


    }
};
