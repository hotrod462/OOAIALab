#include <vector>
#include <bits/stdc++.h>
#define ll long long int 
using namespace std;

class Employee{
    public:
        ll id;
    
        ll age, exp, boss_id;

        Employee(ll in_id, ll in_age, ll in_exp, ll in_boss):id(in_id), age(in_age), exp(in_exp), boss_id(in_boss){}
        Employee():id(0), age(0), exp(0), boss_id(0){}
        
};
class BIdComp{
    public:
    bool operator()(const Employee &e1, const Employee &e2){
        if(e1.boss_id <= e2.boss_id) return true;
        else return false;
    }
};
class ChildComp{
    public:
    ChildComp(Employee in_boss): boss(in_boss){}
    bool operator()(const Employee &e1, const Employee &e2){
        if(e1.boss_id == boss.id) return true;
        else return false;
    }
    Employee boss;
};

class Company{
    public:
    Employee founder;
    unordered_map<ll, vector<ll>> adjList;
    unordered_map<ll, Employee> employeeList;
    

    void addEmp(Employee e){
        if(e.id == e.boss_id){
            founder = e;
            employeeList[e.id]= e;
            return;
        }
        employeeList[e.id]= e;
        adjList[e.boss_id].push_back(e.id);
    }

    ll bfsSub(ll empId){
        ll sum=0;
        ll totalsubs= 0;
        queue<ll> q;
        q.push(empId);
        totalsubs++;
       

        while(!q.empty()){
            ll front = q.front();
            Employee emp = employeeList.find(front)->second;
            sum += emp.exp;
            
            
            vector<ll> nbrs;
            if(adjList.find(front) != adjList.end()) nbrs = adjList.find(front)->second;
            for(auto nbr: nbrs){
                q.push(nbr);
                totalsubs++;
                } 

            q.pop();


        }
        ll avg=0;
        if(totalsubs > 0) avg = sum/totalsubs;
        return avg;

    }
    ll domBFS(bool isCase1){
        ll undom=0;
        ll maxExpOneUp= isCase1 ? founder.exp: founder.age;
        ll maxExpCurrLvl = isCase1 ? founder.exp: founder.age;
        queue<ll> q;

        q.push(founder.id);
        ll inCurrLvl= 1;
        ll inNextLvl = 0;

        while(!q.empty()){
            while(inCurrLvl >0){
                ll front = q.front();
                q.pop();
                inCurrLvl--;
                Employee e = employeeList.find(front)->second;
                ll eCaseval= isCase1 ? e.exp: e.age;
                if(eCaseval >= maxExpOneUp){//TODO- check this for >
                    undom++;
                    maxExpCurrLvl = (ll) max(maxExpCurrLvl, eCaseval);
                }
                //push all nbrs into q;
                vector<ll> nbrs;
                if(adjList.find(front) != adjList.end()) nbrs = adjList.find(front)->second;
                for(auto nbr: nbrs){
                    q.push(nbr);
                    inNextLvl++;
                    } 
                
            }
            maxExpOneUp= maxExpCurrLvl;
            inCurrLvl = inNextLvl;
            inNextLvl=0;
        }
        return undom;
    }
    
   


};

int main() {
      ll n;
      cin >> n;
    Company c1;
  
      for(ll i=0; i<n; i++) {
        ll id, age, exp, boss_id;
          cin >> id >> age >> exp >> boss_id; // take input here
        Employee e(id, age, exp, boss_id);
        c1.addEmp(e);
        
        
    }
  
      ll q;
      cin >> q;
  
      for(ll i=0; i<q; i++) {
        ll queryType;
          cin >> queryType;
        if (queryType == 1){
              // Solve query 1
            ll critnum;
            cin>>critnum;
            if(critnum == 1){
                cout<<c1.domBFS(true)<<endl;
            }
            else if(critnum == 2){
                cout<<c1.domBFS(false)<<endl;
            }
            else if(critnum ==3 ){
                ll empId;
                ll k;
                cin>>empId>>k;
                cout<<endl;
            }
            
        }
          else if (queryType == 2){
             ll empId;
            cin>>empId;
            cout<<c1.bfsSub(empId)<<endl;
        }
          else {
            // Solve query 3
            ll empid, k;
            cin>>empid,k;
            cout<<-1<<endl;
        }
    }
    return 0;
}