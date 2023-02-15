// My First Implementation:

string trueString(string s)
    {
        string output;
        int len = s.length();

        for(int i = 0; i < len; i++)
        {
            if(s[i] > 96 && s[i] < 123)
            {
                output += s[i];          
            }
            else if(s[i] > 64 && s[i] < 91)
            {
                output += (s[i]+32);
            }
            else if(s[i] > 47 && s[i] < 58)
            {
                output += s[i];
            }
        }
        return output;
    }

    bool isPalindrome(string s) {
        int start = 0;
        s = trueString(s);
        int end = s.length()-1;
        while(start < end)
        {
            if(s[start] != s[end])
            {
                return false;
            }
            start++, end--;
        }

        return true;
        
    }

// But this has a poor runtime of 55%. (7ms)

// To optimize, can I remove the other function and solve in a single iteration? Let's try!
bool isPalindrome(string s) {
        int start = 0;
        int end = s.length()-1;

        while(start < end)
        {
            if(s[start] < 48 || (s[start] > 57 && s[start] < 65) || (s[start] > 90 & s[start] < 97) || (s[start] > 122))
            {
                start++;
                continue;
            }
            else if(s[end] < 48 || (s[end] > 57 && s[end] < 65) || (s[end] > 90 & s[end] < 97) || (s[end] > 122))
            {
                end--;
                continue;
            }
            else if(s[start] != s[end])
            {
                if(s[start] > 47 && s[start] < 58 || s[start] != s[end]-32 && s[start]-32 != s[end])
                return false;
            }
            start++, end--;
        }

        return true;
    }

// This beats 94% solutions in runtime.


// To shorten the code even further, you can use isalnum() and toupper() inbuilt functions. They'll also produce a similarly good runtime, maybe better but I believe in making my own bread.
