#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void nacrtaj(int n) {
	char matrica[6][7] = { " ___ ","|  |","|   ","|   ","|   ","|____\n" };
	switch (n) {
		case 6: matrica[4][4] = '\\';
		case 5: matrica[4][2] = '/';
		case 4: matrica[3][4] = '\\';
		case 3: matrica[3][2] = '/';
		case 2: matrica[3][3] = '|';
		case 1: matrica[2][3] = 'O';
	}
	for (int i = 0; i < 6; i++) {
		printf("%s\n", matrica[i]);
	}
}
void ispisi(char rec[]) {
	for (int i = 0; i < strlen(rec); i++) {
		printf("%c ",rec[i]);
	}
	printf("\n");
}

int main() {
	char reci[][20] = {
	"UCIONICA","KLUPA","TABLA","BAZEN","NOKTI","RANAC","BANANA","ANANAS","LAPTOP","KRASTAVAC","PATIKA","FLASA","JASTUK","LAMPA","KNJIGA","PROZOR","CINIJA","SVESKA","KOLICA","AUTOBUS","ZAVESE","HRAST","ZVUCNIIK","KUTIJA","GITARA","DIGITRON"};

	//unosi se broj n i on nam predstavlja rec iz niza koja ce da se pogadja
	printf("Unesite broj u intervalu od 0 do 25\n");
	int n;
	scanf("%d", &n);
	char rec1[20], rec[20];
	strcpy(rec1, reci[n]); //prepisujemo rec iz niza reci u promenljivu rec1
	int duzina = strlen(rec1); //duzina reci koja se pogadja
	for (int k = 0; k < duzina; k++) { //rec prvo ima _ na mestu svakog slova koje se pogadja, kako koje slovo pogodimo _ menjamo njim
		rec[k] = '_';
	}
	rec[duzina] = '\0'; //mora da se unese znak za kraj reci

	int greska = 0, pogodjeno = 0;
	ispisi(rec);
	while (1) {
		printf("\nPogadjajte slovo!\n");
		char c;
		scanf("\n%c", &c);
		int a = 0;
		for (int i = 0; i < duzina; i++) { //prolazimo kroz svako slovo reci i proveravamo da li se uneto slovo poklapa sa nekim od slova u reci
			if (rec1[i] == c) { //ako se uneto slovo poklapa sa nekim slovom u reci
				if (rec[i] == '_') {//ako uneto slovo nije vec pogodjeno
					rec[i] = c;
					pogodjeno++;
				}
				a++;
			}
		}
		if (a == 0) {
			greska++; //ako se uneto slovo ne poklapa ni sa jednim slovom u reci (nema ga u reci) greska se povecava za 1
		}
		nacrtaj(greska);
		ispisi(rec);

		if (a > 0 && pogodjeno<duzina) {
			printf("Da li zelite da pogadjate celu rec? Y/N \n");
			char answer;
			scanf("\n%c", &answer);
			if (answer == 'Y') {
				char b, rec2[20];
				int br = 0; //nam kaze koje po redu nam je slovo
				scanf("\n%c", &b);
				while (b != '\n') { //ucitavamo karaktere sa ulaza dok ne dodjemo do enter(\n) jer je to kraj reci
					rec2[br] = b;
					scanf("%c", &b);
					br++;
				}
				rec2[br] = '\0'; //obavezno dodati znak za kraj stringa
				int jednaki = strcmp(rec1, rec2); //funkcija za uporedjivanje dva stringa, vraca vrednost 0 ako su jednaki
				if (jednaki == 0) {
					printf("Cestitamo! Pogodili ste rec %s!", rec2);
					break;
				}
				printf("\nNiste pogodili rec!\n"); //ako nismo pogodili rec odnosno ako je jednaki!=0
			}
		}

		if (greska == 6) { //ako smo promasili 6 puta, izgubili smo
			printf("Nazalost izgubili ste!Trazena rec je biLa %s",rec1);
			break;
		}
		if (pogodjeno >= duzina) { //ako je broj pogodjenih slova jednak duzini reci, znaci da smo pogodili rec
			printf("Cestitamo! Pobedili ste!");
			break;
		}
	}
}
/*
____
|  |
|  O
| /|\
| / \
|______
*/