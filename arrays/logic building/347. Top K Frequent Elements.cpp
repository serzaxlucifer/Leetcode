    vector<int> topKFrequent(vector<int>& arr, int k) 
    {
        unordered_map<int, int> mpp;
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++) {
            mpp[arr[i]]++;
        }
        // Define a min-heap based on frequency
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minH;

        // Populate the min-heap with frequency and element pairs
        for (auto it : mpp) {
            minH.push({it.second, it.first});
            if (minH.size() > k)
                minH.pop();
        }
        while (!minH.empty()) {
            ans.push_back(minH.top().second);
            minH.pop();
        }
        return ans;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        // BUCKET SORT

        vector<vector<int>> buckets(nums.size()+1, vector<int>());
        unordered_map<int, int> count;

        for(int i : nums)
        {
            count[i]++;
        }

        for(pair<int, int> p : count)
        {
            buckets[p.second].push_back(p.first);
        }

        int lim = 0;
        vector<int> soln;
        for(int i = nums.size(); i >= 0; i--)
        {
            if(soln.size() > k-1)
            {
                break;
            }
            for(int j : buckets[i])
            {
                soln.push_back(j);
            }
        }

        return soln;
    }
