#include <bits/stdc++.h>
using namespace std;

vector<int> createLPS(string &pat)
{
    int n = pat.length();
    vector<int> lps(n + 1);
    int i = 2, len = 0;
    while (i <= n)
    {
        if (pat[i - 1] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void KMPSearch(string &text, string &pattern, vector<int> &lps)
{
    int M = text.length();
    int N = pattern.length();
    int i = 0, j = 0;
    while (i < M)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }
        if (j == N)
        {
            cout << "Found at index: " << i - j << endl;
            j = lps[j];
        }
        else if (i < M && pattern[j] != text[i])
        {
            if (j != 0)
                j = lps[j];
            else
                i = i + 1;
        }
    }
}

int main()
{
    string text, pattern;
    cin >> text >> pattern;
    vector<int> pimat = createLPS(pattern);
    KMPSearch(text, pattern, pimat);
}
