/*
17. Letter Combinations of a Phone Number
Medium

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:

Input: digits = ""
Output: []

Example 3:

Input: digits = "2"
Output: ["a","b","c"]

 

Constraints:

    0 <= digits.length <= 4
    digits[i] is a digit in the range ['2', '9'].

*/
class Solution {
    vector<string>map={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    void letterCombinationsHelper(string digits,string a,int ind){
        if(digits.length()==ind){
            ans.push_back(a);
            return;
        }
        int index=(digits[ind]-'0');
        for(auto i:map[index]){
            letterCombinationsHelper(digits,a+i,ind+1);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits==""){
            return{};
        }
        ans.clear();
        letterCombinationsHelper(digits,"",0);
        return ans;
    }
};
