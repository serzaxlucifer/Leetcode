// Notice how we can remove use of separate 'visited' set using removal in 'words' set itself!

int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);


        vector<bool> visited(wordList.size(), false);
        unordered_set<string> words {wordList.begin(), wordList.end()};
        if(words.find(endWord) == words.end())
        {
            return 0;
        }

        int answer = 1;
        int dictSize = wordList.size();

        queue<string> BFS;
        BFS.push(beginWord);

        while(!BFS.empty())
        {
            int frontierSize = BFS.size();

            for(int i = 0; i < frontierSize; i++)
            {
                string aux = BFS.front(); BFS.pop();
                if(aux == endWord)
                {
                    return answer;
                }

                for(int j = 0; j < aux.size(); j++)
                {
                    char original = aux[j];
                    for(char a = 'a'; ; a++)
                    {
                        aux[j] = a;
                        if(words.find(aux) != words.end())
                        {
                            BFS.push(aux);
                            words.erase(aux);
                        }
                        if(a == 'z')
                        {
                            break;
                        }
                    }
                    aux[j] = original;
                }
            }

            answer++;
        }
        
        return 0;
    }
