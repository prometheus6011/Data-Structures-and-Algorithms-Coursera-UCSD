#include <iostream>
#include <vector>
using namespace std ;

void swap( int *a, int *b ) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray( vector<int> nums ) {
    int size = nums.size() ;
    for (int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void selectionSort( vector<int> array ) {
    int size = array.size() ;
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {
        if (array[i] < array[min_idx]) {
            min_idx = i ;
        }
    }

    swap(&array[min_idx], &array[step]);
    }
    printArray ( array ) ;
}

int main( ) {
    int n ;
    cin >> n ;
    vector<int> a(n) ;
    for ( size_t i = 0; i < a.size(); i++ ) {
        cin >> a[i] ;
    }

    selectionSort ( a ) ;
}
