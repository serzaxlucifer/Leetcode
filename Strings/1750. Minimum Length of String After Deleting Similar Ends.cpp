    int minimumLength(string s) 
    {
        std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
        int left = 0, right = s.size() - 1;

        while(left < right && s[left] == s[right])
        {
            while(left < right && s[left+1] == s[left])
            {
                left++;
            }
            while(right > left && s[right-1] == s[right])
            {
                right--;
            }
            left++, right--;
        }

        if(right < left)
        {
            return 0;
        }

        return right - left + 1;
    }
