int maxDepth(string s) {
        int depth = 0;
        int marker = 0;

        for(char a : s)
        {
            if(a == '(')
            {
                marker++;
                depth = (depth >= marker) ? depth : marker;
            }
            else if(a == ')')
            {
                marker--;
            }
        }

        return depth;
    }
