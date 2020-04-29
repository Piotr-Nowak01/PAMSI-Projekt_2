#include "lista.h"
static int ogranicz=100;	// ogranicz i manip takie same jak w grafmacierz.cpp
static int manip=1;	
void Graf_Lista::dodaj_k (int pocz, int kon, int odl, int nr) const
{
	krawedz[nr].pocz=pocz;
	krawedz[nr].kon=kon;
	krawedz[nr].odl=odl;
}
bool Graf_Lista::czy_ist (int pocz, int kon) const
{
	for (int i=0; i<l_k;i++)
	{
		if (krawedz[i].pocz ==pocz && krawedz[i].kon == kon)
		{
			return true;
		}
	}
	return false;
}void Graf_Lista::Wyp_Los ( const bool petla)
{
	if (g==1)
	{
		int nr=0;
		for (int i=0, i<l_w;i++)
		{
			for (int j=0; j<l_w;j++)
			{
				if(i!=j)
				{
					int odl=rand()%ogranicz+manip;
					while(odl==0)
					{
						odl=rand()%ogranicz+manip;
					}
					dodaj_k(i,j,odl,nr++);
				}
			}
		}
	}
	else
	{
		int krawedzie=0;
		while(krawedzie<l_k)
		{
			int pocz=rand()%l_w;
			int kon=rand()%l_w;
			if (czy_ist(pocz,kon))
			{
				int odl=rand()%ogranicz+manip;
				while(odl==0)
				{
					odl=rand()%ogranicz+manip;
				}
				if (pocz!=kon) 
				{
					dodaj_k(pocz,kon,odl,krawedzie++);
				}
				else if(petla)
				{
					dodaj_k(pocz,kon,odl,krawedzie++);
				}
			}
		}
	}
}
void Graf_Lista::Druk ()
{
	std::cout<<std::string(30,"-")<<"\n Graf jako lista\n\n";
	for(int i=0; i<l_W, i++)
	{
		std::cout<<i;
		for (int j=0; j<l_k;j++)
		{
			if (krawedz[j].pocz==i)
			{
				std::cout<<" ---> [ wierzcholek koncowy:"<<krawedz[j].kon<<" | odleglosc: "<<krawedz[j].odl<<" ]";
			}
		}
		std::cout<<"\n";
	}
	std::cout<<"\n";
}
const Graf_Lista::int Wczytaj()
{
	std::ifstream file ("input.txt");
	if(!file.is_open())
	{	
		throw "Brak pliku";
		return 1;
	}
	int start, pocz, kon, odl;
	file>>l_k>>l_w>>start;
	edge = new Edge [l_k];
	for (int i=0; i<l_k;i++)
	{
		file>>pocz>>kon>>odl;
		dodaj_k(pocz,kon,odl,i);
	}
	file.close();
	return start;	// zwraca pocz¹tkowy wierzcho³ek
}
void Graf_Lista::Zapisz (const int p_w)
{
	std::ofstream file ("output.txt");
	if(!file.is_open())
	{
		throw " Nie utworzono pliku";
		return 1;
	}
	file << l_k <<" "<<l_w<<" "<<start<<"\n";
	for (int i=0;i<l_k;i++)
	{
		file<<krawedz[i].pocz<<" "<<krawedz[i].kon<<" "<<krawedz[i].odl<<"\n";
	}
	file.close();
}
