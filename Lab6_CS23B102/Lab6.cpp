#include <bits/stdc++.h>

using namespace std;
struct CurrencySorter{
    void operator()(vector<int> &nums){
        quicksort(nums, 0, nums.size() -1);
    }
    void quicksort(vector<int> &tosort, int l, int r){
        if( l == r) return;
        int i =l;
        int j =l;
        
        int pivot = tosort[r-1]; //last element pivot
        while(j< r-1){
            if(tosort[j] > pivot) j++;
            else {
                swap(tosort[i], tosort[j]);
                i++;
                j++;
            }
        }
        swap(tosort[i], tosort[r-1]);// put pivot in right place
        quicksort(tosort, l, i-1 );
        quicksort(tosort, i+1, r);
    }
};

struct FibGenerator{
    int operator()(int i){
        return fib(i);
    }

    int fib(int i){
        
    }
};

class PrimeCalculator{
    public:

    vector<int> primes;
    void findPrimes(int L, int R){


    }
    void printPrimes();

    void printPrimeSum(); 
};

class NumberAnalyzer{
    public:
    bool hasSqrFactor;
    set<unsigned int> divisor;

    NumberAnalyzer(){
        hasSqrFactor = false;
    }
    void findDivisors(unsigned int n){
        for(unsigned int i = 1; i <=(unsigned int)sqrt(n);i++){
            if(n % i == 0){
                if(n %(i*i) == 0) hasSqrFactor = true;
                divisor.insert(i);
                divisor.insert(n/i);
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

