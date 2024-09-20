//风险人群筛查

#include<iostream>

using namespace std;

int n, k, t, x1, y1, x2, y2;
int res1, res2;

bool check(int x, int y)
{
    if(x >= x1 && y >= y1 && x <= x2 && y <= y2) return true;
    return false;
}

int main()
{
    scanf("%d%d%d%d%d%d%d", &n, &k, &t, &x1, &y1, &x2, &y2);

    for(int i = 0; i < n; i++)
    {
        int cnt = 0, res = 0;
        bool flag = false;
        bool isHigh = false;
        for(int j = 0; j < t; j++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            if(check(x, y)) 
            {
                if(flag) cnt++;
                else cnt = 1;

                isHigh = true;
                flag = true;
                res = max(res, cnt);
            }
            else 
            {
                res = max(res, cnt);
                cnt = 0;
                flag = false;
            }
        }
        if(res >= k) 
        {
            res2++;
            //cout << "逗留" << endl;
        }
        if(isHigh) 
        {
            res1++;
            //cout << "经过" << endl;
        }
    }

    printf("%d\n%d", res1, res2);

    return 0;
}