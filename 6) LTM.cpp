#include<iostream>
using namespace std;

void read(int **arr,int n){
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++){
            if(i<j){
                arr[i][j]=0;
            }
            else{
                cin>>arr[i][j];
            }
        }
    }
}

void print(int **arr,int n){
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int **array;
    int n;
    cout<<"Enter Order of the Lower Triangular Matrix : ";
    cin>>n;

    array=new int*[n];
    for(int i=0;i<n;i++)
    {
        array[i]=new int[n];
    }
    cout<<"Enter Elements : "<<endl;
    read(array,n);
    print(array,n);
}
