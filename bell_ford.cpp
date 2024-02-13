#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int cost[N];
class Edge
{
    public:
    int u,v,w;
    Edge(int u,int v,int w)
    {
        this->u = u; this->v = v; this->w =w;
    }

};
int main()
{
    int n,e;
    cin>>n>>e;
    vector<Edge> edgeList;
    while(e--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edgeList.push_back(Edge(u,v,w));
    }
    for(int i=1;i<=n;i++)
    {
        cost[i] = INT_MAX;
    }
    cost[1]=0;
    int totalCost = 0;
    for(int i=1;i<=n-1;i++)
    {
        for(Edge e:edgeList)
        {
            int u=e.u,v=e.v,w=e.w;
            if(cost[u]< INT_MAX && cost[u]+w<cost[v])
            {
                cost[v] = cost[u]+w;
            }

        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" "<<cost[i]<<endl;
    }
    return 0;
}