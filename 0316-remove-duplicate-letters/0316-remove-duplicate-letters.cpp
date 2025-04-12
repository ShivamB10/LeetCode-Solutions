class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> pos;

        for(int i = 0; i < s.size(); i++){
            pos[s[i]] = i;
        }

        string result;
        stack<char> st;
        unordered_set<char> visited;
        

        for(int j = 0; j < s.size(); j++){
            if(visited.find(s[j])!=visited.end()){
                continue;
            }
            while(!st.empty()){
                if(s[j] < st.top() && pos[st.top()] > j){
                    visited.erase(st.top());
                    st.pop();
                }
                else{
                    break;
                }
            }

            st.push(s[j]);
            visited.insert(s[j]);
        }

        while(!st.empty()){
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;



    }
};