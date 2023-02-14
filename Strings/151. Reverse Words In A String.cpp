// My first solution:

string reverseWords(string s) {
        string output;
        int length = s.length();

        vector<string> temp;
        string aux = "";
        int i = 0;
        int fills = 0;

        while(s[i] == ' ')
        i++;

        for(; i < length; i++)
        {
            if(s[i] == ' ')
            {
                temp.emplace_back(aux);
                aux = "";
                while(s[i] == ' ')
                i++;
                fills++;
                i--;
            }

            else
            aux += s[i];
        }
        

        if(s[i-1] != ' ')
        {
            temp.emplace_back(aux);
            fills++;
        }
        

        for(int i = fills-1; i >= 0; i--)
        {
            output += temp[i];
            if(i!=0)
            output += ' ';
        }

        return output;
    }

// Using stringstream:

string reverseWords(string s) {
        string output;
        int length = s.length();
        reverse(s.begin(), s.end());

        string word;
        stringstream st(s);
        while(st >> word)
        {
            output += reversee(word) + " ";
        }

        return output.substr(0, output.length()-1);
    }

    string reversee(string input)
    {
        int i = 0, length = input.length() - 1;

        while(i < length)
        {
            char temp = input[i];
            input[i] = input[length];
            input[length] = temp;
            i++, length--;
        }

        return input;
    }

// another:

string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int l = 0, r = 0, i = 0, n = s.size();
        while (i < n) {
            while (i < n && s[i] != ' ')
                s[r++] = s[i++];

            if (l < r) { // if we can find a non-empty word then
                reverse(s.begin() + l, s.begin() + r); // reverse current word
                if (r == n) break;
                s[r++] = ' '; // set empty space
                l = r;
            }
            ++i; // now i == n or s[i] == ' ', so we skip that character!
        }
        if (r > 0 && s[r-1] == ' ') --r; // skip last empty character if have
        s.resize(r);
        return s;
    }
