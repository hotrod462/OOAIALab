#include <bits/stdc++.h>

using namespace std;
struct CurrencySorter{
    void operator()(vector<long long int> &nums){
        quicksort(nums, 0, nums.size() -1);
    }
    long long int partition(vector<long long int> &arr, int l, int r){
        long long int pivot = arr[r];

        long long int i = l -1;
        for(int j = l; j<=r -1; j++){
            if(arr[j]<= pivot){
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i+1], arr[r]);
        return i+1;

    }
    long long int randomPartition(vector<long long int> &arr , int l, int r ){
        //reference - GFG
        srand(time(NULL));
        int random = l + rand() % (r-l);
        swap(arr[random], arr[r]);
        return partition(arr, l, r);
    }
    void quicksort(vector<long long int> &tosort, int l, int r){
        if(l < r){
            long long int partidx = randomPartition(tosort, l, r);

            quicksort(tosort, l, partidx -1);
            quicksort(tosort, partidx +1, r);
        }
    }
};

struct FibGenerator{
    vector<vector<int>> res;
    void matMul(vector<vector<long long int>> &A, vector<vector<long long int>> &B, vector<vector<long long int>>& C){
        int N = 2;
        for(int ii = 0; ii < N; ii++ ){
            for(int jj = 0; jj < N; jj++){
                for(int kk =0 ; kk < N; kk++){
                    C[ii][jj] = A[ii][kk] + B[kk][jj];
                }
            }
        }
    }
    int operator()(int i){

        return fib(i);
    }

    vector<vector<long long int>>matPower(vector<vector<long long int>> &a, long long int n){
        if(n == 1) return a;
        else{
            vector<vector<long long int>> x = matPower(a, n/2);
            vector<vector<long long int>> sqr;
            matMul(x, x, sqr);
            if( n % 2 ==0 ){
                return sqr;
            }
        else {
            matMul(sqr, a, sqr);
            return sqr;
        }
        }
    }
    long long int fib( long long int i){
        vector<vector<long long int>> fibrec {{1, 1}, {1, 0}};
        auto final_mat = matPower(fibrec, i);
        return final_mat[0][0] + final_mat[0][1];
    }
};

class PrimeCalculator{
    public:

    vector<int> primes;
    void findPrimes(int L, int R){


    }
    void printPrimes(){
        for(auto ele: primes){
            cout<<ele<<" "; }
        cout<<endl;
    }

    void printPrimeSum(){
        long long int sum;
        for(auto ele: primes){
            sum += ele;
        }
    }
};

class NumberAnalyzer{
    public:
    long long int x;
    bool hasSqrFactor;
    set<unsigned int> divisor;

    NumberAnalyzer(long long int a):x(a){
        hasSqrFactor = false;
    }
    void findDivisors(){
        for(unsigned int i = 1; i <=(unsigned int)sqrt(x);i++){
            if(x % i == 0){
                if(x %(i*i) == 0) hasSqrFactor = true;
                divisor.insert(i);
                divisor.insert(x/i);
            }
        }
    }

    bool isSquareFree(){
        return hasSqrFactor;
    }
    int countDivisors(){
        return divisor.size();
    }
    
    int sumOfDivisors()
    {
        unsigned int divsum=0;
        for(auto it: divisor){
            divsum += it;
        }
        return divsum;
    }

};


int main(){
    while(true){
        int pick;
        cin>>pick;

        int t;
        cin>>t;
        //for(int ii = 0; ii < t; ii++){
                if(pick == 1){
                    int n;
                    cin>>n;
                    vector<long long int> currency(n);
                    for(int i = 0; i < n; i++){
                        long long int ele;
                        cin>>ele;
                        currency[i] = ele;
                    }
                    CurrencySorter c;
                    c(currency);
                    for(auto ele: currency){
                        cout<<ele<<" ";
                    }
                }

                if (pick == 2)
                {
                    long long int i;
                    cin >> i;
                    FibGenerator f;
                    cout << f(i) << endl;
                }
                if (pick == 3)
                {
                    PrimeCalculator p;
                    p.printPrimes();
                    p.printPrimeSum();
                }
                if(pick ==4){
                    string command;
                    cin>>command;
                    long long int x;
                    cin>>x;
                    
                    NumberAnalyzer numal(x);
                    if(command == "isSqareFree"){
                        numal.isSquareFree();
                    }
                    else if(command == "countDivisors"){
                        numal.countDivisors();
                    }
                    else{
                        numal.sumOfDivisors();
                    }
                }
        
                
            //}
        }
    }
