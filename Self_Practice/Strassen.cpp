#include <bits/stdc++.h>
#define matrix vector<vector<long long int>> 
#define ll long long int
using namespace std;

class StrassenMul{
    public:
    matrix add(matrix &A, matrix &B){
        ll n = A.size();
        matrix C(n, vector<long long int>(n, 0));

        for(ll ii = 0; ii < n; ++ii){
            for(ll jj = 0; jj < n; ++jj){
                C[ii][jj] =  A[ii][jj] + B[ii][jj];
            }
        }
        return C;
    }
    matrix sub(matrix &A, matrix &B){
        
        ll n = A.size();
        matrix C(n, vector<long long int>(n, 0));

        for(ll ii = 0; ii < n; ++ii){
            for(ll jj = 0; jj < n; ++jj){
                C[ii][jj] =  A[ii][jj] - B[ii][jj];
            }
        }
        return C;
    }
    
    matrix strassen(matrix &A, matrix &B){
        ll n = A.size();

        matrix C(n, vector<long long int>(n, 0));
        if(n == 1){
            C[0][0]= A[0][0] * B[0][0];
            return C;
        }

        ll k = n/2;
        matrix A11(k, vector<long long int>(k, 0));
        matrix A12(k, vector<long long int>(k, 0));
        matrix A21(k, vector<long long int>(k, 0));
        matrix A22(k, vector<long long int>(k, 0));
        matrix B11(k, vector<long long int>(k, 0));
        matrix B12(k, vector<long long int>(k, 0));
        matrix B21(k, vector<long long int>(k, 0));
        matrix B22(k, vector<long long int>(k, 0));
    }
};