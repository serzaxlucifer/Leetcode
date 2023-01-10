int maximumPopulation(vector<vector<int>>& logs) {
        int arr[101] = {}; // representing the years.

        for(int i = 0; i <= logs.size()-1; i++)
        {
            arr[logs[i][0]-1950]++;
            arr[logs[i][1]-1950]--;
        }

        int maxPopYear = 1950;

        for(int i = 1; i <= 100; i++)
        {
            arr[i] += arr[i-1];
            maxPopYear = arr[i] > arr[maxPopYear-1950] ? (i + 1950): maxPopYear;
        } 

        return maxPopYear;
    }

// 0ms Solution: Uses priority queues (heap data structures)
// this is an interesting approach to the problem. Do study carefully!

int maximumPopulation(vector<vector<int>>& logs) {
        priority_queue<int, vector<int>, greater<int>> comes;	// min heap
		priority_queue<int, vector<int>, greater<int>> gos;	// min heap
		
		for (vector<int>& log : logs) {
			comes.push(log[0]);
			gos.push(log[1]);
		}
		
		int people = 0;
		int maxPeople = 0;
		int result = 0;
		while (!comes.empty() && !gos.empty()) {
			if (gos.top() <= comes.top()) {
				people--;
				gos.pop();
			} else {
				people++;
				int year = comes.top();
				comes.pop();
				
				if (people > maxPeople) {
					maxPeople = people;
					result = year;
				}
			}
		}
		
		return result;
    }

// another solution:


