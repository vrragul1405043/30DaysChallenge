class MedianFinder {
public:
    priority_queue<int,vector<int>>max_heap;
    priority_queue<int,vector<int>,greater<int>>min_heap;
    
    MedianFinder() {

    }
    void addNum(int num) {
        if(max_heap.empty() || num<max_heap.top())max_heap.push(num);
        else min_heap.push(num);
        
        if(isValid(max_heap.size(), min_heap.size())>1){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        
        else if(isValid(max_heap.size(), min_heap.size())<0){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        if(min_heap.size() == max_heap.size()){
            double ans = (max_heap.empty())?0:(max_heap.top() + min_heap.top())/2.0;
            return ans;
        }
        return max_heap.top();
    }
    
    int isValid(int max_heap_size, int min_heap_size){
        return max_heap_size - min_heap_size;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
