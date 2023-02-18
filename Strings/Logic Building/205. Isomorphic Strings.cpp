// A great solution inspired by: https://leetcode.com/problems/isomorphic-strings/solutions/57796/my-6-lines-solution/?orderBy=most_votes

/* Explanation courtesy of the article above:
The idea is that we need to map a char to another one, for example, "egg" and "add", we need to constract the mapping 'e' -> 'a' and 'g' -> 'd'. Instead of directly
mapping 'e' to 'a', another way is to mark them with same value, for example, 'e' -> 1, 'a'-> 1, and 'g' -> 2, 'd' -> 2, this works same.

So we use two arrays here m1 and m2, initialized space is 256 (Since the whole ASCII size is 256, 128 also works here). Traverse the character of both s and t 
on the same position, if their mapping values in m1 and m2 are different, means they are not mapping correctly, returen false; else we construct the mapping, 
since m1 and m2 are both initialized as 0, we want to use a new value when i == 0, so i + 1 works here.
*/

bool isIsomorphic(string s, string t) {

        int dictionary1[256] = {0};
        int dictionary2[256] = {0};

        int size = s.length();
        
        for(int i = 0; i < size; i++)
        {
            if(dictionary1[s[i]] != dictionary2[t[i]])
            return false;
            dictionary1[s[i]] = dictionary2[t[i]] = i+1;
        }
        return true;

    }
