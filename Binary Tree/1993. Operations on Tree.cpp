class LockingTree {      // runtime: 96%, memory: 92%
public:
    vector<int> parents;
    vector<vector<int>> child;
    vector<int> locks;

    LockingTree(vector<int>& parent) 
    {
        int size = parent.size();
        parents = parent;
        child = vector<vector<int>>(size, vector<int>());
        locks = vector<int>(size, -1);

        for(int i = 1; i < size; i++)
        {
            int parentt = parent[i];
            child[parentt].push_back(i);
        }
    }
    
    bool lock(int num, int user) 
    {
        if(locks[num] == -1)
        {
            locks[num] = user;
            return true;
        }
        return false;
    }
    
    bool unlock(int num, int user) 
    {
        if(locks[num] == user)
        {
            locks[num] = -1;
            return true;
        }
        return false;
    }
    
    bool upgrade(int num, int user) 
    {
        if(locks[num] != -1)
        {
            return false;
        }

        int parent = num;

        while(parent != -1)
        {
            if(locks[parent] != -1)
            {
                return false;
            }
            parent = parents[parent];
        }

        bool found = false;

        traverse(num, found);

        if(found)
        {
            locks[num] = user;
            return true;
        }
        return false;
    }

    void traverse(int num, bool& found)
    {
        if(num == -1)
        {
            return;
        }
        if(locks[num] != -1)
        {
            found = true;
            unlock(num, locks[num]);
        }
        for(int i = 0; i < child[num].size(); i++)
        {
            traverse(child[num][i], found);
        }
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
