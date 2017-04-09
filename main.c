/*
KRO - Króliczki Jasia

Jasiu jest zapalonym hodowca królików. Ostatnio poprzez eksperymenty genetyczne uszkodzi³ DNA jednego z królików i zauwa¿y³ ze sta³y siê nieœmiertelne oraz rozmna¿aj¹ siê w specyficzny sposób: je¿eli pierwszego dnia mamy "a" samców a drugiego do³¹czymy "b-a" samic (warto zauwa¿yæ, ¿e drugiego dnia jest dok³adnie "b" królików) , to trzeciego dnia otrzymamy a+b królików, czwartego a+2b. Jasiu doszed³ to nastêpuj¹cej prawid³owoœci: liczba królików w n-tym dniu jest równa sumie królików w dniach n-1 oraz n-2. Jako ze Jasiu nie by³ zbyt dobry z matematyki ma problem z wyliczaniem kolejnych wartoœci ci¹gu. A chcia³by wszystko zweryfikowaæ. Pomó¿ Jasiowi i napisz program wyliczaj¹cy liczbê królików w n-tym dniu. Ale poniewa¿ do udowodnienia prawid³owoœci Jasiowi wystarcza jedynie podanie ostatnie cyfry liczby królików w n-tym dniu, wiec zostaniesz poproszony o wypisanie ostatniej cyfry.

Wejœcie
W pierwszej linii znajduje siê dok³adnie jedna liczba ca³kowita t (1<=t<=10000) oznaczaj¹ca liczbê zestawów danych. W t kolejnych wierszach znajduj¹ siê 3 liczby: n a b (1<=n<=2*106, 1<=a,b<=5*109) oznaczaj¹ce odpowiednio: liczbê dni, a - liczbê królików pierwszego dnia, b - liczbê królików drugiego dnia.

Wyjœcie
W ka¿dym z t wierszy wyjœcia powinna znaleŸæ siê dok³adnie jedna liczba ca³kowita, oznaczaj¹ca ostatni¹ cyfrê liczby krolików w n-tym dniu.

Przyk³ad

Wejœcie:
2
5 1 1
4 4 3

Wyjœcie:
5
10


Wyt³umaczenie:
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



