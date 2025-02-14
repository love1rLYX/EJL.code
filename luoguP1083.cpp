#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n,m;
int diff[1000011],need[1000011],rest[1000011],r[1000011],l[1000011],d[1000011];//d[i]表示第i天需要的教室数量，diff数组是差分数组
bool isok(int x)
{
    memset(diff,0,sizeof(diff));
    for(int i = 1;i <= x;i ++)
    {
        diff[l[i]] += d[i];
        diff[r[i+1]] -= d[i];
    }
    for(int i = 1;i <=n;i ++)
    {
        need[i] = need[i-1] + diff[i];
        if(need[i] > rest[i]) return -1;
    }
    return 1;
}

int main()
{
    cin >> n >> m;
    for(int i = 1;i <= n;i ++) scanf("%d",&rest[i]);
    for(int i = 1;i <= m;i ++) scanf("%d%d%d",&d[i],&l[i],&r[i]);
    int begin = 1,end = m;
    if(isok(m)) {cout << "0";return 0;}
    while (begin < end)
    {
        int mid = (begin + end)/2;
        if(isok(mid)) begin = mid + 1;
        else end = mid;
    }
    cout << "-1" << endl << begin;
    return 0;
}
