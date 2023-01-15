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

// optimized:

vector<int> plusOne(vector<int>& digits) {
        int n=digits.size(); int carry=0; int idx=0;
        if(digits[n-1]==9) 
        {
            digits[n-1]=0; carry=1;
            for(int i=n-2;i>=0;i--)
            {
                if(digits[i]==9) { digits[i]=0; }
                else { digits[i]+=carry; carry=0; break; }
            }
        }
        else
        {
            digits[n-1]+=1; 
            return digits;
        }
        if(carry) 
        {
            digits[0]=1; digits.push_back(0);
        }
        return digits;
    }
