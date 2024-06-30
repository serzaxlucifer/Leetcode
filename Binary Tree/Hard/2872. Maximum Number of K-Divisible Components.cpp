// This question involves 'BFS on leaves'. It is important to note that each leaf will definitely belong to a component. So we start BFS from leaves and it makes our work all the more easy!
// Also since sum of all nodes is divisible by 'k' (provided in constraints), then we can find components whose sums are divisible by 'k' be it one component or more.

// Then to achieve maximum components, start creating components with sum such that it is divisible by 'k'. If not then add more nodes to it until it is divisible by 'k'. We are guaranteed
// to find more components with sum divisible by 'k' from whatever nodes are left after finding our first component. Because NETSUM is divisible by 'k' (say k*n). You just found a component with sum
// divisible by 'k' (say = k*m), so sum of remaining nodes = k*n - k*m = k(n- m) [still divisible by 'k'!]. Suppose 'k' = 6 and you found a component of sum = 12. Then don't grow it to other multiples
// of 6 like 18 or anything since that will combine two possible components into one. Just combine till first multiple of 'k' is observed. 

// Now, each leaf node must be part of some component. Run BFS from each leaf node. If node sum % k == 0, BAM! you found one component. If not, grow the component from this node. Add it to its
// parent node. You have no other choice to make a sum divisible by k component. Also you are guaranteed to find at least one component (in that case the entire tree as component) with sum divisible
// by 'k'. Next, if all of parent's children have been processed then add it to BFS queue to further identify components. 

// You could also do DFS. But whenever we create components out of tree by removing edges, I always prefer BFS on Leaves. This BFS code gives 98% runtime on leetcode and 81% memory score.

// Another possible way of imagining this is you spread out the tree like this:
/*

                7
                |         8
          9 --- 1 --- 10  |
                |         5 --- 6
                |        /
         3----- 1 ------1            13
                |        \          /
                |         11 ----- 12 ----- 15
                4         |         \
                          16         14

          Now, start creating components from leaves. Suppose these numbers represent value of nodes. Suppose 'k' = 17. In the best case, if each node value is 17, we can remove all
          edges and number of components = number of nodes! (check this first)

          Now we'll start BFS on leaf nodes, thus queue = {7, 9, 10, 8, 6, 13, 15, 14, 16, 4, 3}

          First we pop {7}, It must belong to a component ovbiously! It can't stand on its own (7 % 17 != 0) so we will need to combine it with its parent. We can't remove this edge.
          Thus, add its value to its parent i.e. '1'. Updated tree becomes:

                          
                          8
          9 --- 8 --- 10  |
                |         5 --- 6
                |        /
         3----- 1 ------1            13
                |        \          /
                |         11 ----- 12 ----- 15
                4         |         \
                          16         14

          Next you pop 9 from queue and you again see that nope, we need to combine it with parent i.e. 8! 

          Updated tree:
                          8
               17 --- 10  |
                |         5 --- 6
                |        /
         3----- 1 ------1            13
                |        \          /
                |         11 ----- 12 ----- 15
                4         |         \
                          16         14

          Now pop off 10, NOTICE: If 10 wasn't there, we'd have found '17' in previous step to contain no more children so we could add it to BFS queue. When '17' would be popped,
          we'd see that 17% 17 = 0 thus we have found one component! And its sum wouldn't be passed to its parent to ensure we're making maximum components. and simply removed from tree.
          Thus you could delete edge between 1 and 17. 

          But now 17 has a child '10'! Problem! 10 can't exist on its own. So we must add it to its parent's component. Thus tree becomes: Also add parent to BFS queue!
          New BFS queue = {8, 6, 13, 15, 14, 16, 4, 3, 27}   // 27 added to queue!

                          8
               27         |
                |         5 --- 6
                |        /
         3----- 1 ------1            13
                |        \          /
                |         11 ----- 12 ----- 15
                4         |         \
                          16         14

          Now, we keep on processing and once 27 is again popped, it will be added to parent's component since 27 % 17 != 0. This traversal ensures we're only removing edges that ensure
          we'll find other components optimally. We're aren't brute testing by randomly trying to remove edges.

          In the end, you can see this tree can't be divided into any component with sum diviisble by 17 so entire tree will sum upto one node = 136 which is divisible by 17. So ans = .
*/

class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) 
    {
        if(all_of(begin(values), end(values), [&](int v) { return v % k == 0; }))
        {
            return n;
        }

        vector<vector<int>> adjList(n, vector<int>());

        for(int i = 0; i < n - 1; i++)
        {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> queue, count(n);

        for(int i = 0; i < n; i++)
        {
            if(adjList[i].size() == 1)
            {
                queue.push_back(i);
            }
            count[i] = adjList[i].size();
        }

        return BFS(values, k, queue, adjList, count);          // start from leaf nodes. start making components!
    }

    int BFS(vector<int>& values, int k, vector<int>& queue, vector<vector<int>>& children, vector<int>& count)
    {
        int answer = 0;

        while(!queue.empty())
        {
            vector<int> newQueue;
                
            for(int node : queue)
            {
                if(values[node] % k == 0)
                {
                    answer++;
                }
                
                for(int child : children[node])
                {
                    values[child] += (values[node] % k);
                    count[child]--;

                    if(count[child] == 1)
                    {
                        newQueue.push_back(child);
                    }
                }
            }

            swap(queue, newQueue);
        }

        return answer;
    }
};
