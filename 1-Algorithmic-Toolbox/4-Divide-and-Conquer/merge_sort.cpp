#include <iostream>
#include <vector>
using namespace std ;

void printArray( vector<int> arr) {
    for (int i = 0; i < arr.size() ; i++) {
        cout << arr[i] << " " ;
    }
  cout << endl;
}

void merge( vector<int> nums, int left, int mid, int right ) {

    int subarray1_len = mid - left + 1 ;
    int subarray2_len = right - mid ;

    vector<int> subarray1(subarray1_len), subarray2(subarray2_len) ;

    for( int i = 0; i < subarray1_len; i++ ) {
        subarray1[i] = nums[left + i] ;
    }
    for ( int i = 0; i < subarray2_len; i++ ) {
        subarray2[i] = nums[mid + 1 + i] ;
    }

    int point1 = 0 ;
    int point2 = 0 ;
    int point3 = left ;

    while( point1 < subarray1_len && point2 < subarray2_len ) {
        if ( subarray1[point1] <= subarray2[point2] ) {
            nums[point3] = subarray1[point1] ;
            point1++ ;
        } else {
            nums[point3] = subarray2[point2] ;
            point2++ ;
        }
        point3++ ;
    }

    while( point1 < subarray1_len ) {
        nums[point3] = subarray1[ point1 ] ;
        point1++, point3++ ;
    }

    while( point2 < subarray2_len ) {
        nums[point3] = subarray2[ point2 ] ;
        point2++, point3++ ;
    }
}

void mergeSort( vector<int> nums, int left, int right ) {

    if ( left < right ) {
        int mid = left + (right - left) / 2 ;

        mergeSort( nums, left, mid ) ;
        mergeSort( nums, mid + 1, right) ;

        merge( nums, left, mid, right ) ;
    }
}

int main( ) {
    int n ;
    cin >> n ;
    vector<int> a(n) ;
    for ( size_t i = 0; i < a.size(); i++ ) {
        cin >> a[i] ;
    }

    mergeSort ( a, 0, a.size() - 1 ) ;
}