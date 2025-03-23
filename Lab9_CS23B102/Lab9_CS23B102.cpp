#include <vector>
#include <iostream>

using namespace std;

struct Graph{
    vector<vector<int>> adjList;
    vector<vector<int>> compleAdjList;
    vector<vector<int>> SCC;
    vector<int> nodeWt;
    vector<int> visited; //0 white 1 gray 2 black
    vector<int> tFinish;
    int currtime;
    bool isCycle;
    void dfs(bool onComple){
            for(int ii = 0; ii < adjList.size(); ++ii){
                if(visited[ii] == 0){
                    dfsVisit(ii, onComple);
                }
            }
    }
    void dfsVisit(int u, bool onComple){
        currtime++;
        visited[u] = 1;
    
        auto &gAdjList = onComple ? compleAdjList: adjList;
        for(auto v : gAdjList[u]){

            if(visited[v] == 0){
                dfsVisit(v, onComple);
            }
            else{
                if(!onComple) isCycle = true;
            }
        }
        currtime++;
        visited[u] = 2;
        if(!onComple)tFinish.push_back(u);
        
    }

    // void findSCC(){
    //     visited.resize(visited.size(), 0);//reset visited list

    
    // }

    vector<bool> visitedscc;
    //code reference: https://cp-algorithms.com/graph/strongly-connected-components.html
    void dfsscc(int v, vector<vector<int>> onAdjList, vector<int> &output){
        visited[v]= true;
        for(auto u: onAdjList[v]){
            if(!visited[v]) dfsscc(u, onAdjList, output);
        }
        output.push_back(v);
    }

    void findscc(vector<vector<int>> &onAdjList, vector<vector<int>>&components, vector<vector<int>> &adjListCond){
        int n = onAdjList.size();
        components.clear();
        vector<int> order;
    }

    Graph(int n){
        adjList.resize(n);
        compleAdjList.resize(n);
        nodeWt.resize(n);

        visited.resize(n, 0);
        tFinish.reserve(n);
        currtime =0;
        isCycle = false;
      
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
            cout<<"WIP"<<endl;
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
        G.compleAdjList[v-1].push_back(u-1); //make transpose of G
        
    }
    G.dfs(false);
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
