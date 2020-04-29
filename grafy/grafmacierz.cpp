#include "grafmacierz.h"
static int nieskonczonosc=1000000;
static int ogranicz=100;	//ogranicznik losowanych liczb do losowego uzupe³nienia grafu
static int manip=1;			// s³u¿y do przesuwania zbioru liczb wartoœci. Dla ogranicz=100 funkcja losuje liczby od 0 do 99.
							// Przyk³adowo dla manip=1 liczby bêd¹ losowane z zakresu od 1 do 100
Graf_Macierz::Graf_Macierz(int LW, double g):Graf(LW, static_cast<int>( g*LW*(LW-1), g )),
	macierz(std::make_unique<std::unique_ptr<int[]>[]>(LW))
{
	for (int i=0; i<l_w, ++i)
	{
		macierz[i]=std::make_unique<int[]>(LW);
		for (int j=0; j<l_w;++j)
		{
			if (i==j)
			{
				macierz[i][j]=0;
			}
			else 
			{
				macierz[i][j]=nieskonczonosc;
			}
		}
	}
}
void Graf_Macierz::Wyp_Los(const bool petla) const
{
	if (g==1)	// pe³en graf
	{
		for (int i=0; i<l_w;++i)
		{
			for (int j=0; j<l_w;++j)
			{
				int od = rand()%ogranicz+manip;
				while(od==0)
				{
					od=rand()%ogranicz+manip;
				}
				macierz[i][j]=od;
			}
		}
	}
	else
	{
		int kr = l_k;
		while (kr)
		{
			int wiersz_w=rand()%l_w;
			int kolumna_w=rand()%l_w;
			if (macierz[wiersz_w][kolumna_w]==0 || macierz[wiersz_w][kolumna_w]==nieskonczonosc)
			{
				int od=rand()%ogranicz+manip;
				while(od==0)
				{
					od=rand()%ogranicz+manip;
				}
				if (wiersz_w!=kolumna_w)
				{
					macierz[wiersz_w][kolumna_w]=od;
					kr--;
				}
				else if (petla)		//dla wartoœci true funkcja pozwala robiæ pêtle w grafie 
				{
					macierz[wiersz_w][kolumna_w]=od;
					kr--;
				}
			}
		}
	}
}
void Graf_Macierz::Druk() const
{
	std::cout<<std::string(33,'-')<<" \n Graf w postaci macierzy \n\n";
	for (int i=0l i<l_w;i++)
	{
		if (i<=10)
		{
			std::cout<<"    "<<i;
		}
		else if (i<=100)
		{
			std::cout<<"   "<<i;
		}
		else
		{
			std::cout<<"  "<<i;
		}
	}
	std::cout<<"\n\n";
	for (int i=0;i<l_w;i++)
	{
		if (i<=10)	
		{
			std::cout<<i<<"   |";
		}
		else if (i<=100) 
		{
			std::cout<<i<<"  |";
		}
		else
		{
			std::cout<<i<<" |";
		}
		for (int j=0;j<l_w;j++)
		{
			int od = macierz[i][j];
			if (od=nieskonczonosc)
			{
				std::cout<<"X";			// gdy wierzcho³ki nie s¹ po³¹czone to wyœwietlany jest znak X	
			}
			else
			{
				std::cout<<od;
			}
			if(abs(od)<10 ||abs(od)==nieskonczonosc) 
			{
				std::cout<<"    ";
			}
			else if (abs(od)<100)
			{
				std::cout<"   ";
			}
			else 
			{
				std::cout<<"  ";
			}
			if (od < 0) std::cout<<'\b';
		}
		std::cout<<"|\n";
	}
	std::cout<<"\n";
}
void Graf_Macierz::Wczytaj ()
{
	std::ifstream file("input.txt");	// input.txt to nazwa pliku z danymi grafu
	if(!file.is_open())
	{
		throw "Brak pliku";
		return 1;
	}
	int start, pocz, kon, odl;		// wierzcho³ek startowy, wierzcho³ek pocz¹tkowy krawêdzi, wierzcho³ek koñcowy krawêdzi, d³ugoœæ krawêdzi
	plik>>l_k>>l_w>>start;
	macierz = std::make_unique<std::unique_ptr<int[]>[]>(l_w);
	for (int i=0, i<l_w,i++)	//tworzenie macierzy;
	{
		macierz[i]=std::move(std::make_unique<int[]>(l_w));
		for(int j=0; j<l_w;j++)
		{
			if(i==j)
			{
				macierz[i][j]=0;
			}
			else
			{
				macierz[i][j]=nieskonczonosc;
			}
		}
	}
	for (int i=0;i<l_k;i++)		// wpisywanie krawêdzi do macierzy
	{
		plik>>pocz>>kon>>odl;
		macierz[pocz][kon]=odl;
	}
	file.close();
	return start;		// zwraca wierzcho³ek pocz¹tkowy
}
void Graf_Macierz::Zapisz(const int p_w)
{
	std::ofstream file ("utworzony_graf.txt");
	if (!file.is_open())
	{
		throw "Nie utworzono pliku"
		return 1;
	}
	file<<p_w<<" "<<l_k<<" "<<l_w<<"\n";
	for (int i=0; i<l_w;i++)
	{
		for (int j=0; j<l_w<j++)
		{
			file<<i<<" "<<j<<" "<<macierz[i][j]<<"\n";
		}
	}
	file.close();
}
