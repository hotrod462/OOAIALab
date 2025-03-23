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


        for(ll ii = 0; ii < k ; ii++){
            for(ll jj = 0; jj < k ; ++jj){
                A11[ii][jj]= A[ii][jj];
                B11[ii][jj]= B[ii][jj];
                A12[ii][jj]= A[ii][jj + k];
                B12[ii][jj]= B[ii][jj+k];
                A21[ii][jj]= A[ii+ k][jj];
                B21[ii][jj]= B[ii + k][jj];
                A22[ii][jj]= A[ii +k ][jj + k];
                B22[ii][jj]= B[ii +k][jj +k ];
            }
            }
        

        matrix M1A = add(A11, A22);
        matrix M1B = add(B11, B12);
        matrix M1 = strassen(M1A, M1B);

        matrix M2A = add(A12, A22);
        matrix M2B = add(B21, B22);
        matrix M2 = strassen(M2A, M2B);

        matrix M3A = sub(A11, A22);
        matrix M3B = add(B11, B22);
        matrix M3 = strassen(M3A, M3B);

        matrix M4B = sub(B12, B22);
        matrix M4 = strassen(A11, M4B);

        matrix M5A = add(A21, A22);
        matrix M5 = strassen(M5A, B11);

        matrix M6A = add(A11, A12);
        matrix M6 = strassen(M6A, B22);

        matrix M7B = sub(B21, B11);
        matrix M7 = strassen(A22, M7B);

        matrix C1A = add(M2, M3);
        matrix C1B = add(M6, M7);
        matrix C11 = sub(C1A, C1B);

        matrix C12 = add(M4, M6);
        matrix C21 = add(M5, M7);

        matrix C22A = sub(M1, M3);
        matrix C22B = add(M4, M5);
        matrix C22 = sub(C22A, C22B);

        matrix res(n, vector<long long int>(n, 0 ));
        for(ll ii = 0; ii < k ; ++ii){
            for(ll jj =0; jj < k; ++jj){
                res[ii][jj]= C11[ii][jj];
                res[ii+k][jj]= C21[ii][jj];
                res[ii][jj+k]= C12[ii][jj];
                res[ii+k][jj+k]= C22[ii][jj];
            }
        }
        return res;
            }
};

int main(){
    matrix A= {{1,2, 3,4}, {2, 3,4, 5}, {3,4,5,6}, {4,5,6,7}};
    StrassenMul s1;

    matrix B = s1.strassen(A, A);

    for(ll ii= 0; ii < A.size(); ++ii){
        for(ll jj = 0 ; jj< A.size(); ++jj){
            cout<<B[ii][jj]<<" ";
        }
        cout<<endl;
    }
    return 0;

}