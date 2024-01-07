#include <stdio.h>
#include <stdlib.h>
#include "kullanici.h"
#include <locale.h>

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL, "Turkish"); //Turkce karakter icin
	giris();
	return 0;
}
