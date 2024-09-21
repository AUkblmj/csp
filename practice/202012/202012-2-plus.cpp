//期末预测之最佳阈值

#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

const int N = 100010;

struct node
{
    int y;
    int res;
};

int m, tmp, ans, maxm;
node a[N];

bool cmp(node a, node b)
{
    /* if(a.y != b.y) return a.y < b.y;
    return a.res > b.res;   // 大于还是小于不重要，所以可以使用默认的升序 */
    return a.y < b.y;
}

int main()
{
    scanf("%d", &m);

    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &a[i].y, &a[i].res);
        if (a[i].y == 1)
        {
            tmp++;
        }
    }
    sort(a, a + m, cmp);

    maxm = tmp;
    ans = a[0].y;
    
    for(int i = 1; i < m; i++)
    {
        if(a[i - 1].res == 0) tmp++;
        else tmp--;

        if(tmp >= maxm && a[i].y > ans)
        {
            maxm = tmp;
            ans = a[i].y;
        }
    }

    printf("%d", ans);

    return 0;
}