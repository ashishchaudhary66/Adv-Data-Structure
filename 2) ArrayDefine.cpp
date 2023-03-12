#include<iostream>
using namespace std;

class Array{
private:
    int *a;
    int length;
    int size;
public:
    Array(int n){
        a=new int[n];
        length=n;
        size=0;
    }

    int getsize();
    void insert(int x,int index);
    void display();
    void del(int index);
};


//Method Definition

int Array :: getsize(){
    return size;
}
void Array ::display(){

    cout<<"[";
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<",";
    }
    cout<<"\b]"<<endl;
}

void Array::insert(int x,int index){
    if(index>size || index<0){
        cout<<"!!! cannot be inserted..."<<endl;
        return;
    }
    if(length==size){
        cout<<"Array is full...";
        exit(0);
    }

    for(int i=size-1;i>=index;i--){

        a[i+1]=a[i];
    }
    a[index]=x;
    size++;
    cout<<x<<" inserted at index "<<index<<endl;
}

void Array ::del(int index){
    if(index>=size && index<0){
        cout<<"Failed...Index Not Found";
        return;
    }
    for(int i=index;i<size;i++){
        a[i]=a[i+1];
    }
    size--;
    cout<<"Element at index "<<index<<" deleted..."<<endl;
}

//User Defined Function

void storeDoubleEven(Array &arr,int n){    //1,2,2,3,4,4,5,6,6...
    for(int i=1;i<=n;i++){
        if(i%2==1){
            arr.insert(i,arr.getsize());
        }
        else{
            arr.insert(i,arr.getsize());
            arr.insert(i,arr.getsize());
        }
    }
}

void delDuplicatesMinMovement(Array &arr){
    int end=arr.getsize()-1;
    for(int i=end;i>=0;i=i-3){
        arr.del(i);
    }
}
void delDuplicatesMaxMovement(Array &arr){

    for(int i=1;i<arr.getsize();i=i+2){
        arr.del(i);
    }
}

void storeDoubleOdd(Array &arr,int n){    //1,1,2,3,3,4,5,5,6,7,7...
    for(int i=1;i<=n;i++){
        if(i%2==0){
            arr.insert(i,arr.getsize());
        }
        else{
            arr.insert(i,arr.getsize());
            arr.insert(i,arr.getsize());
        }
    }
}

void delDuplicatesMinMovementOdd(Array &arr){
    int end=arr.getsize()-1;
    for(int i=end;i>=0;i=i-3){
        arr.del(i);
    }
}
void delDuplicatesMaxMovementOdd(Array &arr){

    for(int i=0;i<arr.getsize();i=i+2){
        arr.del(i);
    }
}


//The Main Function...

int main(){
/*
    Array arr(5);

    cout<<"Size : ";
    arr.getsize();
    arr.insert(5,0);
    arr.insert(4,0);
    arr.insert(10,1);
    arr.insert(12,3);
    cout<<"Elements are : ";
    arr.display();

    arr.del(2);
    cout<<"Elements are : ";
    arr.display();
*/

/*
    int n;
    cout<<"Enter Even Number : ";
    cin>>n;
    Array arr(3*n/2);

    storeDoubleEven(arr,n);
    cout<<"Element are : ";
    arr.display();

    delDuplicatesMinMovement(arr);
    cout<<"Element are : ";
    arr.display();

    delDuplicatesMinMovement(arr);
    cout<<"Element are : ";
    arr.display();
*/

    int n;
    cout<<"Enter Odd Number : ";
    cin>>n;
    Array arrOdd((3*n+1)/2);

    storeDoubleOdd(arrOdd,n);
    cout<<"Element are : ";
    arrOdd.display();
/*
    delDuplicatesMinMovementOdd(arrOdd);
    cout<<"Element are : ";
    arrOdd.display();
*/
    delDuplicatesMaxMovementOdd(arrOdd);
    cout<<"Element are : ";
    arrOdd.display();

}

