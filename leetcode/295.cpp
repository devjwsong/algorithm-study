#include <iostream>
#include <queue>

using namespace std;


// Two priority queues(heaps).
class MedianFinder {
public:
    priority_queue<int,vector<int>,less<int>> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (maxHeap.size() + minHeap.size() == 0) {
            minHeap.push(num);
        } else if (maxHeap.size() + minHeap.size() == 1) {
            if (minHeap.top() <= num) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            } else {
                maxHeap.push(num);
            }
        } else {
            if (maxHeap.size() == minHeap.size()) {
                if (minHeap.top() <= num) {
                    minHeap.push(num);
                } else {
                    maxHeap.push(num);
                }
            } else if (maxHeap.size() > minHeap.size()) {
                if (maxHeap.top() > num) {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(num);
                } else {
                    minHeap.push(num);
                }
            } else {
                if (minHeap.top() < num) {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(num);
                } else {
                    maxHeap.push(num);
                }
            }
        }
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return ((double) maxHeap.top() + (double) minHeap.top()) / 2.0;
        } else if (maxHeap.size() > minHeap.size()) {
            return (double) maxHeap.top();
        } else {
            return (double) minHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */