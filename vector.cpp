#include<iostream>
using namespace std;
class Dynarray{
private:
int *data;
int len;
int cap;
public:
Dynarray(){
    len=0;
    cap=4;
   data= new int[cap];
}
~Dynarray(){
    delete []data;
}
void push_back(int v){
    if(len==cap){
        int Newcap=cap*2;
        int *Newdata= new int [Newcap];
        for(int i=0;i<10;i++){
            Newdata[i]=data[i];
        }
        delete [] data;
        data=Newdata;
        cap=Newcap;
    }
    data[len]=v;
    len++;
}
int size() const{
    return len;
}
int capitity() const{
    return cap;
}
int at(int i) const{
    return data[i];
}
};
int main(){
    Dynarray a;
    for(int i=0;i<10;i++) a.push_back(i);
    cout<<"size="<<a.size()<<endl<<"cap="<<a.capitity()<<endl;
    for(int i=0;i<10;i++) cout<<a.at(i)<<' '; 
    return 0;
}