#include <bits/stdc++.h>

#define ll long long int
#define int_ unsigned int

using namespace std;

class student
{
private:
    /* data */
    int id;
    string name;

public:
    student(/* args */);
    student(int id, string name);
    ~student();
    void display();
};
student::student(/* args */){
    cout<<"student constructor"<<endl;
}
student::student(int id, string name) : id(id), name(name)
{
}

student::~student()
{
}

void student::display()
{
    cout << id << " " << name << endl;
    cout << "Hello World";
}

class Monitor: public student{
public:

    Monitor(){
        cout<<"Monitor constructor"<<endl;
    }
    ~Monitor(){
        cout<<"Monitor destructor"<<endl;
    }
};

int main()
{
    ios_base::sync_with_stdio(false); // fastio
    cin.tie(NULL);                    // fastio

    // student s(1, "Ayush");
    Monitor* m = new Monitor();
    // s.display();
    // m->display();
    return 0;
}