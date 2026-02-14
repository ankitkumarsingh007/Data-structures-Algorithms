class Solution {
public:
    int covered = 0;
    bool finishable(vector<vector<int>>& dependent, vector<int>& indegree, int i,
                    int numCourses) {
        indegree[i] = -1;
        covered++;

        if (covered == numCourses)
            return true;

        for (int a : dependent[i]) {
            indegree[a]--;
        }

        for (int a = 0; a < numCourses; a++) {
            if (indegree[a] == 0) {
                if (finishable(dependent, indegree, a, numCourses))
                    return true;
                else
                    return false;
            }
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> dependent(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto v : prerequisites) {
            dependent[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                covered = 0;
                if (finishable(dependent, indegree, i, numCourses))
                    return true;
                else
                    return false;
            }
        }

        return false;
    }
};