#include <bits/stdc++.h>

using namespace std;
class QNS{
    public:
        QNS(int pwr, int dur, int en, int ht):
        pwrLvl(pwr), dura(dur), enStge(en), heatLvl(ht), isShutDown(false), isDestroyed(false) {}

        QNS(const QNS &oldSuit){
            pwrLvl= oldSuit.pwrLvl;
            dura = oldSuit.dura;
            enStge= oldSuit.enStge;
            heatLvl= oldSuit.heatLvl;
            isShutDown = false;
            isDestroyed= false;
            
        }
        
        QNS(){
            pwrLvl = 1000;
            dura= 500;
            enStge= 300;
            heatLvl= 0;
            isShutDown = false;
            isDestroyed = false;
        }
    void operator +(QNS &suit){
        pwrLvl += suit.getEnergyStorage();
        if(pwrLvl > 5000){
            pwrLvl = 5000;
        }
        dura += suit.getDurability();
      //TODO - check for revitaliving suit
        enStge += suit.getPowerLevel();
    }
    void operator -(int damage){
        dura -= damage;
        if(dura <= 0){
            isDestroyed = true;
        }
        enStge += damage;
        heatLvl += damage;
        if(heatLvl> 500){
            isShutDown = true;
        }
    }
    void operator *(int factor){
        pwrLvl += (pwrLvl*factor)/100;
        if(pwrLvl > 5000) pwrLvl = 5000;
        enStge += 5*factor;
        heatLvl += factor;
        if(heatLvl > 500){
            isShutDown = true;
        }
    }
    void operator / (int heatdrop){
        dura += heatdrop;// TODO- add guard here for destructed suit not reviving here?
        heatLvl -= heatdrop;
        if(heatLvl <= 500){isShutDown = false;}//suit powers up again
        if(heatLvl < 0){
            heatLvl = 0;
        }
    }

    bool operator == (QNS otherSuit){
        if(pwrLvl == otherSuit.pwrLvl &&
        dura == otherSuit.getDurability()){
            return true;
        }
        else return false;
    }
    bool operator < (QNS otherSuit){
        return (pwrLvl + dura) < (otherSuit.getPowerLevel() + otherSuit.getDurability());
    }
    //methods
    void boostPower(int factor){
        (*this)*factor;
    }
    void boostPower(QNS otherSuit){
        (*this)+otherSuit;
    }

    int getPowerLevel(){
        return pwrLvl;
    }

    int getDurability(){
        return dura;
    }
    int getEnergyStorage(){
        return enStge;
    }
    int getHeatLevel(){
        return heatLvl;
    }
    bool isOverheat(){
        return isShutDown;
    }
    bool isDestructed(){
        return isDestroyed;
    }

    void setPoweLevel(int inPowerLvl){
        pwrLvl = inPowerLvl;
    }
    void setEngStg(int inEngStage){
       enStge= inEngStage;
    }
    void setDurability(int inDura){
        dura= inDura;
    }
    void setHeatLevel(int inHeatLevel){
        heatLvl = inHeatLevel;
    }

    

private:
    int pwrLvl;
    int dura;
    int enStge;
    int heatLvl;
    bool isShutDown;
    bool isDestroyed;
};

class Avenger{
    public:
        Avenger(string avName, QNS avSuit, int strength): name(avName), suit(avSuit), attackStrength(strength){}
        QNS *operator ->(){
            return &suit;
        }
        void attack(Avenger &enemy){
            if (canAttack())
            { // A is not shutdown or overheated
                enemy.getSuit()- attackStrength;
            }
        }
        void upgradeSuit(QNS &othersuit){
            if(isAlive()){
                (this->suit) + othersuit;
                }
        }
        void repair(int x){
            this->suit / x;
        }
        bool canAttack(){
            return !suit.isDestructed() && !suit.isOverheat();
        }
        bool isAlive(){
            return !suit.isDestructed();
        }
        void printStatus(){
            cout<<name<<" "<< (*this)->getPowerLevel() <<" "<<(*this)->getDurability()<<" " << (*this)->getEnergyStorage()<<" "<<(*this)->getHeatLevel()<<endl;
        }
        string getName(){
            return name;
        }
        QNS &getSuit(){
            return suit;
        }

    private:
        string name;
        QNS suit;
        int attackStrength;
};

class Battle{
    public:
        void initBattle(){

            int k, n, m;
            cin >> k >> n >> m;
            for (int i = 0; i < k; i++)
            {
                int p, d, e, h;
                cin >> p >> d >> e >> h;

                avalSuits.push(QNS(min(p,5000), d, e, max(0,h)));
            }
            for(int i =0; i < n +m; i++){
                string name;
                int strength;
                cin>>name>>strength;

                if (!avalSuits.empty())
                {
                    if (i < n)
                    {
                        Avenger av(name, avalSuits.front(), strength);
                        heroes.push_back(av);
                        players.insert(make_pair(name, av)); //make a pair of name and avenger object to avoid default constructor for avenger
                    }
                    else
                    {
                        Avenger av(name, avalSuits.front(), strength);
                        enemies.push_back(av);
                        players.insert(make_pair(name, av));
                    }
                    avalSuits.pop();
                }
                else{
                    cout<<(name+" is out of fight\n");
                }
            }
        }
        void startBattle(){
            while(true){
                string command;
                string avng1;
                cin>>command;
                if(command =="BattleBegin")
                {
                    continue;
                }
                else if(command == "Attack"){
                    cin>>avng1;
                    string avng2;
                    cin>>avng2;
                    Avenger &av1 = (players.find(avng1)->second);
                    Avenger &av2 = (players.find(avng2)->second);

                    if(av1.canAttack() && av2.isAlive()){
                        av1.attack(av2);  
                        battleLog.push_back(avng1+" attacks "+avng2+"\n");   

                        string logMessage;
                        if(av2->isDestructed() || av2->isOverheat()){

                        
                        if(av2->isDestructed()){
                            logMessage = avng2 + " suit destroyed\n";
                            battleLog.push_back(logMessage);
                            }
                        else if(av2->isOverheat()){ //TODO - check if this is correct
                            logMessage = avng2 + " suit overheated\n";
                            battleLog.push_back(logMessage);
                        }
                    }                     
                    
                    }
                    
                    
                        
                        
                    
                }
                
                else if(command == "Repair"){
                    cin>>avng1;
                    int x;
                    cin>>x;
                    Avenger &av = (players.find(avng1)->second);
                    if( !av.isAlive() ) continue; //sanity check

                    if(av.isAlive()){ 
                        av.repair(x);
                        battleLog.push_back(avng1+" repaired\n");
                        }
                }
                else if(command == "BoostPowerByFactor"){
                    cin>>avng1;
                    int y;
                    cin>>y;
                    Avenger &av = (players.find(avng1)->second);
                    if( !av.isAlive() ) continue; //sanity check

                    av->boostPower(y);
                    battleLog.push_back(avng1+" boosted\n");
                    if(av->isOverheat()) battleLog.push_back(avng1+" suit overheated\n"); 
                }
                else if(command == "BoostPower"){
                    
                    cin>>avng1;
                    int p, d, e,h;
                    cin>>p>>d>>e>>h;
                    Avenger &av = (players.find(avng1)->second);
                    if( !av.isAlive() ) continue; //sanity check

                    av->boostPower(QNS(p,d,e,h));
                    battleLog.push_back(avng1+" boosted\n");
                    if(av->isOverheat()) battleLog.push_back(avng1+" suit overheated\n"); 
                }
                else if(command == "AvengerStatus"){

                    cin>>avng1;
                    Avenger &av = (players.find(avng1)->second);
                    av.printStatus();
                }
                else if(command == "Upgrade"){
                    
                    cin>>avng1;
                    Avenger &av = (players.find(avng1)->second);
                    if( !av.isAlive() ) continue; //sanity check
                    if(!avalSuits.empty()){
                        QNS otherSuit = avalSuits.front();
                        avalSuits.pop();
                        av.upgradeSuit(otherSuit);
                        battleLog.push_back(avng1+" upgraded\n");
                    }
                    else{
                        battleLog.push_back(avng1+ " upgrade Fail\n");
                    }

                }
                else if(command == "PrintBattleLog"){
                    printBattleLog();
                }
                else if(command == "BattleStatus"){
                    int battleResult = Result();
                    if(battleResult== 1){
                        cout<<"heroes are winning"<<endl;
                    }
                    else if(battleResult == 0){
                        cout<<"tie"<<endl;
                    }
                    else if(battleResult == -1){
                        cout<<"enemies are winning"<<endl;
                    }
                }
                else if(command == "End"){
                    break;
                }

            }

        }
        void printBattleLog(){
            for(auto ele: battleLog){
                cout<<ele;
            }
        }
        int Result(){
            int herosum = 0;
            int enemysum =0; 
            for(auto av: heroes){
                Avenger avng = players.find(av.getName())->second;
                if(!avng->isDestructed()){
                    herosum += avng->getDurability()+ avng->getPowerLevel();
                }
            }
            for(auto av: enemies){
                Avenger avng = players.find(av.getName())->second;
                if(!avng->isDestructed()){
                    enemysum += avng->getDurability()+ avng->getPowerLevel();
                }
            }

            int result = herosum - enemysum;
            if(result > 0){
                return 1;
            }
            else if(result < 0){
                return -1;
            }
            else return 0;
        }

        queue<QNS> avalSuits;
    
    private:
        vector<Avenger> heroes;
        vector<Avenger> enemies;
        map<string, Avenger> players;
        vector<string> battleLog;



};

int main(){
    Battle B;
    B.initBattle();
    B.startBattle();
    return 0;
}