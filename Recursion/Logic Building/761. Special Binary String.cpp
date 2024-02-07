/*
  SOLUTION EXPLANATION courtesy of leetcode/alexander: https://leetcode.com/problems/special-binary-string/solutions/113212/think-of-it-as-valid-parentheses/ 


  According to the description , there are 2 requirement for Special-String
 sub-VPs in a VP to make it bigger. If we look at this example : "()(())" or "101100", how would you make it bigger?
  Answer is, by moving the 2nd sub-string to the front. Because deeply nested VP contains more consecutive '('s or '1's in the front. That will make reordered string bigger.

  1) The number of 0's is equal to the number of 1's.
  2) Every prefix of the binary string has at least as many 1's as 0's.
  The 2nd definition is essentially saying that at any point of the string, you cannot have more 0's than 1's.

  If we map '1' to '(', '0's to ')', a Special-String is essentially Valid-Parentheses, therefore share all the properties of a Valid-Parentheses
  A VP (Valid-Parentheses) have 2 form:

  1. single nested VP like "(())", or "1100";
  2. a number of consecutive sub-VPs like "()(())", or "101100", which contains "()" + "(())" or "10" + "1100"
  And this problem is essentially ask you to reorder the
  The above example is straitforward, and no recursion is needed. But, what if the groups of sub-VPs are not in the root level?
  Like if we put another "()(())" inside "()(())", like "()(( ()(()) ))", in this case we will need to recursively reorder the children, make them MVP(Max-Valid-Parentheses), then reorder in root.

  To summarize, we just need to reorder all groups of VPs or SS's at each level to make them MVP, then reorder higher level VPs;

*/

/*
  Additional Important Inferences:   [courtesy of https://leetcode.com/problems/special-binary-string/solutions/113211/java-c-python-easy-and-concise-recursion/comments/281761]

  
1. Each special string starts with 1 and ends with 0
2. Any special string can be broken into n pieces of 
    consecutive special strings.

  == Proof of 1 ==
  By definition, special has to start with 1. Otherwise, 
  0, as a prefix, will be a counter example of prefix having
  more zeros than 1s.
  In addition, it also has to end with zero. Otherwise, consider
  a special string S, its prefix S[:-1] (S with last character excluded)
  will have more zeros than ones. Why ? since S has equal number
  of ones and zeros. If last one is 1, then S[:-1] has n-1 ones and n 
  zeros (suppose originally S has n zeros and n ones)
  
  == Proof of 2 ==
  To prove this claim, we alternatively just need
  to prove that for any special string, after we take shortest
  prefix special string, rest of the string is still a special
  special string). 
  Say S is a special string, and m is the shortest prefix of S that
  is a special string, and n represent the rest part of the S.
  Then we have S = m + n. At this time, both m and n have equal
  number of 1s and 0s. We prove by contradiction here. So
  we suppose that n is not a special string. Then it must be that

*/
    string makeLargestSpecial(string s) 
    {
        int i = 0;
        vector<string> result;
        string res;
        int balance = 0;

        for(int j = 0; j < s.length(); j++)
        {
            if(s[j] == '1')
            {
                balance++;
            }
            else
            {
                balance--;
            }
            if(balance == 0)
            {
                result.push_back('1' + makeLargestSpecial(s.substr(i + 1, j - i - 1)) + '0');
                i = j + 1;
            }
        }

        sort(result.begin(), result.end(), greater<string>());
        for(int i = 0; i < result.size(); i++)
        {
            res += result[i];
        }

        return res;
    }



