// 期末预测之最佳阈值

#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

int m;
int r[N];
vector<PII> p;

bool predict(int y, int c)
{
    if(y < c) return false;
    return true;
}

bool cmp(PII a, PII b)
{
    if(a.y == b.y) return a.x > b.x;
    return a.y > b.y;
}

int main()
{
    scanf("%d", &m);

    for(int i = 0; i < m; i++)
    {
        int y;
        scanf("%d %d", &y, &r[i]);
        p.push_back({y, 0});
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(predict(p[j].x, p[i].x) == r[j]) p[i].y ++;
        }
    }

    sort(p.begin(), p.end(), cmp);
    
    // for(auto op : p)
    // {
    //     printf("%d %d\n", op.x, op.y);
    // }

    printf("%d", p[0].x);

    return 0;
}