// 期末预测之安全指数

#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;

int n, y;
int w[N];
int s[N];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> w[i] >> s[i];
        y += w[i] * s[i];
    }

    y = max(y, 0);

    cout << y ;

    return 0;
}
