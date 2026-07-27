class MedianFinder {
public:

    priority_queue<int> leftHeap;
    priority_queue<int,vector<int>,greater<int>> rightHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(leftHeap.empty() || num <= leftHeap.top()){
            leftHeap.push(num);
        }
        else{
            rightHeap.push(num);
        }    

        if(leftHeap.size() > rightHeap.size() + 1){
            rightHeap.push(leftHeap.top());
            leftHeap.pop();
        }
        else if(rightHeap.size() > leftHeap.size() + 1){
            leftHeap.push(rightHeap.top());
            rightHeap.pop();
        }
    }
    
    double findMedian() {
        if(leftHeap.size() == rightHeap.size()){
            return (leftHeap.top() + rightHeap.top()) /2.0;
        }
        if(leftHeap.size() > rightHeap.size()){
            return leftHeap.top();
        }
        return rightHeap.top();
    }
};
