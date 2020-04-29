#include<iostream>
#include <list>
#include <cmath>
#define ogranicz 100		// wielkoœæ zbioru losowanych liczb
#define manip 1				// przesuwanie zbioru z jakiego losowane s¹ liczby
using namespace std;
class linkowanie
{
	int rozmiar;
	list<int> *tablica;
	public:
		linkowanie(int N)
		{
			this->rozmiar=N;
			tablica= new list<int> [rozmiar];
		}
		void dodaj(int x)
		{
			int indeks=flinkowanie(x);
			tablica[indeks].push_back(x);
		}
		void usun(int klucz)
		{
			int indeks=flinkowanie(klucz);
			list <int>:: iterator i;
			for (i=tablica[indeks].begin();i!=tablica[indeks].end();i++)
			{
				if (*i==klucz)
				{
					break;
				}
			}
			if(i!=tablica[indeks].end())
			{
				tablica[indeks].erase(i);
			}
		}
		int flinkowanie (int x) {return x%rozmiar;}
		void wyswietl()
		{
			for (int i=0;i<rozmiar;i++)
			{
				cout<<i;
				for (auto x: tablica[i])
				{
					cout<<" ----> "<<x;
				}
				cout<<endl;
			}
		}		
};
bool czy_1 (int n)
{
	int x=sqrt(n);
	for (int i=2; i<=x;i++)
	{		
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int N;
	cout<<"Podaj rozmiar tablicy"<<endl;
	cin>>N;
	while(!czy_1(N))
	{
		cout<<endl<<"To nie jest liczba pierwsza"<<endl;
		cin>>N;
	}
	linkowanie hasz(N);
	for (int i=0;i<N;i++)
	{
		int x=rand()%ogranicz+manip;
		hasz.dodaj(x);
	}
	hasz.wyswietl();
}

