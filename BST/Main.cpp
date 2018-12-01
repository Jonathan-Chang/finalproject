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
	ascendingInsert(5000);
	ascendingInsert(10000);
	ascendingInsert(15000);
	ascendingInsert(20000);
	ascendingInsert(25000);
	ascendingInsert(30000);
	ascendingInsert(35000);
	ascendingInsert(40000);
	ascendingInsert(45000);
	ascendingInsert(50000);
	ascendingInsert(55000);
	ascendingInsert(55000);
	ascendingInsert(60000);
	ascendingInsert(65000);
	ascendingInsert(70000);
	ascendingInsert(75000);
	ascendingInsert(80000);
	ascendingInsert(85000);
	ascendingInsert(90000);
	ascendingInsert(95000);
	ascendingInsert(100000);
	
	
	return 0;
}
