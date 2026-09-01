class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int sx = 0, sy = 0;
        vector<pair<int,int>> litter;
        int total = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(classroom[i][j] == 'S')
                {
                    sx = i;
                    sy = j;
                }

                if(classroom[i][j] == 'L')
                {
                    litter.push_back({i,j});
                    total++;
                }
            }
        }

        if(total == 0) return 0;

        int full = (1 << total) - 1;
        vector<vector<vector<vector<int>>>> dist(m, vector<vector<vector<int>>>(n, vector<vector<int>>(energy + 1, vector<int>(1 << total, -1))));
        
        queue<tuple<int,int,int,int>> q;
        q.push({sx, sy, energy, 0});
        dist[sx][sy][energy][0] = 0;

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        while(!q.empty())
        {
            auto [x, y, e, mask] = q.front();
            q.pop();

            int moves = dist[x][y][e][mask];

            if(mask == full)
                return moves;

            for(int d = 0; d < 4; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if(nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;

                if(classroom[nx][ny] == 'X')
                    continue;

                if(e == 0)
                    continue;

                int ne = e - 1;
                int nmask = mask;

                for(int i = 0; i < total; i++)
                {
                    if(litter[i].first == nx && litter[i].second == ny)
                        nmask |= (1 << i);
                }

                if(classroom[nx][ny] == 'R')
                    ne = energy;

                if(dist[nx][ny][ne][nmask] == -1)
                {
                    dist[nx][ny][ne][nmask] = moves + 1;
                    q.push({nx, ny, ne, nmask});
                }
            }
        }

        return -1;
    }
};