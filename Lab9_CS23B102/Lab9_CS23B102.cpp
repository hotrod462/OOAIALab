#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

struct Graph{
    int n;
    vector<vector<int>> adjList;
    vector<vector<int>> transAdj;
    vector<vector<int>> condAdj;
    int compCtr;
    unordered_map<int,vector<int>> components;
    vector<int> nodeWt;
    vector<int> visited; //0 white 1 gray 2 black
    bool isCycle;
    int maxEvent;

    Graph(int n_in):n(n_in){
        //reserve output size to n
        visited.resize(n, 0);
        adjList.resize(n, {});
        transAdj.resize(n, {});

        compCtr=0;
        nodeWt.resize(n);
        visited.resize(n, 0);
        isCycle = false;
        maxEvent = 0;
    }
    void dfs(int u, vector<vector<int>> & adj ,vector<int> &output){
        visited[u] = 1;//mark u from white to gray
        for(auto v : adj[u]){
            if(visited[v] == 0){
                dfs(v, adj, output);
            }
            else{
                isCycle = true;//should this be set while doing dfs on G^T also?
            }
        }
        visited[u]= 2; //mark as black;
        output.push_back(u);
    }

    void scc(){
        vector<int> order;

        for(int ii = 0; ii < n; ++ii){
            if(visited[ii] == 0){
                dfs(ii, adjList, order);
            }
        }

        visited.assign(n, 0);

        reverse(order.begin(), order.end());

        vector<int> roots(n, 0);

        for(auto v: order){
            if(visited[v] == 0){
                compCtr++;

                vector<int> component;
                dfs(v, transAdj, component);
                components.insert({compCtr, component});
                maxEvent = component.size()> maxEvent ? component.size() : maxEvent;
                int root = *min_element(component.begin(), component.end());
                for(auto u : component){
                    roots[u] = root;
                }
            }
        }

        //make condGraph
        condAdj.assign(n, {});

        for(int v = 0; v < n; ++v){
            for(auto u: adjList[v]){
                if(roots[v] != roots[u]){
                    condAdj[roots[v]].push_back(roots[u]);
                }
            }
        }

        



    }

};
class GraphAlgorithm{
    public: 
    virtual void Query(Graph &G) = 0;


};  

class isCycle: public GraphAlgorithm{
    public:
        void Query(Graph &G){
            if(G.isCycle){
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;
        }
};

class indepComponent: public GraphAlgorithm{
    public:
        void Query(Graph &G){
            cout<<G.components.size()<<" " << G.maxEvent<<endl;
        }
};

class validOrder: public GraphAlgorithm{
    public:
        void Query(Graph &G){
            if(G.isCycle){
                cout<<"NO"<<endl;
            }
            else{

            }
        }
};

class maxHype: public GraphAlgorithm{
    public: 
        void Query(Graph &G){
            cout<<"WIP"<<endl;
        }
};

int main(){
     int n, m;
     cin>>n>>m;
     Graph G(n);
     for(int ii =0; ii < n; ++ii){
        cin>>G.nodeWt[ii];
     }
    for(int ii =0; ii < m; ++ii){
        int u, v;
        cin>>u>>v;

        G.adjList[u-1].push_back(v-1);
        G.transAdj[v-1].push_back(u-1); //make transpose of G
        
    }
    G.scc();
    int Q;
    cin>>Q;
    for(int ii = 0; ii < Q; ++ii){
        int qnum;
        cin>>qnum;
        if(qnum == 1){
            isCycle c1;
            c1.Query(G);
        }
        else if(qnum ==2){
            indepComponent i1;
            i1.Query(G);
        }
        else if(qnum == 3){
            validOrder v1;
            v1.Query(G);
        }
        else {
            maxHype m1;
            m1.Query(G);
        }
    }


}
