/*
1286. Iterator for Combination
Medium

Design the CombinationIterator class:

    CombinationIterator(string characters, int combinationLength) Initializes the object with a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
    next() Returns the next combination of length combinationLength in lexicographical order.
    hasNext() Returns true if and only if there exists a next combination.


Example 1:
Input
["CombinationIterator", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[["abc", 2], [], [], [], [], [], []]
Output
[null, "ab", true, "ac", true, "bc", false]

Explanation
CombinationIterator itr = new CombinationIterator("abc", 2);
itr.next();    // return "ab"
itr.hasNext(); // return True
itr.next();    // return "ac"
itr.hasNext(); // return True
itr.next();    // return "bc"
itr.hasNext(); // return False

Constraints:
    1 <= combinationLength <= characters.length <= 15
    All the characters of characters are unique.
    At most 104 calls will be made to next and hasNext.
    It's guaranteed that all calls of the function next are valid.
*/
class CombinationIterator {
    set<string> generateAllCombination(string s,int l){
        int mask=(1<<s.size());
        set<string> hold;
        string comst="";
        for(int i=1;i<mask;i++){
            int num=i,j=0;
            while(num){
                if(num&1)
                    comst+=s[j];
                j++;
                num>>=1;
            }
            if(comst.size()==l) hold.insert(comst);
            comst="";
        }
        return hold;
    }
public:
    set<string> st;
    set<string>::iterator curr;
    CombinationIterator(string characters, int combinationLength) {
        this->st=generateAllCombination(characters,combinationLength);
        this->curr=st.begin();
    }
    
    string next() {
         return curr==st.end()?"":*curr++;
    }
    
    bool hasNext() {
        return curr!=st.end();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
