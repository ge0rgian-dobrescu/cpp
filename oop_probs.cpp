#include <iostream>
#include <stdio.h>

using namespace std;

class Sorter{
    public:
    bool ok;
    int aux;
    void sortingAlg(int arr[], int n){ // BubbleSort.
        do{
            ok=true;
        for (int i = 0; i < n - 1; i++){
            
            if (arr[i] > arr[i+1]){
                aux = arr[i+1];
                arr[i+1]= arr[i];
                arr[i] = aux;
                ok = false;
            }
        }

        }while (!ok);
}
    void printArray(int arr[], int n){
        for (int i=0 ; i < n ; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int main(){
    int arr[5]={40, 8, 11, 2, 99};
    int n=5;
    Sorter sorting;
    sorting.sortingAlg(arr,n);
    sorting.printArray(arr,n);

    return 0;
}