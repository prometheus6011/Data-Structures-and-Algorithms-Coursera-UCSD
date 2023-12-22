#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <iterator>
#include <functional>
#include <utility>

using namespace std ;

struct DisjointSetsElement {
	int size, parent, rank;
	
	DisjointSetsElement(int size = 0, int parent = -1, int rank = 0):
	    size(size), parent(parent), rank(rank) {}
};

struct DisjointSets {
	int size;
	int max_table_size;
	vector <DisjointSetsElement> sets;

	DisjointSets(int size): size(size), max_table_size(0), sets(size) {
		for (int i = 0; i < size; i++)
			sets[i].parent = i;
	}

	int getParent(int table) {
		
		if ( table != sets[table].parent ) {
			sets[table].parent = getParent( sets[table].parent ) ;
		} 

		return sets[table].parent ;
	}

	void update_tables( int real_destination, int real_source ) {
		sets[real_destination].size += sets[real_source].size ;
		sets[real_source].size = 0 ;

		if ( this->max_table_size < sets[real_destination].size ) {
			this->max_table_size = sets[real_destination].size ;
		}
	}

	void union_sets( int real_destination, int real_source ) {
		if ( sets[real_source].rank > sets[real_destination].rank ) {
			sets[real_destination].parent = sets[real_source].parent ;
			swap( real_source, real_destination ) ;
		} else {
			sets[real_source].parent = sets[real_destination].parent ;
			if ( sets[real_source].rank == sets[real_destination].rank ) {
				sets[sets[real_destination].parent].rank++ ;
			}
		}

		update_tables( real_destination, real_source ) ;
	}

	void merge(int destination, int source) {
		int realDestination = getParent(destination);
		int realSource = getParent(source);
		if (realDestination != realSource) {
			union_sets( destination, source ) ;
		}		
	}
};

int main() {
	int n, m;
	cin >> n >> m;

	DisjointSets tables(n);
	for (auto &table : tables.sets) {
		cin >> table.size;
		tables.max_table_size = max(tables.max_table_size, table.size);
	}

	vector<int> destination(m), sources(m) ;

	for (int i = 0; i < m; i++) {
		cin >> destination[i] >> sources[i] ;
                --destination[i] ;
                --sources[i] ;
		
		tables.merge(destination[i], sources[i]);
	  cout << tables.max_table_size << endl;
	}

	for (int i = 0; i < m; i++ ) {
		cout << tables.max_table_size << endl ;
	}

	return 0;
}
