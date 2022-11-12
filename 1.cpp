#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
int L;
vector<string> Ary;
bool Reader(string Dan) {
	int Ja=0, Mo=0;
	for (int i = 0; i < L; i++) {
		if (Dan[i] == 'a' || Dan[i] == 'e' ||
			Dan[i] == 'i' || Dan[i] == 'o' ||
			Dan[i] == 'u') Mo++;
		else Ja++;
	}
	if (Mo >= 1 && Ja >= 2) return 1;
	else return 0;
}
void Re(vector<char> Array, int index,string Dan) {
	if (Dan.size() == L) {
		if(Reader(Dan)) Ary.push_back(Dan);
		return;
	}
	else {
		for (int i = index; i < Array.size(); i++) {
			if (!(Dan.find(Array[i]) != string::npos)) {
				if(Dan==""||Dan[Dan.size() - 1] < Array[i]) 
					Dan += Array[i];
				else return;
			}
			Re(Array, index+1, Dan);
			Dan.resize(Dan.size() - 1);
		}
	}
}
int main() {
	fast;
	int C;
	vector<char> Array;
	cin >> L >> C;
	char Alpa;
	for (int i = 0; i < C; i++) {
		cin >> Alpa;
		Array.push_back(Alpa);
	}
	sort(Array.begin(), Array.end());
	Re(Array, 0, "");
	Ary.erase(unique(Ary.begin(), Ary.end()), Ary.end());
	for (int i = 0; i < Ary.size(); i++) cout << Ary[i] << endl;
}