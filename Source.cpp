
#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	auto start = std::chrono::high_resolution_clock::now();
	// declare variables and function here
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start; //double, duration
	cout << "Time " << diff.count()  << "\n";
// chrono now, chrono 
	system("pause");
	return 0;
}
