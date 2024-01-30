class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> largeHalf;
    priority_queue<int> smallHalf;
    bool turn = true;

    MedianFinder() 
    {
        
    }
    
    void addNum(int num) 
    {
        if(turn)
        {
            largeHalf.push(num);
            smallHalf.push(largeHalf.top()); largeHalf.pop();
        }
        else
        {
            smallHalf.push(num);
            largeHalf.push(smallHalf.top()); smallHalf.pop();
        }

        turn = !turn;
    }
    
    double findMedian() 
    {
        if(turn)
        {
            return (smallHalf.top() + largeHalf.top())*0.5;
        }
        else
        {
            return smallHalf.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
