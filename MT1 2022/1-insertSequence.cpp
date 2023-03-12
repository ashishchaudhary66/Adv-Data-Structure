#include<iostream>
using namespace std;
class Array{
    int *a;
    int length;
    int size;
public :
    Array(int k){
        a=new int[k];
        length=k;
        size=0;
    }
    int insert(int x,int index){
        int noOfMovement=0;
        if(size==length){
            cout<<"Array is full "<<endl;
            exit(0);
        }
        if(index<0 || index>size){
            cout<<"Invalid Index : "<<index<<endl;
            return 0;
        }
        for(int i=size;i>index;i--){
            noOfMovement++;
            a[i]=a[i-1];
        }
        a[index]=x;
        size++;
        return noOfMovement;
    }
    void display(){
        cout<<"[";
        for(int i=0;i<size;i++){
            cout<<a[i]<<",";
        }
        cout<<"\b]"<<endl;
    }
    friend int insertTermsOfSeries(Array &a, int n);
};

int insertTermsOfSeries(Array &a, int n){
    int x=2;
    int index=0;
    int movement=0;
    for(int i=0;i<n/2;i++){
        movement+=a.insert(x,index++);
        movement+=a.insert(x,index++);
        x+=2;
    }
    index=n-2;
    x=n-1;
    for(int i=0;i<n/2;i++){
        movement+=a.insert(x,index);
        index-=2;
        x-=2;
    }
    return movement;
}

int main(){

    int n=10;
    int movement;
    Array arr(3*n/2);

    movement=insertTermsOfSeries(arr,n);
    arr.display();
    cout<<"No of movement is : "<<movement;

}
