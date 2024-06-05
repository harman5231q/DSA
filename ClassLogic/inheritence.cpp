#include<iostream>
using namespace std;
class human{
    public:
    int height;
    int weight;
    int name;
    void speak(){
        cout<<"Human speaking"<<endl;
    }

};
class Male : public human{
    string gender ="male";
    public:
    void getgender(){
        cout<<"Gender of male is: "<<this->gender<<endl;
    }
    
};
class Female : public human{
    string gender ="female";
    public:
    void getgender(){
        cout<<"Gender of female is: "<<this->gender<<endl;
    }
    
};
int main(){
    Male m;
    m.getgender();
    m.speak();
    Female f;
    f.getgender();
    f.speak();
    return 0;
}