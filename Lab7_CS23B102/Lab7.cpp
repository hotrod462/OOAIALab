#include <bits/stdc++.h>
#define ll long long 

using namespace std;
struct Comparator{
    string sortOrder;
    Comparator(string sorton):sortOrder(sorton){}
    bool operator()(const long long &x, const ll &y){
        if(sortOrder == "ascending"){
            if(x == y) return true; //if both are equal, take the one from the left for merge, inv count will be correct only for this
            return x < y; // if true, x is smaller, is right choice for mergine
        }
        else {
            return x > y; // if true, x is larger, is right choice for merging
        }

    }
};

class Board{
    public:
    ll n;
    ll invCount;
    vector<ll> flatmat;
    vector<vector<ll>> mat;
    Board(ll n_in): n(n_in), invCount(0){
        flatmat.resize(n_in*n_in);
        mat.resize(n, vector<long long int>(n));    
    }

    void createMat(){
        for(ll i = 0; i < n*n ; i ++){
            ll temp;
            cin>>temp;
            flatmat[i]= temp;
            mat[i/n][i%n] = temp;
        }
    }

    void sortRows(Comparator comparator){

        for(ll ii = 0; ii < n; ii++){
            mergeSort(mat[ii], 0, n-1, comparator, false);// changed to high val to n-1 as its included
        }
    }
     
    ll countInversions(){
        Comparator c1("ascending");
        mergeSort(flatmat, 0, n * n, c1, true);
        return invCount;        
    }

    void mergeSort(vector<ll> &toSort, ll l, ll h, Comparator &comparator, bool isInvcounting){
        if(l < h){
        ll m = l + (h- l )/2;

        mergeSort(toSort, l, m, comparator, isInvcounting);
        mergeSort(toSort, m+1, h, comparator, isInvcounting);

        mergeArr(toSort, l , m , h, comparator, isInvcounting);//toggle inv counting behaviour here
        }
    }

    void mergeArr(vector<ll>&A, ll l, ll m, ll h, Comparator comparator, bool isInvCounting){
        vector<ll> Asorted;
        ll ptrL = l;
        ll ptrR= m +1;

        while(ptrL < m+1 && ptrR < h+1){
            bool leftadd = comparator(A[ptrL], A[ptrR]);
            if( leftadd){
                Asorted.push_back(A[ptrL]);
                ptrL++;
            }
            else{
                Asorted.push_back(A[ptrR]);
                ptrR++;
            }
        }
        if(ptrL <= m ){
            for(ll i = ptrL; i < m+1; i++){
                Asorted.push_back(A[i]);
            }
        }
        if(ptrR <= h){
            for(ll i = ptrR; i < h+1; i++){
                Asorted.push_back(A[i]);
            }
        }
        for(ll ii =l ; ii <=h; ii++){
            A[ii] = Asorted[ii - l];
        }



    }

    void display(){
        for(ll ii = 0; ii < n; ii++){
            for(ll jj = 0; jj < n ; jj++){
                cout<<mat[ii][jj]<<" ";
            }
            cout<<endl;
        }
    }




};

struct PointComp{
    bool operator()(pair<ll, ll> pt1, pair<ll, ll> pt2, string coordVal){
        if(coordVal == "x"){
            return pt1.first > pt2.first;
        }
        else return pt1.second > pt2.second;
    }
};

class Olympics{
    vector<pair<ll, ll>> pts;
    vector<pair<ll, ll>> xSortPts;
    vector<pair<ll, ll>> ySortPts;

    void closestPair(){

    }
};

int main(){
    string _;
    cin>>_;
    ll n;
    cin>>n;
    Board b1(n);
    for(ll ii = 0; ii < n; ii++){
        for(ll jj = 0; jj < n; jj++){
            ll ele;
            cin>> ele;
            b1.mat[ii][jj] = ele;
            b1.flatmat[ii * n + jj] = ele;
        }
    }

    Olympics o1;
    while(true){

        string command;
        cin>>command;
        if(command == "SORT_2D"){
            string compBy;
            cin>>compBy;
            Comparator c1(compBy); 
            b1.sortRows(c1);
        }
        if(command == "INVERSION_2D"){
            cout<<b1.countInversions()<<endl; 
            
        }

        if(command == "DISPLAY_2D"){
            b1.display();
        }
        if(command == "CLOSEST_2D"){
            continue; // for now
        }
        if(command == "END"){
            break;
        }
    }
    return 0;
}