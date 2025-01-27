class Solution {
public:
    void constructCombo(string digits,vector<string>& result, string combo, int index, map<char, string>& numbers){
        if(index >= digits.size()){
            result.push_back(combo);
            return;
        }

        for(int i = 0; i < numbers[digits[index]].size(); i++){
            combo.push_back(numbers[digits[index]][i]);
            constructCombo(digits,result,combo,index+1,numbers);
            combo.pop_back();
        }

        


    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string combo;

        if(digits.empty()){
            return result;
        }
        map<char, string> numbers;
        numbers['2'] = "abc";
        numbers['3'] = "def";
        numbers['4'] = "ghi";
        numbers['5'] = "jkl";
        numbers['6'] = "mno";
        numbers['7'] = "pqrs";
        numbers['8'] = "tuv";
        numbers['9'] = "wxyz";

        constructCombo(digits,result,combo,0,numbers);

        return result;
        
    }
};