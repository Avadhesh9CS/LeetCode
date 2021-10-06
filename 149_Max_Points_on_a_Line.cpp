/*
149. Max Points on a Line
Hard

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

Example 1:
Input: points = [[1,1],[2,2],[3,3]]
Output: 3

Example 2:
Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4

Constraints:
    1 <= points.length <= 300
    points[i].length == 2
    -104 <= xi, yi <= 104
    All the points are unique.
*/
class Solution {
    int gcd(int a,int b){
        if(b==0) return a;
        else return gcd(b,a%b);
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()<=2) return points.size();
        int res=0,overlap,verticle,localmax,dx,dy,g;
        unordered_map<string,int> m;
        string s;
        for(int i=0;i<points.size();i++){
            m.clear();
            overlap=0,verticle=0,localmax=0;
            for(int j=i+1;j<points.size();j++){
                dx=points[j][0]-points[i][0];
                dy=points[j][1]-points[i][1];
                if(dx==0 && dy==0){
                    overlap++;
                    continue;
                }else if(dx==0){
                    verticle++;
                }else{
                    g=gcd(dx,dy);
                    dx/=g;
                    dy/=g;
                    s=to_string(dx)+"_"+to_string(dy);
                    m[s]++;
                    localmax=max(m[s],localmax);
                } 
                localmax=max(localmax,verticle);
            }
            res=max(res,localmax+overlap+1);
        }
        return res;
    }
};
