    int leastInterval(vector<char>& tasks, int n) 
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        if(n == 0)
        {
            return tasks.size();
        }

        priority_queue<pair<int, char>, vector<pair<int, char>>> PQ;
        int answer = 0;
        int distinctJobs = 0;
        int frequency[26] = {0};

        for(char letter : tasks)
        {
            if(frequency[letter - 'A'] == 0)
            {
                distinctJobs++;
            }

            frequency[letter - 'A']++;
        }

        for(int i = 0; i < 26; i++)
        {
            if(frequency[i])
            {
                PQ.push({frequency[i], 'A' + i});
            }
        }

        pair<int, char> popped[100];

        while(!PQ.empty())
        {
            int tasksOnHand = 0;
            for(int i = 0; i < min(distinctJobs, n+1); i++)
            {
                popped[i] = PQ.top(); PQ.pop();
                tasksOnHand++;
            }

            for(int i = 0; i < tasksOnHand; i++)
            {
                answer++;
                popped[i].first--;
                if(popped[i].first > 0)
                {
                    PQ.push(popped[i]);
                }
                else
                {
                    distinctJobs--;
                }
            }

            if(!PQ.empty())
            answer += n - tasksOnHand + 1;
        }

        return answer;
    }

// to get the sequence you can also sort the tasks array.

// But we only require the number (int) so here:

    int leastInterval(vector<char>& tasks, int n) 
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        if(n == 0)
        {
            return tasks.size();
        }
        int maxCount = 0;
        int maxFreq = 0;

        int frequency[26] = {0};

        for(char letter : tasks)
        {
            frequency[letter - 'A']++;
            if(maxFreq == frequency[letter - 'A'])
            {
                maxCount++;
            }
            else if(maxFreq < frequency[letter - 'A'])
            {
                maxCount = 1; maxFreq = frequency[letter - 'A'];
            }
        }

        int partCount = maxFreq - 1;
        int partLength = n - (maxCount - 1);
        int emptySlots = partCount * partLength;
        int availableTasks = tasks.size() - maxCount*maxFreq;

        int idles = max(0, emptySlots - availableTasks);

        return tasks.size()  + idles;
    }
