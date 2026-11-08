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
Dynarray(const Dynarray& other){
    cap=other.cap;
    len=other.len;
    data= new int [cap];
    for(int i=0;i<len;i++) data[i]=other.data[i];
}
Dynarray(Dynarray&& o) noexcept : data(o.data),len(o.len),cap(o.cap){
    o.len=0;
    o.cap=0;
    o.data=nullptr;
}
Dynarray& operator=(const Dynarray& o){
    if(this!=&o){
        int* newdata=new int[o.cap];
        for(int i=0;i<o.len;i++)
        newdata[i]=o.data[i];
        delete[] data;
        data=newdata;
        cap=o.cap;
        len=o.len;
    }
    return *this;
}
Dynarray& operator=(Dynarray&& o) noexcept {
    if(this!=&o){
        delete [] data;
        cap=o.cap;
        o.cap=0;
        len=o.len;
        o.len=0;
        data=o.data;
        o.data=nullptr;
    }
      return *this;
}
void push_back(int v){
    if(len==cap){
        int Newcap=cap*2;
        int *Newdata= new int [Newcap];
        for(int i=0;i<len;i++){
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
    cout<<endl;
    Dynarray b=a;
    cout<<b.size()<<endl;
    Dynarray m;
    for(int i=0;i<5;i++) m.push_back(i);
    Dynarray n=m;
    Dynarray t=std::move(m);
    n=t;
    t=std::move(n);
    cout<<"n:"<<n.size()<<endl<<"t:"<<t.size()<<endl;
    return 0;
}