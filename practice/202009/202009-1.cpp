// 称检测点查询

#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

const int N = 210;

struct point
{
    int id;
    int x;
    int y;
    double dist;
};

int n, X, Y;
point a[N];

bool cmp(point x, point y)
{
    if(x.dist == y.dist) return x.id < y.id;
    return x.dist < y.dist;
}

int main()
{
    scanf("%d%d%d", &n, &X, &Y);

    for(int i = 1; i <= n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[i].id = i;
        a[i].x = x;
        a[i].y = y;
        a[i].dist = sqrt((double)pow(x - X, 2) + (double)pow(y - Y, 2));
    }

    sort(a + 1, a + 1 + n, cmp);

    printf("%d\n%d\n%d", a[1].id, a[2].id, a[3].id);

    return 0;
}
