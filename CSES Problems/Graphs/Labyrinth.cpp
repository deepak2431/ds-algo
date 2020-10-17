#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{

    long long int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            arr[i].push_back(ch);
        }
    }

    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int start_x = -1, start_y = -1, end_x = -1, end_y = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 'A')
            {
                start_x = i;
                start_y = j;
            }
            if (arr[i][j] == 'B')
            {
                end_x = i;
                end_y = j;
            }
        }
    }

    if(start_x == -1 || end_x == -1) {
        cout << "NO" << endl;
        return 0;
    }
    vector<vector<int>> grid(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '#')
            {
                grid[i].push_back(1);
            }
            else
            {
                grid[i].push_back(0);
            }
        }
    }
    vector<string> dir;
    queue<pair<int, int>> q;
    q.push(make_pair(start_x, start_y));
    grid[start_x][start_y] = 1;

    while (!q.empty())
    {

        auto temp = q.front();
        int x = temp.first, y = temp.second;
        if (x == end_x && y == end_y)
        {
            cout << "YES" << endl;
            cout << dir.size() << endl;
            for(int i = 0; i < dir.size(); i++)
                cout << dir[i];
            cout << endl; 
            return 0;
        }

        for (auto &dr : directions)
        {
            int dx = x + dr[0];
            int dy = y + dr[1];

            if (dx >= 0 && dx < n && dy >= 0 && dy < m && grid[dx][dy] == 0)
            {
                q.push(make_pair(dx, dy));
                grid[dx][dy] = 1 + grid[x][y];
                grid[dx][dy] = 1;
                if(dr[0] == 0 && dr[1] == 1) {
                    dir.push_back("R");
                }
                else if(dr[0] == 0 && dr[1] == -1) {
                    dir.push_back("L");
                }
                else if(dr[0] == -1 && dr[1] == 0) {
                    dir.push_back("U");
                }
                else if(dr[0] == 1 && dr[1] == 0) {
                    dir.push_back("D");
                }
            }
        }
        q.pop();
    }

    cout << "NO" << endl;

    return 0;
}