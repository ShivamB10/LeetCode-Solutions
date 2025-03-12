class MedianFinder {
private:
    priority_queue<int,vector<int>,greater<int>> min_pq;
    priority_queue<int> max_pq;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(max_pq.size() == 0 || num <= max_pq.top()){
            max_pq.push(num);
        }

        else{
            min_pq.push(num);
        }

        if(max_pq.size() > min_pq.size()+1){
                min_pq.push(max_pq.top());
                max_pq.pop();
            }

        else if(min_pq.size()>max_pq.size()){
                max_pq.push(min_pq.top());
                min_pq.pop();
            }

            
        }
    
    double findMedian() {
        double median = 0;

        if(max_pq.size() == min_pq.size()){
            double max_top = max_pq.top();
            double min_top = min_pq.top();

            median = (max_top+min_top)/2;
            return median;
        }

        median = max_pq.top();

        return median;
        }
    };


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */