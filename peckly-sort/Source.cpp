#include <iostream>
#include <random>
#include <chrono>
using namespace std;

int s[10];
void printS(void) { for (int i = 1; i <= 8; i++) cout << s[i] << " "; cout << endl; }
void randomize();
void findErr();
class Grouping {
public:
	static int Start() {
		return unit();
	}
	////////////////////////////////////////
	static void A() {
		int a[4] = { s[1], s[2], s[3], s[4] };
		int b[4] = { s[5], s[6], s[7], s[8] };
		for (int i = 1; i <= 4; i++) s[i] = b[i - 1];
		for (int i = 1; i <= 4; i++) s[i + 4] = a[i - 1];
		//////////
		cout << "A: ";
		printS();
		//////////
		return;
	}
	////////////////////////////////////////
	static void B() {
		int a[2] = { s[1], s[2] };
		int b[4] = { s[3], s[4] };
		for (int i = 1; i <= 2; i++) s[i] = b[i - 1];
		for (int i = 1; i <= 2; i++) s[i + 2] = a[i - 1];
		//////////
		cout << "B: ";
		printS();
		//////////
		return;
	}
	////////////////////////////////////////
	static void C() {
		swap(s[1], s[2]);
		//////////
		cout << "C: ";
		printS();
		//////////
		return;
	}
	////////////////////////////////////////
	static void D() {
		swap(s[1], s[5]);
		//////////
		cout << "D: ";
		printS();
		//////////
		return;
	}
	//End of declaration public objects
private:
	static void asdf(int a, int b) {
		switch (a) {
		case 1: {
			break;
		}
		case 2: {
			C();
			a = 1;
			break;
		}
		case 3: {
			B();
			a = 1;
			break;
		}
		case 4: {
			B();
			a = 2;
			C();
			a = 1;
			break;
		}
		}
		switch (b) {
		case 5: {
			break;
		}
		case 6: {
			A();
			b = 2;
			C();
			b = 1;
			break;
		}
		case 7: {
			A();
			b = 3;
			B();
			b = 1;
			break;
		}
		case 8: {
			A();
			b = 4;
			B();
			b = 2;
			C();
			b = 1;
			break;
		}
		}
		D();
		//A();
		return;
	}
	////////////////////////////////////////
	static void asdf2(int a1, int a2, int b1, int b2) {
		asdf(a1, b1);
		asdf(a2, b2);
		return;
	}
	////////////////////////////////////////
	static int unit() {
		int p[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		int i, cnt = 0;
		for (i = 1; i <= 4; i++) {
			if (s[i] >= 1 && s[i] <= 4) {
				p[i] = 1;
				cnt++;
			}
		}
		for (i = 5; i <= 8; i++) {
			if (s[i] >= 5 && s[i] <= 8) {
				p[i] = 1;
			}
		}
		cout << cnt << endl;
		switch (cnt) {
		case 0: {
			A();
			break;
		}
		case 1: {
			int a, b;
			for (int i = 1; i <= 4; i++) {
				if (p[i] == 1) {
					a = i;
				}
			}
			for (int i = 5; i <= 8; i++) {
				if (p[i] == 1) {
					b = i;
				}
			}
			asdf(a, b);
			break;
		}
		case 2: {
			int a, b;
			for (int i = 1; i <= 4; i++) {
				if (p[i] == 1) {
					a = i;
					break;
				}
			}
			for (int i = 5; i <= 8; i++) {
				if (p[i] == 1) {
					b = i;
					break;
				}
			}
			asdf(a, b);
			unit();
			break;
		}
		case 3: {
			int a, b;
			A();
			for (int i = 1; i <= 8; i++) { p[i] = 0; }
			cnt = 0;
			for (i = 1; i <= 4; i++) {
				if (s[i] >= 1 && s[i] <= 4) {
					p[i] = 1;
					cnt++;
				}
			}
			for (int i = 5; i <= 8; i++) {
				if (s[i] >= 5 && s[i] <= 8) {
					p[i] = 1;
				}
			}
			for (int i = 1; i <= 4; i++) {
				if (p[i] == 1) {
					a = i;
				}
			}
			for (int i = 5; i <= 8; i++) {
				if (p[i] == 1) {
					b = i;
				}
			}
			asdf(a, b);
			break;
		}
		case 4: {
			break;
		}
		}
		cout << cnt << endl;
		return cnt;
	}
	////////////////////////////////////////
};
class Ghana : Grouping {

};
////////////////////////////
//End of class declaration//
////////////////////////////
int main()
{
	//randomize();
	/*
	int i;
	for (i = 1; i <= 8; i++){
		cin >> s[i];
	}
	*/
	/*
	for (i = 1; i <= 8; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
	*/
	//Grouping::Start();
	findErr();
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
	int d[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
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
/////////////
void findErr()
{
	int i;
	int k;
	int cnt = 0;
	int original_data[10];
	randomize();
	for (k = 1; k <= 8; k++) original_data[k] = s[k];
	Grouping::Start();
	while (1) {
		for (k = 1; k <= 4; k++) {
			cnt += s[k];
		}
		if (cnt != 26 && cnt != 10) goto ERR;
		randomize();
		for (k = 1; k <= 8; k++) original_data[k] = s[k];
		Grouping::Start();
		cnt = 0;
	}

ERR:
	cout << endl << endl;

	for (i = 1; i <= 8; i++) {
		cout << original_data[i] << " ";
	}
	return;
}