// 1D DP Memoization:

int cutUtil(vector<int> &price, int n, vector<int>& dp)
{
	// Write your code here.
	if(n == 0)
	{
		return 0;
	}

	if(n < 0)
	{
		return -1;
	}

	if(dp[n] != -2)
	{
		return dp[n];
	}

	int minTrack = -1;

	for(int i = 0; i < price.size(); i++)
	{
		int TAKE = cutUtil(price, n-(i+1), dp);

		if(TAKE == -1)
		{
			continue;
		}

		minTrack = max(minTrack, price[i] + TAKE);
	}

	return dp[n] = minTrack;
}

int cutRod(vector<int> &price, int n)
{
	vector<int> dp(n+1, -2);

	return cutUtil(price, n, dp);
}
