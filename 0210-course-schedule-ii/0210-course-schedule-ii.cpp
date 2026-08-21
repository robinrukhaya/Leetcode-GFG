class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        // Build graph and calculate indegree
        for (auto pair : prerequisites) {
            int course = pair[0];
            int prerequisite = pair[1];

            adj[prerequisite].push_back(course);
            indegree[course]++;
        }

        // Put courses with no prerequisites into queue
        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> answer;

        // Kahn's Algorithm
        while (!q.empty()) {

            int course = q.front();
            q.pop();

            answer.push_back(course);

            for (auto neighbour : adj[course]) {

                indegree[neighbour]--;

                if (indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        // Cycle exists
        if (answer.size() != numCourses) {
            return {};
        }

        return answer;
    }
};