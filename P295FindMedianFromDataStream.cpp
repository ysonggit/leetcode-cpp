class MedianFinder {
public:
    // maxheap saves the smaller half, minheap saves the larger half
    // balance the two heaps, make sure the maxheap.size >= minheap.size
    priority_queue<int, vector<int>, greater<int> > minheap;
    priority_queue<int> maxheap;
    // Adds a number into the data structure.
    void addNum(int num) {
        if(maxheap.size()==minheap.size()){
            if(maxheap.size()==0) maxheap.push(num);
            else{ // adjust two heaps
                if(num > minheap.top()){
                    maxheap.push(minheap.top());
                    minheap.pop();
                    minheap.push(num);
                }else{
                    maxheap.push(num);
                }
            }
        }else{
            if(num > maxheap.top()){
                minheap.push(num);
            }else{
                minheap.push(maxheap.top());
                maxheap.pop();
                maxheap.push(num);
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(minheap.size()==maxheap.size()) return (minheap.top() + maxheap.top())/2.0;
        else return (double) maxheap.top();
    }
};
// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
