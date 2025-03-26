#include <bits/stdc++.h>
#define ll long long int
#define ldob long double
using namespace std;

class Complex{
    public: 
    ll real; //use long long int for input, long double for roots of unity
    ll img;
    Complex(): real(0), img(0){}
    Complex(ll rpart,ll impart): real(rpart), img(impart){}
    Complex operator+(const Complex &b){
        Complex c1(0, 0);
        c1.real = real + b.real;
        c1.img = img + b.img;
        return c1;

    }

    Complex operator *(const Complex &b){

        return Complex(real*b.real - img*b.img, img*b.real + real*b.img);
    }
    bool operator ==(const Complex &b){
        return (img == b.img) && (real == b.real);
    }
    bool operator !=(const Complex &b){
        return !((img == b.img) && (real == b.real));
    }
};
template<typename T>
class PolyMul;

template <typename T>
class Polynomial{
    public:
    vector<T> coeff;
    ll deg; // pass this in through constructor

    Polynomial(ll n_in): deg(n_in){
        coeff.resize(deg);
        for(ll ii =0 ; ii < deg; ++ii){
            if constexpr(is_same<T, Complex>::value ){
                ll r, i;
                cin>>r>>i;
                coeff[ii] = Complex(r, i);
            }
            else{
                cin>>coeff[ii];//check if this works fine for float as well
            }
        }
    }
    Polynomial( vector<T> in_coeff): coeff(in_coeff){deg = coeff.size() -1;}//check if coeff.size



    Polynomial<T> operator*(Polynomial<T> &toMul){
        PolyMul<T> P;
        Polynomial<T> res = P(*this, toMul);
        vector<T> &res_coeff = res.coeff;
        ll cfsz = res_coeff.size() -1;
        
        for(ll ii = cfsz; ii >=0; --ii){
            if constexpr(is_same<T, Complex>::value){
                if(res_coeff[ii] != Complex(0,0)) break;
            }
            else{
                if(res_coeff[ii] != 0) break;
            }
            cfsz--;
        }
        res.coeff.resize(cfsz +1);
        res.deg = cfsz +1 ; //check this calc
        return res;
    }

    void print(){
        for(auto itr: coeff){
            if constexpr(is_same<T, Complex>::value){
                cout<< itr.real <<" " << itr.img<<" ";
            }
            else{
                cout<< itr<<" ";
            }
        }
        cout<<endl;
    }
};

template <typename T>
class PolyMul{
    public:
    
    Polynomial<T> operator()(Polynomial<T> &a, Polynomial<T> &b){

        Polynomial<T> &smol = a.deg < b.deg? a:b ;
        Polynomial<T> &big = a.deg <= b.deg ? b: a;
        while(smol.coeff.size() < big.coeff.size()){
            if constexpr(is_same<T, Complex>::value) smol.coeff.push_back(Complex(0, 0));
            else smol.coeff.push_back(0);
        }
        smol.deg = smol.coeff.size();
        vector<T> &poly1 = smol.coeff;
        vector<T> &poly2 = b.coeff;
        return Polynomial(karatsuba(poly1, poly2, 0, poly1.size()-1 ));

    }

    vector<T> karatsuba(vector<T> &p1, vector<T> &p2, ll l, ll h){ //pad smaller poly with zeros
        if(l < h){
            ll m = l + (h- l)/2;
            ll n = h - l +1;
            vector<T>M1((h-l)/2);
            vector<T>M2((ll) ceil((h-l)/2));

            for(ll ii = 0; ii < M1.size(); ++ii){
                M1[ii] = p1[l+ ii] + p2[m+ ii];
                M2[ii] = p1[m+ ii] + p2[m + ii];
            }
            if (M2.size() > M1.size())
            {
                M2[M2.size() - 1] = p1[p1.size() - 1] + p2[p2.size() - 1];
                if constexpr(is_same<T, Complex>::value) M1.push_back(Complex(0, 0));
                else M1.push_back(0);
            }

            vector<T> S1 = karatsuba(M1, M2, 0, M2.size() -1);
            vector<T> S2 = karatsuba(p1, p2, l, m);
            vector<T> S3 = karatsuba(p1, p2, m+1, h);
            vector<T> res; 
            if constexpr(is_same<T, Complex>::value) {
                res = vector<T>(2*n, Complex(0, 0));  
            } else {
                res = vector<T>(2*n, 0);  
            }
            for(ll ii = 0; ii < 2 * n; ++ii){
                if(ii < n/2){
                    res[ii] = (S2[ii]); //safe as S2 is atleast of length n;
                }
                else if( ii > n/2 && ii < n){
                    res[ii] = (S2[ii] + S1[ii - n/2]);
                }
                else{
                    res[ii] = (S1[ii - n/2] + S3[ii - n]);
                }

            }
            return res;

        }
        else if(l == h){
            vector<T> res = {p1[l] * p2[l]};
            return res;

        }
        else{
            vector<T> help; //this case might fail
            return help;
        }
    }


};
template <typename T>
class PolyEval{
    public:
        Polynomial<T> operator()(Polynomial<T> toEval, ll evalOn){


        }
    
};
template <typename T>
class PolyDiff{
    public:
        Polynomial<T> operator()(Polynomial<T> toDiff){

        }
    
};

string operator*(string s ,ll x){
    string res = "";
    for(ll ii = 0; ii < x; ++ii){
        res+= s;
    } 
    return res;
}

int main(){
    ll q;
    cin>>q;
    while(q--){
        int qno;
        cin>>qno;

        if(qno == 1){
            string dtype;
            cin>>dtype;
            if(dtype == "integer"){
                ll deg1, deg2;
                    cin>>deg1;
                    Polynomial<ll> p1(deg1);
                    cin>>deg2;
                    Polynomial<ll> p2(deg2);

                    Polynomial<ll> p3 = p1 * p2;
                    p3.print();
                    
            }
            if(dtype == "float"){
                ll deg1, deg2;
                    cin>>deg1;
                    Polynomial<ldob> p1(deg1);
                    cin>>deg2;
                    Polynomial<ldob> p2(deg2);

                    Polynomial<ldob> p3 = p1 * p2;
                    p3.print();
                    
            }
            if(dtype == "complex"){
                ll deg1, deg2;
                    cin>>deg1;
                    Polynomial<Complex> p1(deg1);
                    cin>>deg2;
                    Polynomial<Complex> p2(deg2);

                    Polynomial<Complex> p3 = p1 * p2;
                    p3.print();
                    
            }
        }
    }

}