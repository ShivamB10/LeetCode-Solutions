class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        string result;

        if(a>0) pq.push({a, 'a'});
        if(b>0) pq.push({b,'b'});
        if(c>0) pq.push({c,'c'});

        while(!pq.empty()){
            int freq_count = pq.top().first;
            char freq_char = pq.top().second;
            pq.pop();

            if(result.size()>= 2 && result.back() == freq_char && result[result.size()-2] == freq_char){
                if(pq.empty()){
                    break;
                }

                int second_freq = pq.top().first;
                char second_char = pq.top().second;

                pq.pop();

                result += second_char;

                second_freq--;
                if(second_freq >0){
                    pq.push({second_freq, second_char});
                }

                pq.push({freq_count,freq_char});
            }
            else{
                result+= freq_char;
                freq_count--;

                if(freq_count>0){
                    pq.push({freq_count,freq_char});
                }
            } 
        }


        return result;
    }
};