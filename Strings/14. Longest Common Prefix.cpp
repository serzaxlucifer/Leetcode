 string longestCommonPrefix(vector<string>& strs) {
        string output = "";
        int cut = -1;
        if(strs.size() == 1)
        {
            return strs[0];
        }
        int maxCut = strs[0].length();
        for(int i = 0; i < strs.size() - 1; i++)    // start comparing 2 consecutive strings and find the max common and then keep pruning it.
        {
            for(int j = 0; j < strs[i].length() && j < strs[i+1].length() && j <= maxCut; j++)
            {
                if(strs[i][j] != strs[i+1][j])
                {
                    break;
                }
                cut = j;
            }
            maxCut = cut;
            cut = -1;
        }

        for(int i = 0; i <= maxCut; i++)
        {
            output += strs[0][i];
        }
        return output;
    }
