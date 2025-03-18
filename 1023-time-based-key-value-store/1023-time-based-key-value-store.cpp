class TimeMap {
private:
    unordered_map <string,vector<pair<int,string>>> t_map;

public:

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        t_map[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        string ans;
        auto &values = t_map[key];
        int start = 0;
        int end = values.size()-1;

        while(start <= end){
            int mid = start + (end-start)/2;

            if(values[mid].first <= timestamp){
                ans = values[mid].second;
                start = mid+1;
            }
            else{
                end = mid - 1;
            }
        }

        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */