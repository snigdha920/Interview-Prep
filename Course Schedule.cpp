class Solution {
public:
    // state - 1: visited, 2: visiting, 0: not touched
    unordered_map<int, int> state;
    vector<vector<int>> graph;
    vector<int> result;
    void createGraph(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0; i<numCourses; i++) {
           state[i] = 0;
        }
        for(int i=0; i<prerequisites.size(); i++) {
            int first = prerequisites[i][0];
            int second = prerequisites[i][1];
            graph[second].push_back(first);
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses+1, vector<int>());
        createGraph(numCourses, prerequisites);
        return doDfs(numCourses);
    }
    bool doDfs(int numCourses) {
        for(int i=0; i<numCourses; i++) {
            if(dfs(i) == false) return false;
        }
        return true;
    }
    bool dfs(int vertex) {
        if(state[vertex] == 1) return true;
        state[vertex] = 2;
        for(int i=0; i<graph[vertex].size(); i++) {
            if(state[graph[vertex][i]] == 2) {
                return false;
            }
            if(dfs(graph[vertex][i]) == false) return false; 
        }
        result.push_back(vertex);
        state[vertex] = 1;
        return true;
    }
};
