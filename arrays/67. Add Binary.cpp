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


