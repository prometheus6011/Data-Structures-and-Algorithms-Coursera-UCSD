#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void bubble_down( int index ) {
    int min_index = index ;

    int left_index = 2 * index + 1 ;
    int right_index = 2 * index + 2 ;

    if ( (left_index < data_.size() ) && (data_[left_index] < data_[min_index]) )
			min_index = left_index;

		if ( (right_index < data_.size() ) && (data_[right_index] < data_[min_index]) )
			min_index = right_index;

    if (min_index != index) {

			std::swap(data_[index], data_[min_index]);
			swaps_.push_back(make_pair(index, min_index));
			bubble_down(min_index);

		}
  }

  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts 
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap, 
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
    
    for( int i = int(data_.size() / 2); i >= 0; i-- ) {
      bubble_down(i) ;
    }
  }
  


 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
