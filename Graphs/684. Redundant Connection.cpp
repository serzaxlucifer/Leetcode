// This is going to be interesting!
// Reference: (Archit91) https://leetcode.com/problems/redundant-connection/solutions/1295887/easy-solution-w-explanation-all-possible-approaches-with-comments/

class Solution {

    bool* cycle, *visited, found;
    int cycleStart = -1;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        // DFS based Solution!

        int n = edges.size();
        vector<int> adjacencyList[n+1];

        cycle = (bool*)calloc(n+1, sizeof(bool));
        visited = (bool*)calloc(n+1, sizeof(bool));

        for(auto& edge: edges)
        {
            adjacencyList[edge[0]].push_back(edge[1]), adjacencyList[edge[1]].push_back(edge[0]);
        }

        DFS(adjacencyList, 1);

        for(int i = n-1; ~i; i--)
        {
            if(cycle[edges[i][0]] && cycle[edges[i][1]])
            {
                return edges[i];
            }
        }

        return {};

    }

    void DFS(vector<int> adjL[], int start, int parent = -1)
    {
        if(visited[start])
        {
            cycleStart = start;
            found = true;
            return;
        }
        visited[start] = true;

        for(int i : adjL[start])
        {
            if(i == parent)
            {
                continue;
            }
            if(!found)
            {
                DFS(adjL, i, start);
            }
            if(cycleStart != -1)
            {
                cycle[start] = true;
            }
            if(start == cycleStart)
            {
                cycleStart = -1;
                return;
            }
        }
    }
};



