// Prioirty Queue Solution:

vector<string> findRelativeRanks(vector<int>& score) 
    {
        priority_queue<pair<int, int>> pq;
        int size = score.size();

        for(int i = 0; i < size; i++)
        {
            pq.push({score[i], i});
        }

        int i = 0;
        vector<string> answer(size);

        while(!pq.empty())
        {
            pair<int, int> p = pq.top();
            pq.pop();
            if(i == 0)
            answer[p.second] = "Gold Medal";
            else if(i == 1)
            answer[p.second] = "Silver Medal";
            else if(i == 2)
            answer[p.second] = "Bronze Medal";
            else
            answer[p.second] = to_string(i+1);
            i++;
        }

        return answer;
    }

// Without heap, (BETTER!)

vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int,int>> v;
        vector<string> ans(score.size());
        for(int i=0;i<score.size();i++){
            v.push_back({score[i],i});
        }
        sort(v.begin(),v.end(),greater());
        for(int i=0;i<v.size();i++){
            if(i==0){
                ans[v[i].second]="Gold Medal";
            }
            else if(i==1){
                ans[v[i].second]="Silver Medal";
            }
            else if(i==2){
                ans[v[i].second]="Bronze Medal";
            }
            else{
                ans[v[i].second]=to_string(i+1);
            }
        }
        return ans;
    }
