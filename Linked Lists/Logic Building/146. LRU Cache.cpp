// Observe closely why we are using a Doubly Linked List. Read more on LeetCode Editorial: https://leetcode.com/problems/lru-cache/editorial/

class LRUCache {
public:
    // For finding where a node exists, we use an unordered map/dictionary (!)

    int capacity;

    list<pair<int, int>> lru;
    unordered_map<int, list<pair<int, int>>::iterator> map;     // a key and a node pointer

    LRUCache(int capacity) 
    {
        this->capacity = capacity;
    }
    
    int get(int key) 
    {
        auto existence = map.find(key);

        if(existence == map.end())
        {
            return -1;
        }

        int val = (existence->second->second);

        // pass it to back.

        lru.erase(existence->second);
        lru.push_front({key, val});
        map[key] = lru.begin();

        return val;

    }
    
    void put(int key, int value) 
    {
        auto existence = map.find(key);

        if(existence != map.end())     // remove and add it at back as its most recently updated
        {
            lru.erase(existence->second);
        }

        lru.push_front({key, value});
        map[key] = lru.begin();

        if(map.size() > capacity)
        {
            // delete stuff at beginning.
            map.erase(lru.rbegin()->first);
            lru.pop_back();
        }
    }
};

//--------------------------------------------------

// How do we further optimize this? 

// Resource to read: https://stackoverflow.com/questions/38043442/how-do-inline-variables-work
// But more importantly, notice the data structures employed here, and how well they consider the data constraints.
// This code performs drastically better in runtime.

class LRUCache {
public:
    inline static int M[10001];
    inline static int16_t L[10002][2];
    int cap, size = 0;
    const int NONE = 10001;
    int head = NONE, tail = NONE;
    
    LRUCache(int capacity) : cap(capacity) {
        memset(M, 0xff, sizeof M);
    }
    
    inline void erase(int key) {
        const int pre = L[key][0];
        const int nxt = L[key][1];
        L[pre][1] = nxt;
        L[nxt][0] = pre;
        if (head == key) head = nxt;
        if (tail == key) tail = pre;
    }
    
    inline void push_front(int key) {
        L[key][0] = NONE;
        L[key][1] = head;
        L[head][0] = key;
        head = key;
        if (tail == NONE)
            tail = key;
    }
    
    inline int pop_back() {
        int ret = tail;
        tail = L[tail][0];
        L[tail][1] = NONE;
        if (tail == NONE)
            head = NONE;
        return ret;
    }
    
    int get(int key) {
        if (M[key] == -1) return -1;
        erase(key);
        push_front(key);
        return M[key];
    }
    
    void put(int key, int value) {
        if (M[key] != -1) {
            erase(key);
        } else {
            if (size == cap) {
                int poped = pop_back();
                M[poped] = -1;
                size -= 1;
            }
            size += 1;
        }
        push_front(key);
        M[key] = value;
    }
};
