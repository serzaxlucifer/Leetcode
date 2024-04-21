class Solution {
public:

    vector<bool> findAnswer(int n, vector<vector<int>>& edges) 
    {
        vector<bool> res(edges.size());
        vector<vector<array<int, 2>>> al(n);
        for (int i = 0; i < edges.size(); ++i) 
        {
            const auto &e = edges[i];
            al[e[0]].push_back({e[1], i});
            al[e[1]].push_back({e[0], i});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> path(n, INT_MAX);    
        pq.push({0, 0});
        path[0] = 0;

        while(!pq.empty()) 
        {
            auto [len, i] = pq.top(); pq.pop();
            if (len == path[i])
                for (auto [j, e] : al[i])
                    if (len + edges[e][2] < path[j]) 
                    {
                        path[j] = len + edges[e][2];
                        pq.push({path[j], j});
                    }
        }
        pq.push({path[n - 1], n - 1}); // backtrack

        while (!pq.empty()) 
        {
            auto [len, i] = pq.top(); pq.pop();
            for (auto [j, e] : al[i])
                if (len - edges[e][2] == path[j]) 
                {
                    res[e] = true;
                    pq.push({path[j], j});
                }
        }

        return res;
    }
};
