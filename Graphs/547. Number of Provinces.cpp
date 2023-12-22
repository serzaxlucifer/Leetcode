class Solution 
{
    public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int provinces = 0;
        for(int i = 0; i < isConnected.size(); i++)
        {
            if(isConnected[i][i] == -1)
            {
                continue;
            }
            dfs(isConnected, i);
            provinces++;
        }

        return provinces;
    }

    void dfs(vector<vector<int>>& isConnected, int city)
    {
        isConnected[city][city] = -1;

        for(int i = 0; i < isConnected.size(); i++)
        {
            if(isConnected[city][i] && isConnected[i][i] != -1) 
            {
                dfs(isConnected, i);
            }
        }
    }
};
