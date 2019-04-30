#include <vector>
#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
public:
    int group;
    UnionFind(const vector<vector<bool>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        group = 0;
        // father.resize(row*col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == true) {
                    father[i*col+j] = i*col+j;
                    group++;
                }
            }
        }
    }
    
    void union(int p, int q) {
       father[p] = q;
        group--;
    }
    
    bool find(int p, int q) {
        return (root(p) == root(q));
    }
    
private:
    int root(int idx) {
        while (father[idx] != idx) {
            father[idx] = father[father[idx]];
            idx = father[idx];
        }
        return idx;
    }
    
    vector<int> father;
};

class Solution {
public:
    /**
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    int numIslands(vector<vector<bool>> &grid) {
        int row = grid.size();
        if (row <= 0) return 0;
        int col = grid[0].size();
        if (col <= 0) return 0;
        unionFind* uf = new UnionFind(grid);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                for (auto elem : dir) {
                    int x = i + elem[0];
                    int y = j + elem[1];
                    if (x >= 0 && x < row && y >= 0 && y < col) {
                        if (grid[x][y] == true) {
                            uf->union(col*i+j, x*col+j);
                        }
                    }
                }
            }
        }
        return uf->group;
    }
private:
    vector<vector<int>> dir = {{0,-1}, {0,1}, {1,0}, {-1,0}};
};

int main()
{
Solution* solu = new Solution();
vector<vector<bool> > grid = {{0, 0, 0, 0}};
std::cout << solu->numIslands();
}
