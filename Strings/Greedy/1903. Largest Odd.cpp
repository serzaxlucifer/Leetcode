// Simply traverse in reverse order!

string largestOddNumber(string num) {
        int end = num.length() - 1;

        for(int i = end; i >= 0; i--)
        {
            if((num[i]-48)%2)
            {
                return num.substr(0, i+1);
            }
        }

        return "";
    }
