// My first (kind of) brute implementation:

    string minWindow(string s, string t) 
    {
        int start = 0;
        int end = 0;
        int endd = 0;
        int length = 0;
        int minLength = INT_MAX;
        int minStart = 0;
        int minEnd = 0;

        unordered_map<char, int> target;
        unordered_map<char, int> window;
        unordered_set<char> goal;

        for(int i = 0; i < t.length(); i++)
        {
            target[t[i]]++;
            goal.insert(t[i]);          // unordered_set avoids redundancy on its own.
        }

        bool done = true;

        for(; end < s.length(); end++)
        {
            length++;
            char a = s[end];
            if(!goal.empty() && goal.find(a) != goal.end())
            {
                done = false;
                window[a]++;
                if(window[a] == target[a])
                {
                    goal.erase(a);
                }
            }
            else if(window.find(a) != window.end())
            {
                done = false;
                window[a]++;
            }

            if(goal.empty() && target.find(a) != target.end())
            {
                if(done)
                    window[a]++;
                done = true;
                while(target.find(s[start]) == target.end() || window[s[start]] > target[s[start]])
                {
                    if(window.find(s[start]) != window.end())
                    {
                        window[s[start]]--;
                    }
                    start++;
                    length--;
                }
                if(minLength > length)
                {
                    minLength = length;
                    minStart = start;
                    minEnd = end;
                }
            }
        }

        if(!goal.empty())
        {
            return "";
        }

        return s.substr(minStart, minEnd-minStart+1);
    }

// Optimizing data structure usage and algorithm logic: RUNTIME: 7ms \ 

    string minWindow(string s, string t) 
    {
        int start = 0;
        int minLength = INT_MAX;
        int minStart = 0;
        int minEnd = 0;
        int targetCount = t.length();
        int count = 0;

        int target[255] = {0};
        int window[255] = {0};

        for(int i = 0; i < t.length(); i++)
        {
            target[t[i]]++;
        }

        for(int i = 0; i < s.length(); i++)
        {
            char a = s[i];
            bool imp = false;
            if(target[a])
            {
                window[a]++;
                imp = true;
            }

            if(count < targetCount && imp)
            {
                if(window[a] <= target[a])
                    count++;
            }

            if(count == targetCount && imp)
            {
                while(target[s[start]] == 0 || window[s[start]] > target[s[start]])
                {
                    if(window[s[start]] > 0)
                    {
                        window[s[start]]--;
                    }
                    start++;
                }

                if(minLength > i-start+1)
                {
                    minLength = i-start+1;
                    minStart = start;
                    minEnd = i;
                }
            }
        }

        if(count < targetCount)
        {
            return "";
        }

        return s.substr(minStart, minEnd - minStart + 1);
    }

// Further revamping the construct:

string minWindow(string s, string t) 
    {
        int start = 0;
        int minLength = INT_MAX;
        int minStart = 0;

        if(s.length() < t.length())
        {
            return "";
        }

        int target[128] = {0};
        int numsCovered = 0;

        for(int i = 0; i < t.length(); i++)
        {
            if(target[t[i]]++ == 0)
                numsCovered++;
        }

        for(int i = 0; i < s.length(); i++)
        {
            char a = s[i];
            if (target[s[i]]-- == 1)
            {
                numsCovered--;
            }

            while(numsCovered == 0)
            {
                if(minLength > i-start+1)
                {
                    minLength = i-start+1;
                    minStart = start;
                }

                if(target[s[start++]] ++ == 0)
                {
                    numsCovered++;
                }
            }
        }

        if(minLength == INT_MAX)
        {
            return "";
        }

        return s.substr(minStart, minLength);
    }
