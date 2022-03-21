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

vector<int> prefix(string &s)
{
    int n = s.length();
    vector<int> p(n + 1);
    p[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        int k = p[i - 1];
        while (k >= 0 && s[k] != s[i - 1])
            k = p[k];
        p[i] = k + 1;
    }
    return p;
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

void KMPSearch_good(string &t, string &s)
{
    string search = s + '#' + t;
    vector<int> ans = prefix(search);
    for (int i = 0; i < (int)ans.size(); i++)
    {
        if (ans[i] == (int)s.length())
            cout << i - 1 - 2 * (int)s.length() << ' ' << i - 1 - (int)s.length() << '\n';
    }
}

int main()
{
    string text, pattern;
    cin >> text >> pattern;
    vector<int> pimat = createLPS(pattern);
    KMPSearch(text, pattern, pimat);
    // KMPSearch_good(text, pattern);
}
