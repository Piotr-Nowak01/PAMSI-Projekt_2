#pragma once
#include "graf.h"
struct Krawedz
{
	int pocz,kon,odl;	// wierzcho³ek pocz¹tkowy, wierzcho³ek koñcowy, d³ugoœæ krawêdzi
}
class Graf_Lista::public Graf
{
	Krawedz* krawedz;
	public:
		void Wyp_Los ( const bool petla) const override;
		void Druk ()	const override;
		const int Wczytaj() override;
		void Zapisz (const int p_w) const override;
		const Krawedz* getstruct() const {return krawedz;}
		void dodaj_k (int pocz, int kon, int odl, int nr) const;	// wejœcie to pocz¹tkowy i koñcowy wierzcho³ek, odleg³oœæ miêdzy wierzcho³kami oraz nr indeksu w liœcie
		bool czy_ist (int pocz, int kon) const;		// wejœcie  to pocz¹tkowy i koñcowy wierzcho³ek
		explicit Graf_Lista (int l_w, double g):Graf(l_w, static_cast<int>( g*l_w*(l_w-1) ), g), krawedz (new Krawedz[static_cast<int>( g*l_w*(l_w-1) )]) {}
		Graf_Lista():Graf() {};
		~Graf_Lista() { delete [] krawedz;}
		
};
