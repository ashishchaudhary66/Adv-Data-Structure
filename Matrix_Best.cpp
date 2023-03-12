#include<iostream>
using namespace std;

class Matrix{
private:
    int rows;
    int cols;
    int **arr;
public:
    Matrix(int m,int n){
        rows=m;
        cols=n;
        //arr=new int*[rows];
    }
    void read();
    void print();
    Matrix add(Matrix B);
    Matrix mul(Matrix B);
    float det();
    void inverse();

};


void Matrix::read(){
    arr=new int*[rows];
    cout<<"\nEnter the elements of matrix of Order "<<rows<<"*"<<cols<<" : \n";
    for(int i=0;i<rows;i++){
            arr[i]=new int[cols];
        for(int j=0;j<cols;j++){
            cin>>arr[i][j];
        }
    }
}
void Matrix::print(){
    cout<<"\nThe elements of the matrix are \n";
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
}

int main(){
    cout<<"-------DSA Started------";
    Matrix A(3,2);
    A.read();
    A.print();


/*
    Matrix B(3,2);
    B.read();
    B.print();

    Matrix C(3,2);
    C=A.add(B);
    C.print();

    Matrix B(2,3);
    B.read();
    B.print();


    Matrix C=A.mul(B);
    C.print();
*/
}
