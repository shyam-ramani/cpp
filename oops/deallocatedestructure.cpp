#include<bits/stdc++.h>
using namespace std;
class Teacher{
    public:
       string s;
     Teacher(){
        cout<<"hI is am parents"<<endl;
     }
  ~Teacher(){
      cout<<"Bye1"<<endl;
  }

};
class Student: public Teacher{
    public:
   Student(){
     cout<<"Hi i am child"<<endl;
    }
    ~Student(){
        cout<<"Bye2"<<endl;
    }
};
int main(){
    Student s;

    
   
    
}

