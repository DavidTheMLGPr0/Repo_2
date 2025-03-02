#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("pluricex1.in");
ofstream g ("pluricex1.out");

int n, p[11], v[11], k, d, a[23][23];

void sol()
{
    int s[11] = {0}, i, j;
    for (i = 1; i <= n; i++)
        for (j = 1; a[v[i]][j] != 0; j++)
            s[a[v[i]][j]] = 1;
    bool okay = 1;
    for (i = 1; i <= d; i++)
        if (s[i] == 0)
            okay = 0;
    if (okay == 1)
    {
        for (i = 1; i <= k; i++)
            g << v[i] << " ";
        g << endl;
    }
}
void back_tracking(int y)
{
    int i;
    for (i = v[y - 1] + 1; i <= n; i++)
    {
        v[y] = i;
        if (k == y)
            sol();
        else
            back_tracking(y + 1);
    }
}
int main()
{
    int i, j, nr;
    f >> n >> k >> d;
    for (i = 1; i <= n; i++)
    {
        f >> nr;
        for (j = 1; j <= nr; j++)
            f >> a[i][j];
    }
    back_tracking(1);
}
