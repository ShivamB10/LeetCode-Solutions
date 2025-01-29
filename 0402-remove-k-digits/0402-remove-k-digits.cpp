class Solution {
public:
    string removeKdigits(string num, int k) {
        stack <char> st;
        string ans;


        for(int i = 0; i < num.size(); i++){

            while(!st.empty() && st.top() > num[i] && k > 0){
                st.pop();
                k--;
            }

            st.push(num[i]);

        }

        while(k > 0 && !st.empty()){
            st.pop();
            k--;
        }

        


        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        while(!ans.empty() && ans[0] == '0'){
            ans.erase(ans.begin());
        }

        if(ans.empty()){
            return "0";
        }

        return ans;


        
    }
};