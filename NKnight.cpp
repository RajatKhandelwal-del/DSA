#include <bits/stdc++.h>
using namespace std;

void printGrid(vector<vector<int>> &grid){
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid.size(); j++){
            cout << setw(3) << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << "--------------------------\n";
}

void knightsTour(vector<vector<int>> &grid,
                 int r, int c,
                 int moveCount){

    int n = grid.size();

    // Base Case: If all squares are filled
    if(moveCount == n*n){
        printGrid(grid);
        return;
    }

    // All 8 possible knight moves
    int dr[] = {1,2,2,1,-1,-2,-2,-1};
    int dc[] = {2,1,-1,-2,-2,-1,1,2};

    for(int i = 0; i < 8; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == -1){
            
            grid[nr][nc] = moveCount;

            knightsTour(grid, nr, nc, moveCount + 1);

            // Backtracking
            grid[nr][nc] = -1;
        }
    }
}

int main(){

    int n = 8;   // Change size here

    vector<vector<int>> grid(n, vector<int>(n, -1));

    // Start from (0,0)
    grid[0][0] = 0;

    knightsTour(grid, 0, 0, 1);

    return 0;
}