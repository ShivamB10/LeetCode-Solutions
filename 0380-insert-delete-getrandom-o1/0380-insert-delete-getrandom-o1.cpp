class RandomizedSet {
public:
    unordered_map<int,int> freq;
    vector<int> numSet;
    int index = 0;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(freq.count(val)){
            return false;
        }

        numSet.push_back(val);
        freq[val] = numSet.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!freq.count(val)){
            return false;
        }
        
        int index = freq[val];
        numSet[index] = numSet.back();
        freq[numSet[index]] = index;

        numSet.pop_back();
        freq.erase(val);
        return true;

    }
    
    int getRandom() {
        return numSet[rand()%numSet.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */