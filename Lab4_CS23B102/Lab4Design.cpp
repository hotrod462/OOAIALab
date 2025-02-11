#include <bits/stdc++.h>

using namespace std;
class QNS{
    public:
        QNS(int pwr, int dur, int en, int ht):
        pwrLvl(pwr), dura(dur), enStge(en), heatLvl(ht) {}

        QNS(const QNS &oldSuit){
            pwrLvl= oldSuit.pwrLvl;
            dura = oldSuit.dura;
            enStge= oldSuit.enStge;
            heatLvl= oldSuit.heatLvl;

            
        }
        
        QNS(){
            pwrLvl = 1000;
            dura= 500;
            enStge= 300;
            heatLvl= 0;
        }
    void operator +(QNS suit){
        pwrLvl += suit.getEnergyStorage();
        if(pwrLvl > 5000){
            pwrLvl = 5000;
        }
        dura += suit.getDurability();
        enStge += suit.getPowerLevel();
    }
    void operator -(int damage){
        dura -= damage;
        if(dura <= 0){
            //TODO - suit destroyed
        }
        enStge += damage;
        heatLvl += damage;
        if(heatLvl> 500){
            //TODO - suit shuts down
        }
    }
    void operator *(int factor){
        pwrLvl += (pwrLvl*factor)/100;
        if(pwrLvl > 5000) pwrLvl = 5000;
        enStge += 5*factor;
        heatLvl += factor;
        if(heatLvl > 500){
            //TODO - suit shuts down;
        }
    }
    void operator / (int heatdrop){
        dura += heatdrop;
        heatLvl -= heatdrop;
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
    void boostPower(int factor);
    void boostPower(QNS otherSuit);

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
};

class Avenger{
    public:
        Avenger(string avName, QNS avSuit, int strength);
        void attack(Avenger &enemy);
        void upgradeSuit();
        void repair(int x);
        void printStatus(){
            
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
                avalSuits.push(QNS(p, d, e, h));
            }
        }
        void startBattle(){

        }
        void printBattleLog();
        int Result();

        queue<QNS> avalSuits;
    
    private:
        vector<Avenger> heroes;
        vector<Avenger> enemies;
        vector<string> battleLog;



};