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

	int size() 
	{
		return t.size() - 1;
	}

	~kupac()
	{
	}

	int peek() 
	{
		return t[1];
	}

	int pop() 
	{
		int result = peek();
		csere(1, size());
		t.erase(t.end()-1);
		sullyeszt(1);
		return result;
	}

	void push(int e) 
	{
		t.push_back(e);
		fellebegtet(size());
	}

	void diagnosztika()
	{
		for (int i = t.size()-1; 0<=i; i--)
		{
			int j = i;
			while (j != 0)
			{
				cout << "t[" << j << "] : " << t[j] << endl;
				j = szulo(j);
			}
			cout << "lanc vege\n";
		}
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
		while (t[n] < t[szulo(n)])
		{
			csere(n, szulo(n));
			n = szulo(n);
		}
	}

	void csere(int i, int j) {
		int temp = t[i];
		t[i] = t[j];
		t[j] = temp;
	}
};


int main()
{
	cout << "--------------- kupac letrehozasa --------------\n";
	kupac k;
	k.diagnosztika();
	cout << "--------------- kupac 5-ot belerakjuk --------------\n";
	k.push(5);
	k.diagnosztika();
	cout << "--------------- kupac 3-ot belerakjuk --------------\n";
	k.push(3);
	k.diagnosztika();
	cout << "--------------- kupac 7-et belerakjuk --------------\n";
	k.push(7);
	k.diagnosztika();

	cout << "--------------- kupac 1-et belerakjuk --------------\n";
	k.push(1);
	k.diagnosztika();
	cout << "--------------- kupac: 3, 5, 2, 4, 1 szamokat belerakjuk --------------\n";
	k.push(3);
	k.push(5);
	k.push(2);
	k.push(4);
	k.push(1);
	k.diagnosztika();

}
