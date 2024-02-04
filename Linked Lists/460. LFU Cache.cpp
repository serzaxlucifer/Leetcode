    class Node {
        public:
        int key, val, cnt;
        Node* prev, *next;
        Node(int key, int val) {
            this->key = key;
            this->val = val;
            cnt = 1;
        }
    };
    
    class DLList {
        public:
        Node* head, *tail;
        int size;
        DLList(Node* node) {
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
            size = 0;

            if(node)
            {
                add(node);
            }
        }

        DLList()
        {}
        
        void add(Node* node) {
            head->next->prev = node;
            node->next = head->next;
            node->prev = head;
            head->next = node;
            size++;
        }
        
        void remove(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            size--;
        }
        
        Node* removeLast() {
            if (size > 0) {
                Node* node = tail->prev;
                remove(tail->prev);
                return node;
            }
            else return NULL;
        }
    };

class LFUCache {
public:
    int capacity, size, min;
    unordered_map<int, Node*>  nodeMap;
    unordered_map<int, DLList> countMap;

    LFUCache(int capacity) 
    {
        size = 0;
        min = 0;
        this->capacity = capacity;
    }
    
    int get(int key) 
    {
        if (nodeMap.find(key) == nodeMap.end()) return -1;
        Node* node = nodeMap[key];
        update(node);
        return node->val;
    }
    
    void put(int key, int value) 
    {
        if(capacity == 0)
        {
            return;
        }
        Node* node;
        if(nodeMap.find(key) != nodeMap.end())
        {
            node = nodeMap[key];
            node->val = value;
            update(node);
        }
        else
        {
            node = new Node(key, value);
            nodeMap[key] = node;
            if(size == capacity)
            {
                DLList& lastList = countMap[min];
                Node* last = lastList.removeLast();
                nodeMap.erase(last->key);
                delete last;
                size--;
            }
            size++;
            min = 1;
            if(countMap.find(node->cnt) != countMap.end())
            {
                DLList& newList = countMap[node->cnt];
                newList.add(node);
            }
            else
            {
                countMap[node->cnt] = *(new DLList(node));
            }
        }
    }

    void update(Node* node)
    {
        DLList& oldList = countMap[node->cnt];
        oldList.remove(node);
        if (node->cnt == min && oldList.size == 0) 
            min++; 

        node->cnt++;
        
        if(countMap.find(node->cnt) != countMap.end())
        {
            DLList& newList = countMap[node->cnt];
            newList.add(node);
        }
        else
        {
            countMap[node->cnt] = *(new DLList(node));
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
