#include <bits/stdc++.h>

using namespace std;

class Graph{
    public:

        void operator +(Graph H){
            int N1 = adjList.size();
            int N2 = H.adjList.size();

            if(N2> N1){
                for(int ii = 0; ii < N1; ii++){
                    //H is bigger, insert into H fron G
                    set<int> adj= adjList[ii];
                    for(auto ele: adj){
                        H.adjList[ii].insert(ele);
                    }
                }
                adjList= H.adjList;
            }
            else{
                for(int ii =0; ii< N2; ii++){
                    set<int> adj = H.adjList[ii];
                    for(auto ele: adj){
                        adjList[ii].insert(ele);
                    }
                }
            }
            
            
        }
        void operator -(Graph &H){

            int N1 = adjList.size();
            int N2 = H.adjList.size();
            //vertex set union, but edge set 
            if(N2> N1){
                adjList.resize(N2);
            }
            else{
                H.adjList.resize(N1); //Make sure both are of same size 
            }
            for (int ii = 0; ii < N2; ii++)
            {
                set<int> &adj = adjList.at(ii);
                set<int> &Hadj = H.adjList[ii];

                for(auto it = adj.begin(); it != adj.end();){
                    if(Hadj.find(*it) == Hadj.end()){
                        it = adj.erase(it);
                    }
                    else{
                        it++;
                    }
                }
            }
        }
        void operator !(){
            int N = adjList.size();

               set<int> comple;
               auto hint = comple.end();
               for(int i =0 ; i< N; i++) {
                comple.emplace_hint(hint, i);
               }
            for(int ii= 0; ii< N ; ii++){
                set<int> nbrset = adjList[ii];
                set<int> result;

                set_difference(comple.begin(), comple.end(), nbrset.begin(), nbrset.end(), inserter(result, result.begin()));
                result.erase(ii);
               adjList[ii]= result;


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
                visited.insert(front);
                q.pop();

                if(front == v2){
                    return true;
                }

                for(auto nbr: adjList[front]){
                    if(visited.find(nbr) == visited.end()){
                    q.push(nbr);
                    visited.insert(nbr);
                    }
                }
            }
            return false; //TODO
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
        else if(command == "complement"){
            !G;
        }

        else if(command == "isReachable"){
            if(G.isReachable()){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
        else if(command == "union"){
            string _ ;
            cin>> _;
            Graph H;
            cin>>H;
            G + H;
        }
        else if(command == "intersection"){
            string _ ;
            cin>> _;
            Graph H;
            cin>>H;
            G - H;
        }
    }
    while(command != "end");
}


