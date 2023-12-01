#include <iostream>
#include <vector>
#include<cstdlib>

using namespace std;

int randint_kozott(int tol, int ig)
{
	return tol + (rand() % (ig - tol));
}


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

	// megkeresi a kupacban az elem ÉRTÉKET, és megjavítja, ha az nincs a helyén.
	void repair(int elem) {
		int i = keres(1, elem);
		megigazit(i);
	}

private:
	int szulo(int n) 
	{
		return n/2;
	}

	int kisebbik_gyerek(int n) 
	{
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

	int nagyobbik_gyerek(int n) 
	{
		int egyik = n * 2;
		int masik = egyik + 1;
		if (size() < egyik)
			return -1;
		if (size() < masik)
			return egyik;
		return t[egyik] > t[masik] ? egyik : masik;
	}

	void sullyeszt(int n) 
	{
		int kgy = kisebbik_gyerek(n);
		if (kgy == -1)
			return;
		if (t[kgy] < t[n])
		{
			csere(kgy, n);
			sullyeszt(kgy);
		}
	}

	
	void fellebegtet(int n) 
	{
		while (t[n] < t[szulo(n)])
		{
			csere(n, szulo(n));
			n = szulo(n);
		}
	}

	int keres(int hol, int elem)
	{
		if (t[hol] == elem)
			return hol;
		int egyik = 2 * hol;
		if (size() < egyik)
			return -1;
		int az_eredmeny = keres(egyik, elem);
		if (az_eredmeny != -1)
			return az_eredmeny;
		int masik = 2 * hol + 1;
		if (size() < masik)
			return -1;
		az_eredmeny = keres(masik, elem);
		if (az_eredmeny != -1)
			return az_eredmeny;
		return -1;
	}

	void megigazit(int n) 
	{
		sullyeszt(n);
		fellebegtet(n);
	}

	void csere(int i, int j) 
	{
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
	cout << "--------------- kupac: poppolunk --------------\n";
	cout << k.pop();
	k.diagnosztika();

	cout << "--------------- kupac: poppolunk --------------\n";
	cout << k.pop();
	k.diagnosztika();

	cout << "--------------- kupac: poppolunk --------------\n";
	cout << k.pop();
	k.diagnosztika();

	cout << "--------------- kupac: poppolunk --------------\n";
	cout << k.pop();
	k.diagnosztika();
	cout << "--------------- kupac: poppolunk, mintha nem lenne holnap --------------\n";
	cout << k.pop();
	cout << k.pop();
	cout << k.pop();
	cout << k.pop();
	cout << k.pop();
	k.diagnosztika();


	srand((unsigned)time(NULL)); // itt (a program elején) inicializálod a randomszámgenerátort, 
	for (int i = 0; i < 100; i++)
	{
		cout << randint_kozott(5, 10)<<endl; // itt pedig használod. 5 inklúzív, 10 exklúzív határ, azaz 10 már nem lehet eredmény, 5 még igen.
	}

}





