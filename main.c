/*
 * main.c
 */


#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

void simple_mergesort(int* array, int from, int to) {
	if (from >= to){
		//Wenn from Wert größer ist als to Wert -> Abbruch
		return;
	}
	//Mitte des Arrays in m speichern
	int m = (to + from) / 2;

	//Rekursiver aufruf der Funktion
	//Für erste Hälfte des Arrays
	simple_mergesort(array, from, m);
	//Für zweite Hälfte des Arrays
	simple_mergesort(array, m+1, to);

	//temp Datensatz für göße des Arrays festlegen
	int *temp = malloc((to-from)*sizeof(int));
	//Variablen für Schleifen befüllen
	int i = from, j = m + 1, k = 0;

	//Arrays durchgehen
	while (i <= m && j <= to){
		//Werte mit einander Vergleichen und kleineren Wert in Temp speichern
		if (array[i] <= array[j]){
			temp[k++] = array[i++];
		}
		else {
			temp[k++] = array[j++];
		}
	}

	//Solange noch nicht alle möglichen i verwendet
	while (i <= m){
		//Wird Stelle i im Array an nächste Stelle von temp geschrieben
		temp[k++] = array[i++];
	}
	
	//Solange noch nicht alle möglichen j verwendet
	while (j <= to){
		//Wird Stelle j im Array an nächste Stelle von temp geschrieben
		temp[k++] = array[j++];
	}
	k--; //k-1 damit man die länge des temp Arrays hat
	while (k >= 0){
		//temp rückwärts sortiert in array speichern
		array[from + k] = temp[k];
		k--;
	}
	//temp leeren
	free(temp);
}

void generate_sort_and_print(const int size) {
	//Ruft Funktion auf die random Array erstellt
	int* a = generate_random_array(size);
	//Gibt unsortiertes Array aus
	print_array("Unsortiert:", a, size);
	//Ruft Funktion auf die Array sortiert
	simple_mergesort(a, 0, size -1);
	//Gibt sortiertes Array aus
	print_array("Sortiert:", a, size);
	//a leeren
	free(a);
}

//Vorgegebene Main, ruft Funktion mehrmals unterschiedlich auf
int main(int argc, char** argv) {
	generate_sort_and_print(10);
	generate_sort_and_print(20);
	generate_sort_and_print(7);
	generate_sort_and_print(2);
	generate_sort_and_print(1);
	return 0;
}
