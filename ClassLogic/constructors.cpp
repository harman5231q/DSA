#include<iostream>
using namespace std;

class Circle{
    int rad;
    public:
    Circle(){

    }
    Circle(int r){
        this->rad=r;
    }
    void area(){
        cout<<"Area is :";
        cout<< (rad*rad)*(3.14)<<endl;;
    }
    void setdata(int r){
        this->rad=r;
    }
    int getdata(){
        return this->rad;
    }
    void perimeter(){
        cout<<"Perimeter is:";
        cout<<2*(3.14)*(rad)<<endl;
    }
    ~Circle(){
        cout<<"Destructor called"<<endl;
    }
};
int main(){
    Circle cir(12);
    cir.perimeter();
    cir.area();
    cout<<cir.getdata()<<endl;
    //Circle *cir1=new Circle(10);
    //cir1->perimeter();
    //cir1->area();
    //delete cir1;

    return 0;
}