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
    
    Board():  invCount(0){}
    void initBoard(ll n_in ){
        n = n_in;

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
        //
        
    }
     
    ll countInversions(){
        //flatten matrix into flatmat;
        for(ll ii = 0; ii < n ; ii++){
            for(ll jj = 0; jj < n ; jj++){
                flatmat[ii*n + jj] = mat[ii][jj];
            }
        }
        Comparator c1("ascending");
        invCount =0;
        mergeSort(flatmat, 0, (n * n) -1 , c1, true);
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
                if(isInvCounting) invCount += (m - ptrL + 1);// +1 here for accuracy
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
struct Point{
    ll x;
    ll y;
    ll inpIdx;
    Point(ll inX, ll inY, ll inInpIdx): x(inX), y(inY), inpIdx(inInpIdx){}
};
struct PtComparator{
    
    bool operator()(Point &p1, Point&p2, bool isCmpX){
        if(isCmpX){
            return p1.x < p2.x;
        }
        else return p1.y < p2.y;
    }
};


struct PointPair{
    Point a;
    Point b;
    double dist;
};

class Olympics{
    public:
    vector<Point> pts;
    vector<Point> xSortPts;
    vector<Point> ySortPts;
    ll noPts;

    void mergeSort(vector<Point> &toSort, ll l, ll h, PtComparator &comparator, bool isCmpX){
        if(l < h){
        ll m = l + (h- l )/2;

        mergeSort(toSort, l, m, comparator, isCmpX);
        mergeSort(toSort, m+1, h, comparator, isCmpX);

        mergeArr(toSort, l , m , h, comparator, isCmpX);//toggle inv counting behaviour here
        }
    }

    void mergeArr(vector<Point>&A, ll l, ll m, ll h, PtComparator comparator, bool isCmpX){
        vector<Point> Asorted;
        ll ptrL = l;
        ll ptrR= m +1;

        while(ptrL < m+1 && ptrR < h+1){
            bool leftadd = comparator(A[ptrL], A[ptrR], isCmpX);
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

    double distance(Point &a, Point &b){
        return sqrt((a.x - b.x)*(a.x - b.x) + (a.y- b.y)*(a.y - b.y));
    }
    double lineDistance(Point &line, Point &a){
        return abs(line.x - a.x);
    }
    PointPair tiebrk(PointPair &ptPr1, PointPair&ptPr2){
        if(ptPr1.dist <  ptPr2.dist){
            return ptPr1;
        }
        else if(ptPr1.dist == ptPr2.dist){
            if(ptPr1.a.x < ptPr2.a.x) return ptPr1;
            else if(ptPr1.a.x > ptPr2.a.x) return ptPr2;
            else { //x coord of matches
            if(ptPr1.a.y < ptPr2.a.y) return ptPr1;
            else if(ptPr1.a.y > ptPr2.a.y) return ptPr2;
            else{
                //first pt is same
                if(ptPr1.b.x < ptPr2.b.x) return ptPr1;
                else if (ptPr1.b.x> ptPr2.b.x) return ptPr2;
                else{
                    if(ptPr1.b.y< ptPr2.b.y) return ptPr1;
                    else if(ptPr1.b.y > ptPr2.b.y) return ptPr2;
                    else{
                        //both points are same
                        
                        return ptPr1;
                    }
                }

            }

            }
        }
        else return ptPr2;
    }
    void populatePts(){
        
        cin>>noPts;

        for(ll ii = 0; ii < noPts; ii ++){
            ll x, y;
            cin>>x>>y;
            Point p1(x, y, ii);
            
            pts.push_back(p1);
            xSortPts.push_back(p1);
            ySortPts.push_back(p1);

        }
        // TODO -sort xSortPts wrt x,
        PtComparator ptsort; 
        mergeSort(xSortPts, 0, xSortPts.size()-1,ptsort, true );
        // TODO -sort ySortPts wrt y,
        mergeSort(ySortPts, 0, ySortPts.size()-1, ptsort, false);
    }
    void checkInpOrder(PointPair &p1){
        if(p1.a.inpIdx > p1.b.inpIdx){
            swap(p1.a, p1.b);
        }
    }

    PointPair closestPair(ll l , ll r){
        //do slicing on xSortPts
        ll segsz= r- l + 1;

        if(segsz == 2){ //base case, less than or equal to 3 pts
            PointPair res = {xSortPts[l], xSortPts[r], distance(xSortPts[l], xSortPts[r])};
            checkInpOrder(res);
            return res;

        }
        if(segsz == 3){
            PointPair res1 = {xSortPts[l], xSortPts[r], distance(xSortPts[l], xSortPts[r])};
            PointPair res2 = {xSortPts[l+1], xSortPts[r], distance(xSortPts[l+1], xSortPts[r])};
            PointPair res3 = {xSortPts[l], xSortPts[l+1], distance(xSortPts[l], xSortPts[l+1])};

            PointPair res = tiebrk(res1, res2);
            res = tiebrk(res, res3);
            checkInpOrder(res);
            return res;
        }
        ll m = l + (r- l)/2;

        PointPair lefthalf = closestPair(l, m);
        PointPair righthalf = closestPair(m+1, r);

        PointPair minPt = tiebrk(lefthalf, righthalf);
        double delta = minPt.dist;
        //line L will be at mid element 
        Point line = xSortPts[m];
        //find 
        vector<Point> inrange;
        for(ll i = l; i < r; i++){
            Point xPoint = xSortPts[i];  
            if(lineDistance(line, xPoint) < delta){
                inrange.push_back(xPoint);
            }
        }
        PtComparator c2;
        mergeSort(inrange, 0, inrange.size()-1, c2, false);
        //need y sorted points which are in range
        //for each point in inrange, check against next fifteen points
        ll rngsz= inrange.size();
        PointPair acrossBdr= minPt;
        for(ll ii = 0; ii < rngsz; ii++){
            Point p = inrange[ii];
            ll maxCheck = rngsz > ii + 16 ? ii + 16 : rngsz; //TODO - check bug for off by one
            for(int jj = ii +1 ; jj < maxCheck; jj++){
                Point q = inrange[jj];

                PointPair candid= {p, q, distance(p,q)};
                acrossBdr = tiebrk(acrossBdr, candid);
            } 
        }
        checkInpOrder(acrossBdr);
        return acrossBdr; //will return delta points if no smaller dist across Brdr
    }
    
};

int main(){
   
   
    Board b1;
    

    while(true){

        string command;
        cin>>command;
        if (command == "CREATE_2D")
        {
            ll n;
            cin >> n;
            b1.initBoard(n);
            for (ll ii = 0; ii < n; ii++)
            {
                for (ll jj = 0; jj < n; jj++)
                {
                    ll ele;
                    cin >> ele;
                    b1.mat[ii][jj] = ele;
                    b1.flatmat[ii * n + jj] = ele;
                }
            }
        }
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
            Olympics o1;
            o1.populatePts();
            PointPair res = o1.closestPair(0, o1.noPts-1 );
            cout<<res.a.x<<" "<< res.a.y<<" "<< res.b.x<<" "<<res.b.y<<endl;

            
        }
        if(command == "END"){
            break;
        }
    }
    return 0;
}
