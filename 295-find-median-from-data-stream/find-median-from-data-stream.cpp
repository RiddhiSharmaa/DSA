class MedianFinder {
public:
    priority_queue<int>maxH;
    priority_queue<int, vector<int>, greater<int>>minH;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (maxH.empty() || (!minH.empty() && num <= minH.top())){
            maxH.push(num);
        } else if (minH.empty() || (!maxH.empty() && num > maxH.top())){
            minH.push(num);
        }

        if (!maxH.empty() && !minH.empty() && maxH.top() > minH.top()){
            minH.push(maxH.top());
            maxH.pop();
        }
        if (!maxH.empty() && !minH.empty() && minH.top() < maxH.top()){
            maxH.push(minH.top());
            minH.pop();
        }

        if (maxH.size()+1 < minH.size()){
            maxH.push(minH.top());
            minH.pop();
        }

        if (minH.size()+1 < maxH.size()){
            minH.push(maxH.top());
            maxH.pop();
        }
    }
    
    double findMedian() {
        if (minH.size() == maxH.size()){
            return (minH.top() + maxH.top()) / 2.0;
        } else if (minH.size() > maxH.size()){
            return minH.top();
        } else {
            return maxH.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */