#include <iostream>
#include <vector>

using namespace std;

class kupac
{
public:
	vector<int> t;

	kupac()
	{
		t.push_back(0);
	}

	int size() {
		return t.size() - 1;
	}

	~kupac()
	{
	}

	int peek() {
		return -1;
	}

	int pop() {
		return -1;
	}

	void push(int e) {
		
	}
private:

	int szulo(int n) {
		return n/2;
	}

	int kisebbik_gyerek(int n) {
		int egyik = n*2;
		int masik = egyik + 1;
		if (size() < egyik)
			return -1;
		if (size() < masik)
			return egyik;
		return t[egyik]<t[masik] ? egyik : masik;
	}

	// LBYL : Look before you leap stratégia -- személyes preferenciám
	// EAFP : Easier to ask forgiveness than permission  -- de ez elterjedtebb: try-catch....

	int nagyobbik_gyerek(int n) {
		int egyik = n * 2;
		int masik = egyik + 1;
		if (size() < egyik)
			return -1;
		if (size() < masik)
			return egyik;
		return t[egyik] > t[masik] ? egyik : masik;
	}

	void sullyeszt(int n) {

	}

	void fellebegtet(int n) {

	}

	void csere(int i, int j) {
		int temp = t[i];
		t[i] = t[j];
		t[j] = temp;
	}
};


int main()
{

}
