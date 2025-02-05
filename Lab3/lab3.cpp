#include <bits/stdc++.h>

using namespace std;

class Graph{
    public:

        Graph operator -(){
            Graph H;
            for(int ii= 0; ii< adjList.size(); ii++){
                set<int> nbrset = adjList[ii];
               set<int> comple;
               for(int i =0 ; i< adjList.size(); i++) {
                comple.insert(i);
               }
               for(auto nbr: nbrset){
                comple.erase(nbr);
               }

               adjList[ii]= comple;


            }

        }

        void addEdge() {
            int first, second;
            cin>>first>>second;

            adjList[first].insert(second);
            adjList[second].insert(first); //both should have
        }

        void removeEdge(){
            int first, second;
            cin>> first>>second;

            adjList[first].erase(second);// BUG- what if edge doesnt exist?
            adjList[second].erase(first); // remove both as undirected
        }

        void printGraph(){
            //implement printing here
            int ctr =0;
            for(auto adjset : adjList){
                cout<<"Vertex "<<ctr<<":";
                for(auto adjto: adjset){
                    cout<<" "<< adjto;
                }
                ctr++;
                cout<<endl;
            }
        }

        bool isReachable(){
            int v1, v2;
            cin>>v1>>v2;

            //do BFS
            queue<int> q;
            unordered_set<int> visited;

            q.push(v1);
            while(!q.empty()){
                int front = q.front();
                q.pop();

                for(auto nbr: adjList[front]){
                    q.push(nbr);
                }
            }

        }

    private:
        vector<set<int>> adjList;

    friend void operator>>(
    istream& stream, Graph &G);

};

void operator>>(
    istream& stream, Graph &G){
        int N, M;
        cin>>N>>M;
        G.adjList.resize(N);

        for(int i = 0; i< M; i++){
            G.addEdge();
        }       
    }

void operator <<(
    ostream& stream, Graph &G){
        G.printGraph();
        
    }

int main(){
    string command;
    Graph G;
    do{
        cin>>command;
        if(command == "Graph"){
            cin>>G;  
        }
        else if(command == "printGraph"){
            cout<<G;
        }
        else if(command == "add_edge"){
            G.addEdge();
        }
        else if(command == "remove_edge"){
            G.removeEdge();
        }

    }
    while(command != "end");



}