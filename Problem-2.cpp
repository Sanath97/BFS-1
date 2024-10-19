// Time Complexity : O(n) where n is number of courses, since topo sort is traversing each node in graph once.
// Space Complexity : O(n+n+n) n is number of courses, space used for stack, dfs and visited array
// Did this code successfully run on Leetcode : yes
// Any problem you faced while coding this : no

class Solution {
private:
    void dfs(int node, unordered_map<int, vector<int>> graph, vector<int> visited, stack<int>& st)
    {
        visited[node] = 1;
        vector<int> adjs = graph[node];
        for(int i=0;i<adjs.size();i++)
        {
            if(visited[i]==0)
                dfs(i, graph, visited, st);
        }
        st.push(node);
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> visited(numCourses, 0);
        for(int i=0;i<prerequisites.size();i++)
        {
            int dep_course = prerequisites[i][0];
            int indep_course = prerequisites[i][1];
            if(graph.find(indep_course)==graph.end())
            {
                vector<int> vec = {dep_course};
                graph.insert(make_pair(indep_course, vec));
            }
            else
            {
                graph[indep_course].push_back(dep_course);
            }
        }

        stack<int> st;
        for(int i=0;i<numCourses;i++)
        {
            if(visited[i]==0)
                dfs(i, graph, visited, st);
        }


        return st.size() == numCourses;
    }
};