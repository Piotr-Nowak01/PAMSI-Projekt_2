#pragma once
#include "graf.h"
#include <memory>
#include <cstdlib>
class Graf_Macierz : public Graf
{
	std::unique_ptr<std::unique_ptr<int[]>[]> macierz;
	public:
		void Wyp_Los (const bool petla ) const override;
		void Druk () const override;	
		const int Wczytaj () override; 
		void Zapisz (const int P_W) const override;
		const int& odleglosc (int wiersz, int kolumna) const {return macierz[wiersz][kolumna];}
		explicit Graf_Macierz (int LW, double gestosc);
		Graf_Macierz():Graf() {};
};
