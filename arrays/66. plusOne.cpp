vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int i = 0;
        int carry = 0;

        digits[n-1-i] += 1;
        carry = digits[n-1-i]/10;
        digits[n-1-i]%=10;
        i++;

        while(carry > 0 && i < n)
        {
            digits[n-1-i]+=carry;
            carry = digits[n-1-i]/10;
            digits[n-1-i]%=10;
            i++;
        }

        if(carry!=0 && i == n)
        {
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
