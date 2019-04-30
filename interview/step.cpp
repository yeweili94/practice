#include <bits/stdc++.h>
using namespace std;

struct node
{
  node(int x, int y, int k, int s) : x(x), y(y), key(k), step(s){}
  int x, y, key, step;  
};

char Graph[101][101];
int status[101][101], M, N;
int bfs(int x, int y);

int main()
{
    while (scanf("%d%d", &M, &N) != EOF) {
        for (int i = 0; i < M; i++) scanf("%s", Graph[i]);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (Graph[i][j] == '2') {
                    printf("%d\n", bfs(i, j));
                    return 0;
                }
            }
        }
    }
    return 0;
}

int bfs(int x,int y)
{
    queue<node> queue;
    queue.push(node(x, y, 0, 0));
    status[x][y] = 1;
    while (!queue.empty()) {
        node head = queue.front(); queue.pop();
        if (Graph[head.x][head.y] == '3') return head.step;
        int next[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for (int i = 0; i < 4; i++) {
            int key = head.key;
            int m = head.x + next[i][0];
            int n = head.y + next[i][1];
            if (m < 0 || m >= M || n < 0 || n >= N || status[m][n]) continue;
            if (Graph[m][n] >= 'a' && Graph[m][n] <= 'z') key |= (1<<(Graph[m][n]-'a'));
            if (Graph[m][n] >= 'A' && Graph[m][n] <= 'Z')
            {
                int shift = Graph[m][n] - 'A';
                if (!((1<<shift)&key)) continue;
            }
            node newnode(m, n, key, head.step+1);
            queue.push(newnode);
        }
        status[head.x][head.y] = 1;
    }
    return 0;
}
