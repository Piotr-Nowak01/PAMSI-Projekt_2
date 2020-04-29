#include<iostream>
#include <cmath>
#define ogranicz 100		// wielkoœæ zbioru losowanych liczb
#define manip 1				// przesuwanie zbioru z jakiego losowane s¹ liczby
using namespace std;
class probkowanie
{
	
	int* tab;
	int rozmiar;	// rozmiar tablicy haszuj¹cej
	int obc_roz;
	public:
		bool czy_p() {return obc_roz==rozmiar;}
		int hasz (int x) {return (x%rozmiar);}
		probkowanie(int x)
		{
			rozmiar=x;
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
			int indeks=hasz(x);
			for (int i=0; i<rozmiar;i++)
			{
				int z=(indeks+i)%rozmiar;
				if(tab[z]==x)
				return i+1;
			}
			return -1; 		// nie znaleziono
		}
		int dodaj(int x)
		{
			if(czy_p())
			{
				return 0;
			}
			int indeks=hasz(x);
			if(tab[indeks]!=-1)
			{
				for (int i=1; i<rozmiar;i++)
				{
					int z=(indeks+i)%rozmiar;
					if(tab[z]==-1)
					{
						tab[z]=x;
						obc_roz++;
						return (i+1);
					}
				}
				
			}
			else
			{
				tab[indeks]=x;
				obc_roz++;
				return 1;
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
	int N,z;
	cout<<"Podaj rozmiar tablicy"<<endl;
	cin>>N;
	while(!czy_1(N))
	{
		cout<<endl<<"To nie jest liczba pierwsza"<<endl;
		cin>>N;
	}
	cout<<endl;
	probkowanie hasz(N);
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
