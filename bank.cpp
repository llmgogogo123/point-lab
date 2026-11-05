#include<iostream>
using namespace std;
class Bankaccount{
    private:
    double x;
    public:
Bankaccount(double init) :x(init){}
    void add(double amount){
        x+=amount;
    } 
    bool withdraw(double amount){
        x-=amount;
        if(x>=0) return true;
        else{
            x+=amount;
            return false;
    }
}
    double getx(){
        return x;
    }
};
int main(){
    Bankaccount a(100);
    a.add(50);
    cout<<a.getx()<<endl;
    cout<<a.withdraw(40)<<endl;
    cout<<a.withdraw(200)<<endl;
    cout<<a.getx()<<endl;
    return 0;
}