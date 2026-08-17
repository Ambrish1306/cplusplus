#include<iostream>
using namespace std;
class Base{
 int a; 
 const int b;//we need Initializer List
 int &c;////we need Initializer List
 int *d;
    public:
    Base(int a, const int b, int &c):a(a),b(b),c(c){
        d = new int(10);
    };
    

    void display() const{
        cout<<"a: "<<a<<endl;
        cout<<"b: "<<b<<endl;
        cout<<"c: "<<c<<endl;
        cout<<"d: "<<*d<<endl;
    }
    ~Base(){
        delete d;
    }
};


int main(){
    int a=10,b=10,c=20;
    int *d;
    Base *bobj= new Base(a,b,c);
    Base *cobj=move(bobj);
    cobj->display();
    delete bobj;
    return 0;
}
//when we need default const
//object instantiation without Arguments 
//Creating Arrays of Objects 
//Usage with STL containers 
//Base Class Initialization in Inheritance
//

class MyClass
{
  public :
    MyClass() {
        cout<<"default const"<<endl;
    }
    void print()
    {
        cout<<"i am class a"<<endl;
    }
}; 

int main() 
{
    
    MyClass ObjArr[10]; //-->it will call 10 times 
    vector<MyClass> myObj(10); //--same like above 

    ObjArr[0].print();
    myObj[0].print();
   
    return 0;
}
