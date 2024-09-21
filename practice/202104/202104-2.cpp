// 邻域均值

#include<iostream>
#include<cstring>

using namespace std;

const int N = 610;

int n, L, r, t;
int a[N][N], s[N][N];
int res;

bool check(int x, int y)
{
    int maxx = min(n, x + r);
    int maxy = min(n, y + r);
    int minx = max(1, x - r);
    int miny = max(1, y - r);
    int cnt = (maxx - minx + 1) * (maxy - miny + 1);
    int sum = s[maxx][maxy] - s[minx - 1][maxy] - s[maxx][miny - 1] + s[minx - 1][miny - 1];
    double avg = (double)sum / (double)cnt;
    return avg <= (double)t;
}

int main()
{
    scanf("%d %d %d %d", &n, &L, &r, &t);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(check(i, j)) res++;
        }
    }

    printf("%d", res);

    return 0;
}