//灰度直方图

#include<iostream>

using namespace std;

const int N1 = 510, N2 = 260;

int n, m, L;
int A[N1][N1], h[N2];

int main()
{
    scanf("%d %d %d", &n, &m, &L);

    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &A[i][j]);
            h[A[i][j]]++;
        }
    }

    for(int i = 0; i < L; i++)
    {
        printf("%d ", h[i]);
    }


    return 0;
}