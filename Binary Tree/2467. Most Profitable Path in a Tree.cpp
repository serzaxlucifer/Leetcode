class Solution {
public:


    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) 
    {
        int size = edges.size() + 1;
        vector<vector<int>> adjList(size, vector<int>());

        for(auto i : edges)
        {
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
        }
        vector<vector<int>> UpList(size, vector<int>());
        vector<vector<int>> DownList(size, vector<int>());

        queue<pair<int, int>> BFS;
        BFS.push({0, -1});

        while(!BFS.empty())
        {
            int pop = BFS.back().first; 
            int prevNode = BFS.back().second;
            BFS.pop();

            for(int i = 0; i < adjList[pop].size(); i++)
            { 
                if(adjList[pop][i] != prevNode)
                {
                    DownList[pop].push_back(adjList[pop][i]);
                    UpList[adjList[pop][i]].push_back(pop);
                    BFS.push({adjList[pop][i], pop});
                }
            }
        }

        vector<vector<int>> dp(size, vector<int>(size, INT_MIN));      // removes TLE (still time = 5%) but MLE still present.
        int maxProfit = DFS(0, bob, amount, UpList, DownList, dp);

        return maxProfit;
        
    }

    int DFS(int alice, int bob, vector<int> amount, vector<vector<int>>& UpList, vector<vector<int>>& DownList, vector<vector<int>>& dp)
    {
        if(DownList[alice].size() == 0)
        {
            return alice == bob ? amount[alice]/2 : amount[alice];
        }

        int amt = amount[alice];

        int balance = INT_MIN;
        amount[alice] = 0;
        amount[bob] = 0;

        if(dp[alice][bob] != INT_MIN)
        {
            return dp[alice][bob];
        }

        if(bob == 0)
        {
            for(int i = 0; i < DownList[alice].size(); i++)
            {
                balance = max(balance, DFS(DownList[alice][i], 0, amount, UpList, DownList, dp));
            }
        }
        else
        {
            for(int i = 0; i < DownList[alice].size(); i++)
            {
                for(int j = 0; j < UpList[bob].size(); j++)
                {
                    balance = max(balance, DFS(DownList[alice][i], UpList[bob][j], amount, UpList, DownList, dp));
                }
            }
        }

        if(balance == INT_MIN)
            balance = 0;

        return dp[alice][bob] = balance + (alice == bob ? amt/2 : amt);
    }
};

// This brute force simulation will give Memory Limit Exceeded and Time Limit Exceeded!!
// Now analyze and think of simpler solutions, removing the for loops at least.
// Notice number 1: For UpList, you ONLY require to calculate parents of each node!
// Notice number 2: To avoid nested for loops in DFS(), we can pre-compute distance from root node to each node. That will answer if Bob could have reached there or not. Note 
// that Bob will always follow the same path up to root due to Tree Property. The tree only coverges towards the root and diverges from the root (so Alice has a diverging path
// and bob has a converging path.)

class Solution {
public:
    vector<vector<int>>adj;
    vector<int>par,dis;
	//Find the parent and distance from node 0
    void dfs(int u,int p = 0,int d = 0){
        dis[u] = d;
        par[u] = p;
        for(int v:adj[u]){
            if(v==p)continue;
            dfs(v,u,d+1);
        }
    }
	// Find total sum to each node
    int dfs2(int u,vector<int>&amount,int p= 0){
        int ret = amount[u];
        int mxc = -INT_MAX;
        for(int v:adj[u]){
            if(v!=p){
                mxc= max(mxc,dfs2(v,amount,u));
            }
        }
		//if the node is leaf we just return its amount
        if(mxc==-INT_MAX)return ret;
        else return ret+mxc;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        adj.resize(n,vector<int>());
        for(auto&e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        par.resize(n);
        dis.resize(n);
        dfs(0);
        int cur = bob;
        int bob_dis = 0;
		//update the path of from Bob to 0
        while(cur!=0){
            if(dis[cur]>bob_dis){
                amount[cur] = 0;
            }else if(dis[cur]==bob_dis){
                amount[cur]/=2;
            }
            cur = par[cur];
            bob_dis++;
        }
        return dfs2(0,amount);
    }
};


// Can we use a single DFS traversal?! i.e. Can we merge functionality of DFS1 and DFS2?

    vector<vector<int>>adj;
    vector<int>disFromBob;
    int bobNode;
    int dfs(int u,int par,int depth,vector<int>&amount){
        int ret = 0;
        if(u==bobNode) disFromBob[u] = 0;
        else disFromBob[u] = amount.size();
        int maxChild = -INT_MAX;
        for(int v:adj[u]){
            if(v==par)continue;
            maxChild = max(maxChild,dfs(v,u,depth+1,amount));
            disFromBob[u] = min(disFromBob[u],disFromBob[v]+1);
        }
        if(disFromBob[u]>depth)ret+=amount[u];
        else if(disFromBob[u]==depth)ret+=amount[u]/2;
        if(maxChild==-INT_MAX) return ret;
        else return ret+maxChild;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        bobNode = bob;
        adj.resize(n,vector<int>());
        for(auto&e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        disFromBob.resize(n);
        return dfs(0,0,0,amount);
    }
