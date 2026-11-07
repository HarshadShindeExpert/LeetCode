class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> available;
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> busy;

        int n = servers.size();
        int m = tasks.size();

        for(int i = 0; i < n; i++)
            available.push({servers[i], i});

        vector<int> ans(m);
        long long time = 0;

        for(int i = 0; i < m; i++)
        {
            time = max(time, (long long)i);

            while(!busy.empty() && busy.top()[0] <= time)
            {
                auto temp = busy.top();
                busy.pop();

                available.push({temp[1], temp[2]});
            }

            if(available.empty())
            {
                time = busy.top()[0];

                while(!busy.empty() && busy.top()[0] <= time)
                {
                    auto temp = busy.top();
                    busy.pop();

                    available.push({temp[1], temp[2]});
                }
            }

            auto temp = available.top();
            available.pop();

            int weight = temp.first;
            int index = temp.second;

            ans[i] = index;

            busy.push({time + tasks[i], weight, index});
        }

        return ans;
    }
};