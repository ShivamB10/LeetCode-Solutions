class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        long long total_gifts = 0;
        int current_gift = 0;

        for(int i = 0; i < gifts.size(); i++){
            pq.push(gifts[i]);
        }


        while(k > 0){
            current_gift = floor(sqrt(pq.top()));
            pq.pop();
            pq.push(current_gift);
            k--;
        }

        while(!pq.empty()){
            total_gifts+= pq.top();
            pq.pop();
        }

        return total_gifts;
        
    }
};