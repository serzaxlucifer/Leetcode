// HEHEHEHE: brute force

string addBinary(string a, string b) {
        string output = "";

        int carry = 0;
        int aP = a.length()-1;
        int bP = b.length()-1;

        while(aP >= 0 && bP >= 0)
        {
            output += to_string(((a[aP]-48)+(b[bP]-48)+carry)%2);
            carry = ((a[aP]-48)+(b[bP]-48)+carry)/2;
            aP--, bP--;
        }

        while(aP >= 0)
        {
            output += to_string(((a[aP]-48)+carry)%2);
            carry = ((a[aP]-48)+carry)/2;
            aP--;
        }

        while(bP >= 0)
        {
            output += to_string(((b[bP]-48)+carry)%2);
            carry = ((b[bP]-48)+carry)/2;
            bP--;
        }

        if(carry)
        {
            output += "1";
        }

        reverse(output.begin(), output.end());
        return output;
    }

// to optimize, we try to incorporate all while loops into one. How can we do that? Can we modify how we process the carry variable?? Yes and really efficiently!
    string addBinary(string a, string b) 
    {
        string output = "";

        int al = a.length() - 1;
        int bl = b.length() - 1;

        int carry = 0;
        while(al >= 0 || bl >= 0 || carry)
        {
            if(al >= 0)
            {
                carry += a[al]-48;
                al--;
            }
            if(bl >= 0)
            {
                carry += b[bl]-48;
                bl--;
            }

            output += (carry % 2 + '0');
            carry /= 2;
        }

        reverse(output.begin(), output.end());

        return output;

    }

// A real bad soln (a big string will cause overflow issues easily):
string addBinary(string a, string b) {
        return toBinary(toDecimal(a) + toDecimal(b));
    }

    int toDecimal(string dec)
    {
        int output = 0;
        int size = dec.length()-1;
        for(int i = size; i >= 0; i--)
        {
            output += (dec[i]-48)*pow(2, size-i);
        }
        return output;
    }

    string toBinary(int num)
    {
        if(num == 0)
        {
            return "0";
        }
        string str;
        while(num)
        {
            if(num & 1) // 1
            str+='1';
            else // 0
            str+='0';
            num>>=1; // Right Shift by 1 
        }   
        reverse(str.begin(), str.end());
        return str;
    }

