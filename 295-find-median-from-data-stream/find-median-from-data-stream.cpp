class MedianFinder {
public:
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> r;

    MedianFinder() {}
    
    void addNum(int num) {
        l.push(num);
        r.push(l.top());
        l.pop();
        
        if (l.size() < r.size()) {
            l.push(r.top());
            r.pop();
        }
    }
    
    double findMedian() {
        if (l.size() > r.size()) {
            return l.top();
        }
        return (l.top() + r.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */