#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main(){
    ifstream fin("notes.txt");
    if(!fin){
        cerr<<"打不开文件"<<endl;
        return 1;
    }
    int lines=0;
    int chars=0;
    string line;
    while(getline(fin,line)){
        lines++;
        chars+=line.size();
    }
    cout<<"行数为"<<lines<<endl;
    cout<<"字符数为"<<chars<<endl;
    return 0;
}