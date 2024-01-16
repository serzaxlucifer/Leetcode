class Solution {
public:
    int removeStones(vector<vector<int>>& stones) 
    {
        set<vector<int>> visited;
        int numOfIslands = 0;

        for(auto i : stones)
        {
            if(visited.find(i) == visited.end())
            {
                DFS(stones, i, visited);
                numOfIslands++;
            }
        }

        return stones.size() - numOfIslands;
    }

    void DFS(vector<vector<int>>& stones, vector<int>& s, set<vector<int>>& visited)
    {
        visited.insert(s);
        for(auto i : stones)
        {
            if(visited.find(i) == visited.end())
            {
                if(i[0] == s[0] || i[1] == s[1])
                {
                    DFS(stones, i, visited);
                }
            }
        }
    }
};

// THAT GIVES TLE
class Solution {
public:
    int dfs(vector<vector<int>>&stones,int index,vector<bool>&visited,int&n){
        visited[index]=true;
        int result=0;
        for(int i=0;i<n;i++)
            if(!visited[i]&&(stones[i][0]==stones[index][0]||stones[i][1]==stones[index][1]))
                result +=(dfs(stones,i,visited,n) + 1);
        return result;
    }
    int removeStones(vector<vector<int>>&stones) {
        int n = stones.size();
        vector<bool>visited(n,0);
        int result=0;
        for(int i=0;i<n;i++){
            if(visited[i]){continue;}
            result+=dfs(stones,i,visited,n);
        }
        return result;
    }

};

// dsu:

class UnionFind
{
    public:
    unordered_map<int, int> UF;
    int islands;

    UnionFind()
    {
        islands = 0;
    }

    int find(int x)
    {
        if (!UF.count(x)) 
        {
            UF[x] = x; 
            islands++;
        }
        if (x != UF[x]) UF[x] = find(UF[x]);
        return UF[x];
    }

    void connect(int p, int q)
    {
        int i = find(p);
        int j = find(q);

        if(i != j)
        {
            UF[i] = j;
            islands--;
        }
    }
};

class Solution {
public:
    
    int removeStones(vector<vector<int>>&stones) 
    {
        UnionFind UF;
        for (int i = 0; i < stones.size(); ++i)
        {
            UF.connect(stones[i][0], ~stones[i][1]);
        }

        return stones.size() - UF.islands;
    }

};
