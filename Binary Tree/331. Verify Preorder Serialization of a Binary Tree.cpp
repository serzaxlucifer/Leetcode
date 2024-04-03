class Solution {
    int parseString(string& preorder, int& start)
    {
        if(preorder[start] == '#')
        {
            start++;
            return -1;
        }

        while(start < preorder.length() && preorder[start] != ',')
        {
            start++;
        }

        return 1;
    }
public:
    bool isValidSerialization(string preorder) 
    {
        if(preorder[0] == '#' && preorder.length() != 1)
        {
            return false;
        }
        int balance = 0;
        int hashes = 0;

        for(int i = 0; i < preorder.length(); i++)
        {
            int ans = parseString(preorder, i);
            if(ans == 1)
            {
                balance++;
            }
            else
            {
                hashes++;
                if(hashes == 2)
                {
                    hashes = 0;
                    balance--;
                    hashes++;
                }

                if(balance <= 0 && i != preorder.length())
                {
                    return false;
                }
            }
        }

        return balance == 0;
    }
};
