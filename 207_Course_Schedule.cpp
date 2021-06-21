//207. Course Schedule
/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
    For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Constraints:
    1 <= numCourses <= 105
    0 <= prerequisites.length <= 5000
    prerequisites[i].length == 2
    0 <= ai, bi < numCourses
    All the pairs prerequisites[i] are unique.
*/
//DFS
class Solution {
    vector<vector<int>> creategraph(int numCourses,vector<vector<int>>& prerequisites){
        vector<vector<int>> graph(numCourses);
        for(auto p: prerequisites){
            graph[p[1]].push_back(p[0]);
        }
        return graph;
    }
    bool acyclic(vector<vector<int>> &graph,vector<bool>& todo,vector<bool>& done,int node){
        if(todo[node]){
            return false;
        }
        if(done[node]){
            return true;
        }
        todo[node]=done[node]=true;
        for(int i :graph[node]){
            if(!acyclic(graph,todo,done,i)){
                return false;
            }
        }
        todo[node]=false;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph=creategraph(numCourses,prerequisites);
        vector<bool> todo(numCourses,false),done(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!done[i] && !acyclic(graph,todo,done,i)){
                return false;
                }    
            }
    return true;
    }
};

//BFS
class Solution {
    typedef vector<vector<int>> graph;
    graph creategraph(int numCourses,vector<vector<int>>& prerequisites){
        graph g(numCourses);
        for(auto p: prerequisites){
            g[p[1]].push_back(p[0]);
        }
        return g;
    }
    vector<int> indegree(graph g){
        vector<int> indeg(g.size(),0);
        for(auto ver:g){
            for(int adj:ver){
                indeg[adj]++;
            }
        }
        return indeg;
    }
   
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph g=creategraph(numCourses,prerequisites);
        vector<int> indeg=indegree(g);
        for(int i=0;i<numCourses;i++){
            int j=0;
            for(;j<numCourses;j++){
                if(!indeg[j]){
                    break;
                }
            }
            if(j==numCourses){
                return false;
            }
            indeg[j]--;
            for(int adj:g[j]){
                indeg[adj]--;
            }
        }
    return true;
    }
};

