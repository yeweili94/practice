#include <vector>
#include <iostream>
using namespace std;

class UnionFind
{
private:
    int group_;
    vector<int> father_;
    vector<int> count_;
public:
    UnionFind(int N)
    {
        for (int i = 0; i < N; i++) {
            father_.push_back(i);
            count_.push_back(1);
        }
        group_ = N;
    }
    
    bool find(int p, int q)
    {
        return root(p) == root(q);
    }
    
    int root(int idx)
    {
        while(father_[idx] != idx) {
            father_[idx] = father_[father_[idx]];
            idx = father_[idx];
        }
        return idx;
    }
    
    void Union(int p, int q)
    {
        int x = root(p);
        int y = root(q);
        if (x == y) return;
        if (count_[x] > count_[y]) {
            father_[y] = x;
            count_[x] += count_[y];
        } else {
            father_[x] = y;
            count_[y] += count_[x];
        }
        group_--;
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if (rows <= 0) return;
        int cols = board[0].size();
        if (cols <= 0) return;
        int dummy = rows*cols+1;
        UnionFind uf(dummy);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int idx = i * rows + j;
                if ((i == 0 || i == rows-1 || j == 0 || j == cols-1) && board[i][j] == 'O') {
                    uf.Union(idx, dummy-1);
                } else if (board[i][j] == 'O'){
                    if (board[i-1][j] == 'O') {
                        uf.Union(idx, cols*(i-1)+j);
                    }
                    if (board[i+1][j] == 'O') {
                        uf.Union(idx, cols*(i+1)+j);
                    }
                    if (board[i][j-1] == 'O') {
                        uf.Union(idx, cols*(i)+j-1);
                    }
                    if (board[i][j+1] == 'O') {
                        uf.Union(idx, cols*(i)+j+1);
                    }
                }
            }
        }
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!uf.find(i*cols+j, dummy-1) && board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

void print(const vector<vector<char>>& board)
{
    int rows = board.size();
    int cols = board[0].size();
    for (int i = 0; i < rows; i++) {
        for (int j = 0;j < cols; j++) {
            std::cout << " " << board[i][j];
        }
        std::cout << std::endl;
    }
}
int main()
{
    vector<vector<char> > board = {{'X', 'O', 'X', 'X'}, {'O', 'X', 'O', 'X'}, {'X', 'O', 'X', 'O'}, {'O', 'X', 'O', 'X'}, {'X', 'O', 'X', 'O'}, {'O', 'X', 'O', 'X'}};
    std::cout << "before :" << std::endl;
    print(board);
    Solution* s = new Solution();
    s->solve(board);
    std::cout << "after :" << std::endl;
    print(board);
}
