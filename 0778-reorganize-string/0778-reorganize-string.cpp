class Solution {
public:
    struct Compare{
        bool operator()(const pair<char,int> &a, const pair<char,int> &b){
            return a.second < b.second;
        }
    };
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        priority_queue<pair<char,int>, vector<pair<char,int>>, Compare> pq;

        for(int i = 0; i < s.size(); i++){
            freq[s[i]]++;
        }

        for(auto it = freq.begin(); it!= freq.end(); it++){
            pq.push({it->first,it->second});
        }

        string ans;

        while(pq.size()>1){
            char first_char = pq.top().first;
            pq.pop();
            char second_char = pq.top().first;
            pq.pop();

            ans.push_back(first_char);
            ans.push_back(second_char);


            if(--freq[first_char] >0){
                pq.push({first_char, freq[first_char]});
            }

            if(--freq[second_char] >0){
                pq.push({second_char, freq[second_char]});
            }

        }

        if(!pq.empty()){
            if(pq.top().second > 1){
                return "";
            }
            ans.push_back(pq.top().first);
        }


        return ans;



        
    }
};