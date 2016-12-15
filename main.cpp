#include <stdio.h> 
#include <stdlib.h> 
struct Book {
	char author[10];
	char name[10];
	char publ[10];
	char year[4];
	char pages[4];
};

int main() {
	int n = 0;
	Book *pBook;
	FILE *pF; fopen_s(&pF, "myList.dat", "rb");
	if (pF == 0) { 
		printf("Error, file not found"); 
		system("pause");
		return 1; 	
	} 
	fread(&n, sizeof(int), 1, pF); 
	pBook = new Book[n];
	fread(pBook, sizeof(Book), n, pF); 
	fclose(pF); 
	for (int i = 0; i<n; i++) 
		printf("%s %s %s %s %s\n", pBook[i].author,
		pBook[i].name, pBook[i].publ, pBook[i].year, pBook[i].pages); 
	system("pause");
	return 0;	
}
