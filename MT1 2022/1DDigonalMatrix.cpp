#include<iostream>
using namespace std;

class Matrix{
    float *a;
    int n;
public:
    Matrix(){
        //nothing
    }
    Matrix(int n){
        this->n=n;
        a=new float[n];
    }
    void read();
    void print();
    Matrix add(Matrix);
    Matrix mul(Matrix);
    float det();
    Matrix inverse();
};

void Matrix::print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                cout<<a[i]<<" ";
            }
            else{
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
}

void Matrix::read(){
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}

Matrix Matrix::add(Matrix m){
    if(n!=m.n){
        cout<<"Invalid Order";
        exit(0);
    }
    Matrix result(n);
    for(int i=0;i<n;i++){
        result.a[i]=a[i]+m.a[i];
    }
    return result;
}

Matrix Matrix::mul(Matrix m){
    if(n!=m.n){
        cout<<"Invalid Order";
        exit(0);
    }
    Matrix result(n);
    for(int i=0;i<n;i++){
        result.a[i]=a[i]*m.a[i];
    }
    return result;
}

float Matrix::det(){
    float d=1;
    for(int i=0;i<n;i++){
        d*=a[i];
    }
    return d;
}

Matrix Matrix :: inverse(){
    if(this->det()==0){
        cout<<"Inverse Does not Exist";
        exit(0);
    }
    Matrix result(n);
    for(int i=0;i<n;i++){
        result.a[i]=1/a[i];
    }
    return result;
}

int main(){
    Matrix a(3);
    Matrix b(3);
    Matrix c;
    cout<<"Enter Diagonal Element A : "<<endl;
    a.read();
    a.print();
    cout<<"Enter Diagonal Element B : "<<endl;

    b.read();
    b.print();

    c=a.add(b);
    cout<<"Addition of Matrix A and B is : "<<endl;
    c.print();

    c=a.mul(b);
    cout<<"Multiplication of Matrix A and B is : "<<endl;
    c.print();

    cout<<"Determinant of Matrix C is : "<<c.det()<<endl;


    cout<<"Inverse of Matrix C is : "<<endl;
    c.inverse().print();
}
