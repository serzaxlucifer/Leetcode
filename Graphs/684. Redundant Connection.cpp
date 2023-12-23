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
// DSU:
class Solution {
public:
    int findParent(int x, vector<int> &parent) 
    {
        if (parent[x] == x)
            return x;
        return parent[x] = findParent(parent[x], parent);               // path compression
    }
    bool Union(int p1, int p2, vector<int> &parent, vector<int> &rank) 
    {
    
        p1 = findParent(p1, parent);
        p2 = findParent(p2, parent);

        if (p1 == p2)
            return false;
        if (rank[p1] > rank[p2]) 
        {
            parent[p2] = p1;
        }   
        else if(rank[p2]>rank[p1])
        {
            parent[p1] = p2;
        }
        else
        {
            rank[p1]++;
            parent[p2]=p1;
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges) 
    {
        int n = edges.size();
        vector<int> parent(n + 1);
        
        for (int i = 0; i <= n; i++)
            parent[i] = i;

        vector<int> rank(n + 1, 0);

        for (int i = 0; i < n; i++) 
        {
            if (!Union(edges[i][0], edges[i][1], parent, rank)) // !Union-> means they are already connected
                return edges[i];
        }
        return {};
    }
};



