#include<iostream>
using namespace std;

class Array{
private:
    int *a,length,size;
public:
    Array(int n){
        a=new int[n];
        size=0;
        length=n;

    }
    void display();
    friend void store(Array &arr,int n);
};

int main()
{

    Array num(8);
    store(num,6);
    num.display();
}

void Array:: display()
{

    cout<<"[";
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<",";
    }
    cout<<"\b]";
}
void store(Array &arr,int n)
{
    if(n>arr.length){
        cout<<"Index Out of Bound---";
        exit(0);
    }
    int i=0,count=1;
    for(i=0;i<n/2;i++){
        arr.a[i]=count;
        count+=2;
        arr.size++;
    }
    count=2;
    for(i;i<n;i++)
    {
        arr.a[i]=count;
        count+=2;
        arr.size++;
    }
}
