#include <iostream>
#include <random>
#include <chrono>
using namespace std;
int d[10];
int s[10];

void randomize();
class Grouping {
public:
	static void A() {
		int a[4] = { s[1], s[2], s[3], s[4] };
		int b[4] = { s[5], s[6], s[7], s[8] };
		for (int i = 1; i <= 4; i++) s[i] = b[i - 1];
		for (int i = 1; i <= 4; i++) s[i + 4] = a[i - 1];
		return;
	}
	static void B() {
		int a[2] = { s[1], s[2] };
		int b[4] = { s[3], s[4] };
		for (int i = 1; i <= 2; i++) s[i] = b[i - 1];
		for (int i = 1; i <= 2; i++) s[i + 2] = a[i - 1];
		return;
	}
	static void C() {
		swap(s[1], s[2]);
		return;
	}
	static void D() {
		swap(s[1], s[5]);
		return;
	}
private:
	void unit() {
		int i;
		for (i = 1; i <= 4; i++) {

		}
	}
};
class Ghana : Grouping {
	
};
////////////////////////////
//End of class declaration//
////////////////////////////
int main()
{
	randomize();
	int i;
	for (i = 1; i <= 8; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
	Grouping::D();
	for (i = 1; i <= 8; i++) {
		cout << s[i] << " ";
	}
	return 0;
}
/////////////////
//End of main()//
/////////////////
void randomize() 
{
	std::random_device rn;
	std::mt19937 mtRand(time(NULL));
	int i, a;
	for (i = 1; i <= 8; i++) {
	re:
		a = mtRand() % 8 + 1;

		if (d[a] != 1) {
			d[a] = 1;
			s[i] = a;
		}
		else goto re;
	}
	return;
}