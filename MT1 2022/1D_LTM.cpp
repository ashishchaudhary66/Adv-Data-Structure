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
        a=new float[n*(n+1)/2];
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
            int map=i*(i+1)/2+j;
            if(i<j){
                cout<<0<<" ";
            }
            else{
                cout<<a[map]<<" ";
            }
        }
        cout<<endl;
    }
}

void Matrix::read(){
    int size=n*(n+1)/2;
    for(int i=0;i<size;i++){
        cin>>a[i];
    }
}

Matrix Matrix::add(Matrix m){
    if(n!=m.n){
        cout<<"Addition Failed";
        exit(0);
    }
    Matrix result(n);

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            int map=i*(i+1)/2+j;
            result.a[map]=a[map]+m.a[map];
        }

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


int main(){
    int order;
    cout<<"Enter Order of the Matrix : ";
    cin>>order;
    Matrix a(order);
    Matrix b(order);
    Matrix c;
    cout<<"Enter LTM Element of A : "<<endl;
    a.read();
    a.print();
    cout<<"Enter LTM Element of B : "<<endl;

    b.read();
    b.print();

    c=a.add(b);
    cout<<"Addition of Matrix A and B is : "<<endl;
    c.print();

}
