#include <bits/stdc++.h>
using namespace std;
#define MAX 200005
int a[MAX], nodes, edges;
pair <long long, pair<int, int> > p[MAX];
#define N 100005 //graph size

vector< pair<int,int> > mygraph[N]; 
int subsize[N], n; 
long long res;
long long ans[400005];
void awake()
{
    for(int i = 0; i < MAX; ++i) a[i] = i;
    for(int i = 0; i < 400005; i++) ans[i] = 0;
}

int change(int x)
{
    while(a[x] != x) 
    {
        a[x] = a[a[x]];
        x = a[x];
    }
    return x;
}

void myunion(int x, int y)
{
    int p = change(x);
    int q = change(y);
    a[p] = a[q];
}

long long kruskal(pair<long long, pair<int, int> > p[])
{
    int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0; i < edges;++i)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(change(x) != change(y))
        {
            minimumCost += cost;
            mygraph[x].push_back(make_pair(y,cost));
            mygraph[y].push_back(make_pair(x,cost));
            myunion(x, y);
        }    
    }
    return minimumCost;
}

void dfs(int node, int cost, int parent)
    {
        subsize[node]=1; 
        for(auto it:mygraph[node])
        {
            int next=it.first;
            int c=it.second;
            if(next != parent)
            {
                dfs(next, c, node);
                subsize[node] += subsize[next]; 
            }
        }
        
        long long fre = ((long long)(n-subsize[node])) * ((long long)subsize[node]);
        if(fre != 0) ans[cost] = ((long long)(n-subsize[node])) * ((long long)subsize[node]);
    }
int main()
{
    int x, y;
    long long weight, cost, minimumCost;
    awake();
    scanf("%d %d", &nodes, &edges);
    n=nodes;
    for(int i = 0; i < edges; ++i)
    {
        scanf("%d %d %lld", &x, &y, &weight);
        p[i] = make_pair(weight, make_pair(x, y));
    }
    sort(p, p + edges);
    minimumCost = kruskal(p);
    res = 0;
    dfs(1, 0, -1);
    for (int i = 0; i < 400004; i++)
    {
        if(ans[i] != 0){
            ans[i+1] += ans[i]/2 ;
            ans[i] = ans[i]%2 ;
        }
    }
    int pos = -1 ;
    for(int i = 400005; i >= 0; i--){
        if(ans[i] == 1){
            pos = i;
            break;
        }
    }
    if(pos == -1) printf("0\n");
    else
    {
        for(int i = pos; i >= 0; i--)
        printf("%lld", ans[i]);
    }
    printf("\n");
    return 0;
}