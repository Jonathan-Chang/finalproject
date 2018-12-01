#include <chrono>
#include "BST.hpp"

using TimePoint = std::chrono::time_point<std::chrono::system_clock>;
using Milli = std::chrono::duration<double, std::ratio<1,1000>>;

void ascendingInsert(int n) {
	TimePoint start, end;

	start = std::chrono::system_clock::now();
	
	BST<int> bst;
	for (int i = 0; i < n; i++) {
		bst.insert(i);
	}
	
	end = std::chrono::system_clock::now();

	Milli time = end - start;

	std::cout << "Inserting " << n
			  << " items in ascending order took " << time.count()
			  << " milliseconds" << std::endl;
}

int main() {
	ascendingInsert(1);
	ascendingInsert(10000);
	ascendingInsert(100000);
	ascendingInsert(1000000);
	ascendingInsert(10000000);

	return 0;
}
