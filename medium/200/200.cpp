#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    grid[i][j] = '0';
                    dfs(grid, i, j);
                    num++;
                }
            }
        }
        return num;
    }

    void dfs(vector<vector<char>>& grid, int x, int y){
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == '1'){
                grid[nx][ny] = '0';
                dfs(grid, nx, ny);
            }
        }
    }
};