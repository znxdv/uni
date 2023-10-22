#ifdef _WIN32
#include <windows.h>
#define clear "cls"
#else
#include <unistd.h>
#define clear "clear"
#endif

#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	system(clear);

	float c, f, k, r;

	puts("<<Temperature Converter>?\n");
	puts("[1] Celcius");
	puts("[2] Fahrenheit");
	puts("[3] Kelvin");
	puts("[4] Reamur");
	puts("[5] Exit");
	printf("\nChoose: ");

  	switch(getch()) {
		case '1':
			puts("{===Celcius===");
			printf("\nInput temperature in Celcius: ");
			scanf("%f", &c);

			f = c * 1.8 + 32;
			k = c + 273.15;
			r = c * 0.8;

			printf("\nIn Fahrenheit: %.2f F\nIn Kelvin: %.2f K\nIn Reamur: %.2f R\n", f, k, r);
			printf("\nPress any key to continue!");
			getch();
			main();
			break;
		case '2':
			puts("{===Fahrenheit===");
			printf("\nInput temperature in Fahrenheit: ");
			scanf("%f", &f);

			c = f * 0.5556 - 32;
			k = (f - 32) * 0.5556 + 273.15;
			r = f * 0.4444 - 32;

			printf("\nIn Celcius: %.2f C\nIn Kelvin: %.2f K\nIn Reamur: %.2f R\n", c, k, r);
			printf("\nPress any key to continue!");
			getch();
			main();
			break;
		case '3':
			puts("{===Kelvin===");
			printf("\nInput temperature in Kelvin: ");
			scanf("%f", &k);

			c = k - 273.15;
			f = (k - 273.15) * 1.8 + 32;
			r = k * 0.8 - 273.15;

			printf("\nIn Celcius: %.2f C\nIn Fahrenheit: %.2f F\nIn Reamur: %.2f R\n", c, f, r);
			printf("\nPress any key to continue!");
			getch();
			main();
			break;
		case '4':
			puts("{===Reamur===");
			printf("\nInput temperature in Reamur: ");
			scanf("%f", &r);

			c = r * 1.25;
			f = r * 2.25 + 32;
			k = r * 1.25 + 273.15;

			printf("\nIn Celcius: %.2f C\nIn Fahrenheit: %.2f F\nIn Kelvin: %.2f K\n", c, f, k);
			printf("\nPress any key to continue!");
			getch();
			main();
			break;
		case '5':
			puts("\n\nThank you for using my program :)...");
			break;
		default:
			printf("Invalid Input! ");    
			if(getch()) main();
	}
	return 0;
}