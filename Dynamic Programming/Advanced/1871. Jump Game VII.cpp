// A recursive construct looks like this:

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) 
    {
        return aux(s, minJump, maxJump, 0);
    }

    bool aux(string s, int minJump, int maxJump, int start)
    {
        if(start >= s.length()-1)
        {
            return true;
        }

        bool reach = false;

        for(int i = min(start + maxJump, (int)s.length()-1); i >= start + minJump; i--)
        {
            if(s[i] == '0')
            {      
                reach = aux(s, minJump, maxJump, i);
            }
            if(reach)
            {
                return true;
            }
        }

        return false;
    }
};

// It is efficient in time BUT... memory limits are exceeded due to call stack on a specific example.
// Solution is to use an iterative solution. Can we convert to an iterative solution?

bool canReach(string s, int mi, int ma) 
    {
        if(s.back()=='1')
            return false; 

        vector<bool>dp(s.size());
        dp[0] = true;
        int count = 0;

        for(int i = 1; i<s.size(); i++){
            if(i>ma)
            {
                count-=dp[i-ma-1]; //Moving sliding window forward by decrementing the count by the dp value of the index that is no longer in our window
            }
            if(i>=mi)
            {
                count+=dp[i-mi];
            }
            if(count>0&&s[i]=='0')
                dp[i] = true;
            else 
                dp[i] = false;
        }
        return dp.back();
    }

// Deque:

bool canReach(string s, int minJump, int maxJump) {
        if (s.back() == '1')
            return false;

        deque<int> stairs;
        stairs.push_back(0);
        for (int i = minJump; i < s.size() && !stairs.empty(); i++) {
            if (s[i] == '1') continue;

            while (!stairs.empty() && i - stairs.front() > maxJump)
                stairs.pop_front();

            if (!stairs.empty() && (i - stairs.front() >= minJump))
                stairs.push_back(i);
        }

        return !stairs.empty() && stairs.back() == s.size() - 1;
    }
