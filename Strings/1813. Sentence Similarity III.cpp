    bool areSentencesSimilar(string sentence1, string sentence2) 
    {
        int l1 = sentence1.length(), l2 = sentence2.length();

        vector<string> s1, s2;
        //parse both.
        string aux = "";

        for(int i = 0; i < l1; i++)
        {   
            if(sentence1[i] == ' ')
            {
                s1.push_back(aux);
                aux = "";
            }
            else
            {
                aux += sentence1[i];
            }

        }
        s1.push_back(aux);
        aux = "";

        for(int i = 0; i < l2; i++)
        {
            if(sentence2[i] == ' ')
            {
                s2.push_back(aux);
                aux = "";
            }
            else
            {
                aux += sentence2[i];
            }
        }
        s2.push_back(aux);
        aux = "";

        int i = 0;
        l1 = s1.size(), l2 = s2.size();

        if(l1 > l2)
        {
            return areSentencesSimilar(sentence2, sentence1);
        }

        while(i < l1 && s1[i] == s2[i])
        {
            i++;
        }

        while(i < l1 && s1[i] == s2[l2 - l1 + i])
        {
            i++;
        }

        return i == l1;
    }
