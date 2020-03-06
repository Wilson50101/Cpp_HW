#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 0xFFFFFFFF
using namespace std;
int main()
{
    //��J�I�Ƹ����
    int vertex_num,edge_num;
    cin>>vertex_num>>edge_num;

    /*
        �ĥ�adj list�s
        first�N����䤧���I
        second�N������v��
    */
    vector<pair<long long ,long long >> adj[vertex_num];
    for(int i=0;i<edge_num;i++)
    {
        long long node_begin; //�_�I
        long long node_end;   //���I
        long long weight;     //�䪺�v��

        //��J�䪺���(�_�I,���I,�䪺�v��)
        cin >>  node_begin  >>  node_end>>  weight;
        //�s�W��Ӱ_�I��adj list��
        adj[node_begin].push_back(make_pair(node_end,weight));
        //���V�ϻݭn��٪��s�Wlist
        adj[node_end].push_back(make_pair(node_begin,weight));
    }
    //�إ�priority queue��maintain decrease key���ާ@
    priority_queue< pair<long long ,long long>   ,   vector<pair<long long,long long>>   ,   greater<pair<long long,long long>>  >   PQ;

    //dist�N��̫�n�L�X�Ӫ��̵u�Z��
    //�Q��(vectex,INF)������l�ƨC�Ӥ���,�N���ΦA��for�j���l�ƤF
    vector<long long> dist(vertex_num,INF);

    /*
        ��l��priorty queue�Nvertex 0���淽�_�I
        make_pair(�_�I����I�̵u�Z��,���I�W��)
        �M�e��(make_pair(node_begin,weight))�O���@�˪��F�褣�n�d�V
    */
    PQ.push(make_pair(0,0));

    //0�O�_�I�G�̵u�Z����0
    dist[0]=0;

    //��priority queue�����Ů�,����ާ@
    while(!PQ.empty())
    {
            //���X�ثepriority queue �|���M�w�̵u���|���I��,�D��dist�̵u��,�M�w��dist�åB���է�s��LPQ����vertex���Z��
            long long u=PQ.top().second;
            PQ.pop();
            //foreach node adj to u�Ҷ�relax if ���Q
            for(auto x:adj[u])
            {
                long long v=x.first;
                long long weight=x.second;
                //�Yrelax �Y���Q�h:
                if(dist[v]>dist[u]+weight)
                {
                    //��sdist
                    dist[v]=dist[u]+weight;
                    /*
                        �N��s�᪺ pair(��v�̵u�Z��,�Iv)���PQ�̭�
                        �Y�t��k�̭���decrease key
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
