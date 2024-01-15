class UnionFind
{
    private:
    int *parent, *rank;

    public:
    UnionFind(int N)
    {
        parent = new int[N];
        rank = new int[N];
        for(int i = 0; i < N; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    ~UnionFind()
    {
        delete [] parent;
        delete [] rank;
    }

    int find(int p)
    {
        if(p == parent[p])
        {
            return p;
        }
        return parent[p] = find(parent[p]);
    }

    bool connected(int p, int q)
    {
        return find(p) == find(q);
    }

    void connect(int p, int q)
    {
        int i = find(p);
        int j = find(q);

        if(i == j)
        {
            return;
        }
        if(rank[i] > rank[j])
        {
            parent[j] = i;
        }
        else if(rank[j] > rank[i])
        {
            parent[i] = j;
        }
        else
        {
            parent[i] = j;
            rank[j]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        UnionFind UF = UnionFind(n);
        int spareConnections = 0;
        int answer = -1;

        for(auto it : connections)
        {
            int a = it[0];
            int b = it[1];

            if(UF.connected(a, b))
            {
                spareConnections++;
            }
            else
            {
                UF.connect(a, b);
            }
        }

        answer = spareConnections;

        for(int i = 0; i < n; i++)
        {
            if(UF.find(i) == i)
            {
                spareConnections--;
            }
        }
        spareConnections++;

        if(spareConnections < 0)
        {
            return -1;
        }

        return answer - spareConnections;
    }
};
