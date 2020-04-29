#pragma once

#include <iostream>
#include <fstream>
#include <stdlib.h>

class Graf
{
	protected:
		int l_w, l_k;		// liczba wierzcho³ków, liczba krawêdzi
		double g;			//gêstoœæ grafu
	public:
		const int& getW () const {return l_w;}
		const int& getK () const {return l_k;}
		virtual void Wyp_Los (const bool petla ) const=0;		//funkcja do wype³nienia grafu w sposób pseudolosowy
		virtual void Druk () const=0;							// funkcja do wyswietlenia grafu na terminal
		virtual const int Wczytaj () =0;	 					// funkcja do wczytania grafu z pliku
		virtual void Zapisz (const int P_W) const=0;			// funkcja do zapisania grafu do pliku
		virtual ~Graf() {};
		explicit Graf(int LW, int LK, int gestosc) : l_w(LW), l_k(LK), g(gestosc) {}		
		Graf() {};
};
