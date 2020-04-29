#include<iostream>
#include <cmath>
#define ogranicz 100		// wielkoœæ zbioru losowanych liczb
#define manip 1				// przesuwanie zbioru z jakiego losowane s¹ liczby
using namespace std;
class doublehasz
{
	int* tab;
	int rozmiar;	// rozmiar tablicy haszuj¹cej
	int q;			// zmienna do 2 haszowania
	int obc_roz;
	public:
		bool czy_p() {return obc_roz==rozmiar;}
		int hasz1 (int x) {return (x%rozmiar);}
		int hasz2(int x) { return (q-(x%q));}
		doublehasz(int x, int y)
		{
			rozmiar=x;
			q=y;
			tab= new int [rozmiar];
			obc_roz=0;
			for(int i=0;i<rozmiar;i++)
			{
				tab[i]=-1;
			}
		}
		void wyswietl()
		{
			for (int i=0; i<rozmiar;i++)
			{
				if(tab[i]!=-1)
				{
					cout<<i<<" ---> "<<tab[i]<<endl;
				}
				else
				{
					cout<<i<<endl;
				}
			}
		}
		int szukaj(int x)
		{
			int indeks1=hasz1(x);
			int indeks2=hasz2(x);
			int i=0;
			while (tab[indeks1+i*indeks2])
			{
				if (tab[indeks1+i*indeks2]==-1)
				{
					return -1;
				}
				i++;
			}
			return (i+1);		//zwraca, po ilu próbkach znaleziono liczbê
		}
		int dodaj(int x)
		{
			if (czy_p())
			{
				return 0;
			}
			int indeks1=hasz1(x);
			if(tab[indeks1]!=-1)
			{
				int indeks2=hasz2(x);
				int i=1;
				while(1)
				{
					int indeks=(indeks1+i*indeks2)%rozmiar;
					if(tab[indeks]==-1)
					{
						tab[indeks]=x;
						return i;
					}
					i++;
				}
			}
			else
			{
				tab[indeks1]=x;
				obc_roz++;
				return 1;
			}
		}
		void usun(int x)
		{
			int z=szukaj(x);
			if (z!=-1)
			{
				int indeks1=hasz1(x);
				int indeks2=hasz2(x);
				tab[indeks1+z*indeks2]=-1;
				cout<<"Usuniêto."<<endl;
				return;
			}
			else
			{
				cout<<"Nie ma takiego elementu."<<endl;
				return;
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
	int N,q,z;
	cout<<"Podaj rozmiar tablicy"<<endl;
	cin>>N;
	while(!czy_1(N))
	{
		cout<<endl<<"To nie jest liczba pierwsza"<<endl;
		cin>>N;
	}
	cout<<endl<<"Podaj liczbe q do 2 haszowania"<<endl;
	cin>>q;
	while(!(czy_1(q)&&q<N))
	{
		cout<<endl<<"Musi byæ to liczba pierwsza mniejsza od "<<N<<endl;
		cin>>q;
	}
	doublehasz hasz(N,q);
	for (int i=0;i<N;i++)
	{
		int x=rand()%ogranicz+manip;
		cout<<"Element: "<<x<<" ilosc probek: ";
		cout<<hasz.dodaj(x)<<endl;
		z=x;
	}
	cout<<"Element "<<z<<" znaleziono po "<<hasz.szukaj(z)<<" próbkach"<<endl;
	hasz.wyswietl();
}

