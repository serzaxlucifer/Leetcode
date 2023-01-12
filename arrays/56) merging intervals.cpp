// first solution:

vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        for(auto i : intervals)
        {
            if(ans.empty() || ans.back()[1] < i[0])
            {
                ans.push_back(i);
            }
            else
            {
                ans.back()[1] = max(ans.back()[1], i[1]);
            }
        }

        return ans;
    }

// another solution: (better runtime somehow!)

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    std::vector<std::pair<int, int>> p;
    for (const auto& x : intervals) {
      p.emplace_back(x[0], -1);
      p.emplace_back(x[1], 1);
    }
    std::sort(p.begin(), p.end());
    vector<vector<int>> res;
    int balance = 0;
    int first = 0;
    for (const auto& x : p) {
      if (balance == 0) {
        first = x.first;
      }
      balance += x.second;
      if (balance == 0) {
        res.emplace_back() = {first, x.first};
      }
    }
    return res;
  }
