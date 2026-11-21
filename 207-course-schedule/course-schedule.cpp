class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> dependent(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto v : prerequisites) {
            dependent[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }

        int covered = 0;
        while (true) {
            bool flag = false;
            for (int i = 0; i < numCourses; i++) {
                if (indegree[i] == 0) {
                    indegree[i] = -1;
                    flag = true;
                    covered++;
                    for (int a : dependent[i])
                        indegree[a]--;
                }
            }
            if (!flag)
                break;
        }

        return covered == numCourses;
    }
};