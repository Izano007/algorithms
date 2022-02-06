#include <iostream>
using namespace std;

const int MAX = 1e5 + 5;
int id[MAX], size_grp[MAX], rank_grp[MAX];

void init_size(int n)
{
    for (int i = 0; i < n; i++)
    {
        id[i] = i;
        size_grp[i] = 1;
    }
}

void init_rank(int n)
{
    for (int i = 0; i < n; i++)
    {
        id[i] = i;
        rank_grp[i] = 0;
    }
}

int root(int x)
{
    while (id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union_size_grp(int x, int y)
{
    int pp = root(x);
    int qq = root(y);
    if (pp != qq)
    {
        if (size_grp[pp] < size_grp[qq])
            swap(pp, qq);
        id[qq] = pp;
        size_grp[pp] += size_grp[qq];
    }
}

void union_rank_grp(int x, int y)
{
    int pp = root(x);
    int qq = root(y);
    if (pp != qq)
    {
        if (rank_grp[pp] < rank_grp[qq])
            swap(pp, qq);
        id[qq] = pp;
        if (rank_grp[pp] == rank_grp[qq])
            rank_grp[pp]++;
    }
}
