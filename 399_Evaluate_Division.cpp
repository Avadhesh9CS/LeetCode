/*
399. Evaluate Division
Medium

You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.
You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.
Return the answers to all queries. If a single answer cannot be determined, return -1.0.
Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

Example 1:
Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]

Example 2:
Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]

Example 3:
Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]

Constraints:
    1 <= equations.length <= 20
    equations[i].length == 2
    1 <= Ai.length, Bi.length <= 5
    values.length == equations.length
    0.0 < values[i] <= 20.0
    1 <= queries.length <= 20
    queries[i].length == 2
    1 <= Cj.length, Dj.length <= 5
    Ai, Bi, Cj, Dj consist of lower case English letters and digits.
*/
class Solution {
public:
    unordered_map<string,unordered_map<string,double>> m;
    int ans=1;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i=0;i<equations.size();i++){
            m[equations[i][0]].insert({equations[i][1],values[i]});
            if(values[i]!=0)
                m[equations[i][1]].insert({equations[i][0],(double)1/(values[i])});
        }
        unordered_set<string> s;
        vector<double> ans;
        double a;
        for(auto q:queries){
            s.clear();
            a=0;
            a=dfs(q[0],q[1],s);
            if(a)ans.push_back(a);
            else ans.push_back(-1.0);
        }
        return ans;
    }
    double dfs(string node,string target,unordered_set<string> &s){
        if(m[node].find(target)!=m[node].end()) return m[node][target];
        for(auto i:m[node]){
            if(s.find(i.first)==s.end()){
                s.insert(i.first);
                double ans=dfs(i.first,target,s);
                if(ans) return ans*i.second;
            }
        }
        return 0;
    }
};
