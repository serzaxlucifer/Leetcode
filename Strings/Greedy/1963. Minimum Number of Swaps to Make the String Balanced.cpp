    int minSwaps(string s) {
	int n = s.size();
	int balance = 0, swaps = 0, j=n-1;
	for(int i=0; i<n; i++)
	{
		if(s[i] == '[') balance++;
		else balance--;

		if(balance < 0)
		{
			while(i<j && s[j] != '[') j--;
			swap(s[i], s[j]);
			swaps++;
			balance = 1;
		}
	}
	return swaps;
}

// The optimal strategy is to fix two brackets with one swap.

int minSwaps(string s) {
    int bal = 0, cnt = 0;
    for (auto ch : s)
        if (bal == 0 && ch == ']')
            ++cnt;
        else
            bal += ch == '[' ? 1 : -1;
    return (cnt + 1) / 2;
}
