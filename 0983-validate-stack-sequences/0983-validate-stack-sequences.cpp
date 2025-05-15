class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int left = 0;

        for(int i = 0;  i < pushed.size(); i++){
            while(!st.empty() && st.top() == popped[left]){
                st.pop();
                left++;
            }
            
            st.push(pushed[i]);
            cout<<st.top()<<endl;

            
        }

        


        while(!st.empty()){
            if(st.top()!= popped[left]){
                return false;
            }

            st.pop();
            left++;
        }

        return true;


    }
};