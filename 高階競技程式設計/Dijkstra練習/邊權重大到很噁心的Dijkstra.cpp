#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 0xFFFFFFFF
using namespace std;
int main()
{
    //輸入點數跟邊數
    int vertex_num,edge_num;
    cin>>vertex_num>>edge_num;

    /*
        採用adj list存
        first代表該邊之終點
        second代表該邊權重
    */
    vector<pair<long long ,long long >> adj[vertex_num];
    for(int i=0;i<edge_num;i++)
    {
        long long node_begin; //起點
        long long node_end;   //終點
        long long weight;     //邊的權重

        //輸入邊的資料(起點,終點,邊的權重)
        cin >>  node_begin  >>  node_end>>  weight;
        //新增到該起點的adj list中
        adj[node_begin].push_back(make_pair(node_end,weight));
        //雙向圖需要對稱的新增list
        adj[node_end].push_back(make_pair(node_begin,weight));
    }
    //建立priority queue來maintain decrease key等操作
    priority_queue< pair<long long ,long long>   ,   vector<pair<long long,long long>>   ,   greater<pair<long long,long long>>  >   PQ;

    //dist代表最後要印出來的最短距離
    //利用(vectex,INF)直接初始化每個元素,就不用再用for迴圈初始化了
    vector<long long> dist(vertex_num,INF);

    /*
        初始化priorty queue將vertex 0為單源起點
        make_pair(起點到該點最短距離,該點名稱)
        和前面(make_pair(node_begin,weight))是不一樣的東西不要搞混
    */
    PQ.push(make_pair(0,0));

    //0是起點故最短距離為0
    dist[0]=0;

    //當priority queue不為空時,持續操作
    while(!PQ.empty())
    {
            //取出目前priority queue 尚未決定最短路徑的點中,挑其dist最短的,決定其dist並且嘗試更新其他PQ中的vertex之距離
            long long u=PQ.top().second;
            PQ.pop();
            //foreach node adj to u皆須relax if 有利
            for(auto x:adj[u])
            {
                long long v=x.first;
                long long weight=x.second;
                //即relax 若有利則:
                if(dist[v]>dist[u]+weight)
                {
                    //更新dist
                    dist[v]=dist[u]+weight;
                    /*
                        將更新後的 pair(到v最短距離,點v)丟到PQ裡面
                        即演算法裡面的decrease key
                    */
                    PQ.push((make_pair(dist[v],v)));
                }
            }
    }
    for(int i=0;i<vertex_num-1;i++)
        cout<<dist[i]<<" ";
    cout<<dist[vertex_num-1];
    return 0;
}
