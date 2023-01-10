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
