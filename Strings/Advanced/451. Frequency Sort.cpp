// My first solution using sort():

string frequencySort(string s) {
        map<char, int> map;
        for(char a : s)
        {
            map[a]++;
        }

        vector<string> store;
        store.reserve(s.size());
        for(auto& i : map)
        {
            store.push_back(string(i.second, i.first));  
        }


        sort(store.begin(), store.end(), [](const string& a, const string& b) {return a.length() >= b.length();});

        s = "";
        int size = store.size();
        for(int i = 0; i < size; i++)
        {
            s += store[i];
        }

        return s;
    }

// fails on test case: s = "AABBCCDDEEFFGGHHIIJJKKLLMMNNOOPPQQRRSSTTUUVVWWXXYYZZaabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz0011223344556677889"

string frequencySort(string s) {
        if (s.empty())
            return "";
        
        //populate map with chars and their # of occurence
        map<char,int> myMap;
        for (auto c : s)
            myMap[c]++;
        
        //store each char (by # of occurences) in a vector of strings
        vector<string> sVec;
        sVec.reserve(s.size());
        for (auto c : myMap){
            sVec.push_back(string(c.second, c.first));
        }
        
        //passing a lambda argument sort vector based on length of strings 
        sort(sVec.begin(), sVec.end(), [](const string& a, const string& b){
                return a.size() > b.size();
            });
        
        //populate return string
        string ret = "";
        for(auto it = sVec.begin(); it != sVec.end(); ++it)
            ret.append(*it);
        return ret;

    }

// But this one works. I can't find any difference.   [96% runtime]

// Moving on, this solution utilizes Bucket Sort    [33% runtime]

string frequencySort(string s) {
        vector<string> bucket(s.size()+1, "");
        unordered_map<char, int> map;
        int size = s.size();

        for(char a : s)
        {
            map[a]++;
        }

        for(auto& i : map)
        {
            bucket[i.second] += string(i.second, i.first);
        }

        s = "";
        for(int i = size; i > 0; i--) {
            if(!bucket[i].empty())
                s.append(bucket[i]);
        }
        return s;

    }


// This one utilizes Priority Queues. [seems to be best solution at 97% runtime]
string frequencySort(string s) {
        int frequency[256] = {0};
        priority_queue<pair<int, char>> pq;

        for(char a : s)
        frequency[a]++;
        s = "";

        for(int i = 0; i < 256; i++)
        {
            if(frequency[i])
            {
                pq.push({frequency[i], i});
            }
        }

        while(!pq.empty())
        {
            s += string(pq.top().first, pq.top().second);
            pq.pop();
        }

        return s;
    }




