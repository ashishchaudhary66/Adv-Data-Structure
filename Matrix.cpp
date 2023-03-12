#include<iostream>
using namespace std;

class Matrix{
    int row;
    int col;
    int *a;

public :
    Matrix(int m,int n){
        row=m;
        col=n;
        a=new int[m*n];
    }
    void read();
    void print();
    Matrix add(Matrix B);
    Matrix mul(Matrix B);
    void det();
    void inverse();
    void utm();

};


void Matrix::read(){
    cout<<"\nEnter the elements of matrix of Order "<<row<<"*"<<col<<" : \n";
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>a[col*i+j];
        }
    }
}
void Matrix::print(){
    cout<<"\nThe elements of the matrix are \n";
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<a[col*i+j]<<"  ";
        }
        cout<<endl;
    }
}

Matrix Matrix::add(Matrix B){
    Matrix C(row,col);
    try{
        if(row!=B.row || col!=B.col){
            throw;
        }
        else{
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    C.a[col*i+j]=a[col*i+j]+B.a[col*i+j];
                }
            }
        }
    }
    catch(...){
        cout<<"---Failed---as order must be equal...";
    }

    return C;
}

Matrix Matrix::mul(Matrix B){
    if(col!=B.row){
        cout<<"---Failed---as A(Row) must be equal B(Column)";
    }

    Matrix C(row,B.col);
    for(int i=0;i<row;i++){
        for(int j=0;j<B.col;j++){
            int sum=0;
            for(int k=0;k<col;k++){
                sum=sum+a[col*i+k] * B.a[B.col*k+j];
            }
            C.a[B.col*i+j]=sum;
        }
    }

    return C;
}

void Matrix::utm()
{
    Matrix B(row,col);
    for(int i=0;i<col;i++)
    {
        B.a[i]=a[i];
    }
    for(int i=1;i<row;i++){
        int pre=B.a[(i-1)*col+(i-1)];
        int next=a[i*col+i];
        for(int j=0;i<col;j++){
            B.a[i*col+j]=a[i*col+j]*pre-B.a[(i-1)*col+j]*next;
        }
    }
    B.print();
}

int main(){
    cout<<"-------DSA Started------";
    Matrix A(2,2);
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
    A.utm();

}

