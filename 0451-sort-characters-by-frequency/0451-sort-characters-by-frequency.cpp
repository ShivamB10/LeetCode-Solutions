class Solution {
public:
    struct Compare{
        unordered_map <char, int>& freq;
        Compare(unordered_map<char, int>& freqMap) : freq(freqMap) {}

        bool operator()(char a, char b){
            return (freq[a] < freq[b]);
        }
    };

    string frequencySort(string s) {
        unordered_map <char, int> freq;
        string result;

        for(int i = 0; i < s.size(); i++){
            freq[s[i]]++;
        }

        priority_queue<char, vector<char>, Compare> pq{Compare(freq)};

        for(auto it = freq.begin(); it!= freq.end(); it++){
            pq.push(it->first);
        }

        while(!pq.empty()){
            for(int j = 0; j < freq[pq.top()]; j++){
                result.push_back(pq.top());
            }

            pq.pop();
        }


        return result;


    }
};