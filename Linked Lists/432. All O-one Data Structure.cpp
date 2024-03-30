class BucketNode
{
    public:
    int count;
    unordered_set<string> keySet;
    BucketNode *next;
    BucketNode *prev;

    BucketNode(int cnt) 
    {
        count = cnt;
    }
};

class AllOne {
public:
    BucketNode *head, *tail;
    unordered_map<int, BucketNode*> countBucketMap;
    unordered_map<string, int> keyCountMap;

    AllOne() {
        head = new BucketNode(INT_MIN);
        tail = new BucketNode(INT_MAX);
        head->next = tail;
        tail->prev = head;
    }
    
    void inc(string key) 
    {
        if(keyCountMap.find(key) != keyCountMap.end())
        {
            changeKey(key, 1);
        }
        else
        {
            keyCountMap[key] = 1;
            if (head->next->count != 1) 
            {
                insertBucket(new BucketNode(1), head);
            }
            head->next->keySet.insert(key);
            countBucketMap[1] = head->next;
        }
    }
    
    void dec(string key) 
    {
        if(keyCountMap.find(key) != keyCountMap.end())
        {
            int count = keyCountMap[key];
            if(count == 1)
            {
                keyCountMap.erase(key);
                removeKey(countBucketMap[count], key);
            }
            else
            {
                changeKey(key, -1);
            }
        }
    }
    
    string getMaxKey() 
    {
        return tail->prev == head ? "" : *(tail->prev->keySet.begin());
    }
    
    string getMinKey() 
    {
        return head->next == tail ? "" : *(head->next->keySet.begin());
    }

    void changeKey(string key, int offset)
    {
        // offset is either 1 or -1

        int count = keyCountMap[key];
        keyCountMap[key] = count + offset;

        BucketNode* curBucket = countBucketMap[count];
        BucketNode* newBucket;

        if(countBucketMap.find(count+offset) != countBucketMap.end())
        {
            newBucket = countBucketMap[count+offset];
        }
        else
        {
            newBucket = new BucketNode(count+offset);
            countBucketMap[count+offset] = newBucket;
            insertBucket(newBucket, offset == 1 ? curBucket : curBucket->prev);
        }

        newBucket->keySet.insert(key);
        removeKey(curBucket, key);
    }

    void removeKey(BucketNode* bucket, string key)
    {
        bucket->keySet.erase(key);
        if(bucket->keySet.size() == 0)
        {
            removeBucket(bucket);
            countBucketMap.erase(bucket->count);
        }
    }

    void insertBucket(BucketNode* newBucket, BucketNode* afterThis)
    {
        newBucket->prev = afterThis;
        newBucket->next = afterThis->next;
        afterThis->next->prev = newBucket;
        afterThis->next = newBucket;
    }

    void removeBucket(BucketNode* bucket)
    {
        bucket->prev->next = bucket->next;
        bucket->next->prev = bucket->prev;
        bucket->next = NULL;
        bucket->prev = NULL;
    }
};

// Better Approach:

class AllOne {
public:
    AllOne() {
        
    }
    
    void inc(const string& key) {
        int nf = ++freq[key];
        if (mxf && nf > mxf) {
            mxf = nf;
            mx = key;
        } else {
            //mxf = 0;
        }
        mnf = 1e9;
    }
    
    void dec(const string& key) {
        int nf = --freq[key];
        if (mnf < 1e9 && nf > 0 && nf < mnf) {
            mnf = nf;
            mn = key;
        } else {
            mnf = 1e9;
        }
        mxf = 0;
    }
    
    string getMaxKey() {
        if (mxf) return mx;

        for (auto& kvp: freq) {
            if (kvp.second > mxf) {
                mx = kvp.first;
                mxf = kvp.second;
            }
        }
        return mx;
    }
    
    string getMinKey() {
        if (mnf < 1e9) return mn;

        for (auto& kvp: freq) {
            if (kvp.second > 0 && kvp.second < mnf) {
                mn = kvp.first;
                mnf = kvp.second;
            }
        }
        return mn;
    }
private:
    int mxf = 0;
    string mx;
    int mnf = 1e9;
    string mn;
    unordered_map<string, int> freq;
};
