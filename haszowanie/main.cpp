#include <iostream>
#include <math.h>
#define ogranicz 100		// wielko�� zbioru losowanych liczb
#define manip 1				// przesuwa zbi�r losowanych liczb
using namespace std;
bool czy_1 (int n)
{
	for (int i=0; i<=sqrt(n);i++)
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
	
}
