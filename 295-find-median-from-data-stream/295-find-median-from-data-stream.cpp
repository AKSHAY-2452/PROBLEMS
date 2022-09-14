class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(minHeap.size() < maxHeap.size()) minHeap.push(num);
        else maxHeap.push(num);
        
        if(minHeap.size() == 0) return;
        if(minHeap.top()<maxHeap.top()){
            auto a = minHeap.top();
            minHeap.pop();
            auto b = maxHeap.top();
            maxHeap.pop();
            
            maxHeap.push(a);
            minHeap.push(b);
        }
    }
    
    double findMedian() {
        //odd number of elements
        if(minHeap.size() < maxHeap.size()){
            return maxHeap.top();
        }
        else{//even elemnts means number of elements in min heap == max heap
            return (maxHeap.top()+minHeap.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */