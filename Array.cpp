#include<iostream>
using namespace std;

class Array{
	int *a, length, size;
	public:
	Array(int n);
	int getSize();
	void insert(int x, int index);
	int del(int index);
	void display();
};

Array::Array(int n){
	a = new int[n];
	length = n;
	size = 0;
}

int Array::getSize(){
	return size;
}

void Array::insert(int x, int index){
	if(size == length){
		cout<<"Array is full. Insertion operation failed";
		exit(0);
	}
	if(index<0 || index>size){
		cout<<"Invalid index. Insertion operation failed";
		exit(0);
	}
	int noOfMovements = 0;
	for(int i=size-1; i>=index; i--){
		a[i+1] = a[i];
		noOfMovements++;
	
	}
	a[index] = x ;
	size++;
	cout<<"\nx = "<<x<<", index = "<<index<<", no of ovements = "<<noOfMovements ;
}

void Array::display(){
	cout<<"[";
	for(int i=0; i<size; i++)
		cout<<a[i]<<", ";
	cout<<"\b\b]";
}
int Array::del(int index){
	if(size == 0){
		cout<<"Array is empty. deletion failed.";
		exit(0);
	}
	if(index<0 || index >= size){
		cout<<"Invalid index. Deletion failed.";
		exit(0);
	}
	int x = a[index];
	int noOfMovements = 0;
	for(int i = index+1; i<size; i++){
		a[i-1] = a[i];
		noOfMovements++;
	}
	cout<<"\ndeleted element = "<<x<<", index = "<<index<<", no of ovements = "<<noOfMovements ;
	size--;
	return x;
}
void store(Array &a, int n){
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		a.insert(i,(i-1)/2);
		else
		a.insert(i,i-1);
	}
}
void storeSeries(Array &a, int n){ // to store 1, 2, 2, 3, 4, 4, 5, ..., n, n
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		   a.insert(i,a.getSize());
		else{
			a.insert(i,a.getSize());
			a.insert(i,a.getSize());
		}
	}
}

void delDuplicatesMinMovement(Array &a, int n){
	//1, 2, 2, 3, 4, 4, 5, 6, 6 [8, 5, 2]
	int m = 3*n/2 - 1;
	for(int i=m; i>=2; i=i-3){
		a.del(i);
	}
}
void delDuplicatesMaxMovement(Array &a, int n){
	//1, 2, 2, 3, 4, 4, 5, 6, 6 [1, 3, 5]
	int m = 3*n/2 - 1;
	for(int i=1; i<n; i=i+2){
		a.del(i);
	}
}
int main(){
	int n;
	cout<<"Enter the even number ";
	cin>>n;
	Array a(3*n/2);
	storeSeries(a, n);
	cout<<"\nContent of array: ";
	a.display();
	delDuplicatesMaxMovement(a, n);
	cout<<"\nContent of array after duplicate removal: ";
	a.display();
	return 0;
}
