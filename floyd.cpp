#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    int mat[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = INT_MAX;
            if (i == j)
            {
                mat[i][j] = 0;
            }
        }
    }
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        mat[u][v] = w;
    }
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][k]+ mat[k][j]< mat[i][j])
                {
                    mat[i][j] = mat[i][k]+ mat[k][j];
                }
            }
        }
    }
    for(int i=0; i < n; i++)
    {
        if(mat[i][i]<0)
        {
            cout<<"Cycle Detect!"<<endl;
            break;
        }
    }
    if (n >= 4)
    {
        cout << mat[3][2] << endl;
    }
    return 0;
}