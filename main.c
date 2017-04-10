/*
KRO - Kr?liczki Jasia

Jasiu jest zapalonym hodowca kr?lik?w. Ostatnio poprzez eksperymenty genetyczne uszkodzi? DNA jednego z kr?lik?w i zauwa?y? ze sta?y si? nie?miertelne oraz rozmna?aj? si? w specyficzny spos?b: je?eli pierwszego dnia mamy "a" samc?w a drugiego do??czymy "b-a" samic (warto zauwa?y?, ?e drugiego dnia jest dok?adnie "b" kr?lik?w) , to trzeciego dnia otrzymamy a+b kr?lik?w, czwartego a+2b. Jasiu doszed? to nast?puj?cej prawid?owo?ci: liczba kr?lik?w w n-tym dniu jest r?wna sumie kr?lik?w w dniach n-1 oraz n-2. Jako ze Jasiu nie by? zbyt dobry z matematyki ma problem z wyliczaniem kolejnych warto?ci ci?gu. A chcia?by wszystko zweryfikowa?. Pom? Jasiowi i napisz program wyliczaj?cy liczb? kr?lik?w w n-tym dniu. Ale poniewa? do udowodnienia prawid?owo?ci Jasiowi wystarcza jedynie podanie ostatnie cyfry liczby kr?lik?w w n-tym dniu, wiec zostaniesz poproszony o wypisanie ostatniej cyfry.

Wej?cie
W pierwszej linii znajduje si? dok?adnie jedna liczba ca?kowita t (1<=t<=10000) oznaczaj?ca liczb? zestaw?w danych. W t kolejnych wierszach znajduj? si? 3 liczby: n a b (1<=n<=2*106, 1<=a,b<=5*109) oznaczaj?ce odpowiednio: liczb? dni, a - liczb? kr?lik?w pierwszego dnia, b - liczb? kr?lik?w drugiego dnia.

Wyj?cie
W ka?dym z t wierszy wyj?cia powinna znale?? si? dok?adnie jedna liczba ca?kowita, oznaczaj?ca ostatni? cyfr? liczby krolik?w w n-tym dniu.

Przyk?ad

Wej?cie:
2
5 1 1
4 4 3

Wyj?cie:
5
10


Wyt?umaczenie:
I przypadek testowy: kolejne dni: 1 1 2 3 5;
II przypadek testowy: kolejne dni: 4 3 7 10;

to do:
read data from file
fill list
compute rabbits

*/

#include <stdio.h>
#include <stdlib.h>
#include "rabbits.h"




int main(int argc, char *argv[]) {
	
	//free should be freed only dynamic data!!!
	data_input *data_list, *tmp;
	data_list = malloc(sizeof(data_input));
	read_data(data_list, "data.txt");
	
	free_data(&data_list);

    
	return 0;
}




