// Iterative processing:
    vector<string> letterCombinations(string digits) 
    {
        
        string combinations[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        int depth = digits.length();
        
        vector<string> aux;
        aux.push_back("");

        for(int i = 0; i < depth; i++)
        {
            vector<string> aux2;

            for(char c : combinations[digits[i] - '0'])
            {
                for(int j = 0; j < aux.size(); j++)
                {
                    aux2.push_back(aux[j] + string(1, c));
                }
            }

            aux = aux2;
        }

        return aux;
        
    }


// Recursive Processing:

class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
        
        vector<string> combinations = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        int depth = digits.length();
        
        vector<string> answer;

        solve(answer, digits, combinations, 0, "");

        return answer;
        
    }

    void solve(vector<string>& answer, string digits, vector<string>& data, int depth, string temp)
    {
        if(depth == digits.length())
        {
            if(depth != 0)
                answer.push_back(temp);
            return;
        }

        for(char c : data[digits[depth] - '0'])
        {
            solve(answer, digits, data, depth+1, temp + string(1, c));
        }
    }
};


