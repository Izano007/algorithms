#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const vector<int> dh{1,0,-1,0};
const vector<int> dw{0,1,0,-1};
const vector<int> ndh{-2,-2,-2,-1,-1,-1,-1,-1,0,0,0,0,1,1,1,1,1,2,2,2};
const vector<int> ndw{-1,0,1,-2,-1,0,1,2,-2,-1,1,2,-2,-1,0,1,2,-1,0,1};

bool is_safe(vector<vector<char>>& s,int nx,int ny)
{
	int h=s.size();
	int w=s[0].size();
	if(nx>=0 && ny>=0 && nx<h && ny<w) return true;
	return false;
}


void solve()
{
	int h,w;
	cin>>h>>w;
	vector<vector<char>> s(h,vector<char>(w));
	vector<vector<int>> dist(h,vector<int>(w,2e9+5));
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++) cin>>s[i][j];
	}
	deque<vector<int>> q;
	q.push_back({0,0});
	dist[0][0]=0;
	while(!q.empty())
	{
		vector<int> pos=q.front();
		q.pop_front();
		for(int k=0;k<4;k++)
		{
			int nx=pos[0]+dh[k];
			int ny=pos[1]+dw[k];
			if(is_safe(s,nx,ny) && s[nx][ny]=='.' && dist[nx][ny]>dist[pos[0]][pos[1]])
			{
				dist[nx][ny]=dist[pos[0]][pos[1]];
				q.push_front({nx,ny});
			}
		}
		for(int k=0;k<20;k++)
		{
			int nx=pos[0]+ndh[k];
			int ny=pos[1]+ndw[k];
			if(is_safe(s,nx,ny) && dist[nx][ny]>dist[pos[0]][pos[1]]+1)
			{
				dist[nx][ny]=dist[pos[0]][pos[1]]+1;
				q.push_back({nx,ny});
			}
		}
	}
	cout<<dist[h-1][w-1];
}

int main()
{
	fastio;
	solve();
	return 0;
}
