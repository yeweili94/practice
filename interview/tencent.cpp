#include <bits/stdc++.h>
using namespace std;
#define size 100

int N;
//开销
int cost[size];
//武力值
int fight[size];
//到i为止所需最小金额
int mm[size];

void dfs(int index, int tot, int money) {
    if (index >= N) return;
    //当前武力值小于index对应的怪兽,只能收买
    if (tot < fight[index]) {
        mm[index] = min(mm[index], money+cost[index]);
        dfs(index+1, tot+fight[index], money+cost[index]);
    } else {
        //当前武力值大于index对应的怪兽,分两种情况，买和不买
        mm[index] = min(mm[index], money);
        dfs(index+1, tot, money);
        dfs(index+1, tot+fight[index], money+cost[index]);
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> fight[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> cost[i];
    }
    for (int i = 0; i < N; i++) {
        mm[i] = INT_MAX;
    }
    dfs(0, 0, 0);
    cout << mm[N-1] << endl;
}
