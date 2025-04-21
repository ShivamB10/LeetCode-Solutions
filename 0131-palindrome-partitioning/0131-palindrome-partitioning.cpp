class Solution {
public:
    bool checkPalindrome(string& sub, int start, int end){
        while(start < end){
            if(sub[start] != sub[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void generateSubstrings(string s, vector<vector<string>> &ans, vector<string>& path, string sub, int index){
        if(index == s.size()){
            ans.push_back(path);
            return;
        }

        for(int end = index; end < s.size(); end++){
            if(checkPalindrome(s,index,end)){
                path.push_back(s.substr(index,end-index+1));
                generateSubstrings(s,ans,path,sub,end+1);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        string sub;
        generateSubstrings(s, ans, path, sub, 0);

        return ans;
    }
};