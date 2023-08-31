// Watch this Video: https://youtu.be/wT7gcXLYoao?si=-S-QKkooHwtgRY_u

string getPermutation(int n, int k) 
    {
        vector<int> numbers;
        int factorial = 1;          // Keeping in mind the constrained value of n (given in constraints), 'int' will be sufficient.
        string answer = "";

        for(int i = 1; i < n; i++)
        {
            numbers.push_back(i);
            factorial  *= i;
        }

        k--;

        numbers.push_back(n);

        for(int i = 0; i < n; i++)
        {
            int index = k / factorial;  
            answer += to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);
            k = k % factorial;

            if(i != n - 1)
            {
                factorial /= numbers.size();
            }
        }

        return answer;
    }

// Time Complexity: O(N*N)
// Space Complexity: O(N)
