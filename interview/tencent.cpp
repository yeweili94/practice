#include <bits/stdc++.h>
using namespace std;
#define size 100

int N;
//����
int cost[size];
//����ֵ
int fight[size];
//��iΪֹ������С���
int mm[size];

void dfs(int index, int tot, int money) {
    if (index >= N) return;
    //��ǰ����ֵС��index��Ӧ�Ĺ���,ֻ������
    if (tot < fight[index]) {
        mm[index] = min(mm[index], money+cost[index]);
        dfs(index+1, tot+fight[index], money+cost[index]);
    } else {
        //��ǰ����ֵ����index��Ӧ�Ĺ���,�������������Ͳ���
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
