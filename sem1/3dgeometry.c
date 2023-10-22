#ifdef _WIN32
#include <windows.h>
#define clear "cls"
#else
#include <unistd.h>
#define clear "clear"
#endif

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define PI 3.1415926535
#define system(clear); system(clear);
#define error puts("\nPlease input positive number!");

int main();
void cont();

int size = 0;
double data[100000];

// This function displays a message and waits for user input to continue.
void loop(){
	puts("\n-----------------------------------------------");
	printf("\nPress any key to continue . . . "); getch();
}

// This function displays a thank you message and exits the program.
void exitMessage(){
	system(clear);

	puts("**********************************************\n");
	puts("Terima kasih sudah menggunakan program saya :)\n\n ");
	puts("**********************************************");
	exit (0);
}

// This function displays the history of calculations.
void loadHistory(){
	system(clear);

	puts("~~~History~~~\n");
	for (int i = 0; i < size; i++){
		printf("Data number %d: %.2lf cm^2.", (i + 1), data[i]);
	}
	int j = size;
	printf("\nYou have performed calculations %d times.", j);

	loop();
	cont();
}

// This function calculates and displays the volume of a cylinder.
void cylinder(){
	system(clear);

	double rad, height;

	puts("===Cylinder Volume===\n");
	printf("Enter the radius of the cylinder: ");
	scanf ("%lf", &rad);
    printf("\nEnter the height of the cylinder: ");
	scanf("%lf", &height);

	size[data] = (PI * rad * rad * height);
	size++;

	if (rad > 0 && height > 0){
		printf ("\nCylinder's Volume = %.2lf cm^2\n", (PI * rad * rad * height));
	}
	else error

	loop();
	cont();
}

// This function calculates and displays the volume of a cone.
void cone(){
	system(clear);

    double rad, height;

	puts("===Cone Volume===\n");
	printf("Enter the radius of the cone: ");
	scanf ("%lf", &rad);
    printf("\nEnter the height of the cone: ");
	scanf("%lf", &height);

	size[data] = (PI * rad * rad * height) / 3;
	size++;

	if (rad > 0 && height > 0){
		printf ("\nCone's Volume = %.2lf cm^2\n", (PI * rad * rad * height) / 3);
	}
	else error

	loop();
	cont();
}

// This function calculates and displays the volume of a sphere.
void sphere(){
	system(clear);

	double rad, height;

	puts("===Sphere Volume===\n");
	printf ("Enter the radius of the sphere: ");
	scanf ("%lf", &rad);
    size[data] = (4 * PI * rad * rad) / 3;
	size++;

	if (rad > 0){
		printf("\nSphere's Volume = %.2lf cm^2\n", (4 * PI * rad * rad) / 3);
	}
	else error

	loop();
	cont();
}

// This function displays a menu for the user to continue, view history, or exit.
void cont(){
	system(clear);

	puts("Please choose the menu you'd like to go to.\n");
    puts("[1] Continue");
    puts("[2] History.");
    puts("[3] Exit.");
	printf("\nChoose : ");

	switch(getch()){
    	case '1' :
        	main();
			break;
    	case '2' :
			loadHistory();
			break;
		case '3' :
        	exitMessage();
	    	break;
	    default :
	    	printf("Invalid Input ! ");
			getch();
			cont();
	}
}

int main(){
	system(clear);

	puts("<<<Geometry Volume Calculator>>>");
	puts("\n{===3D shape===}\n");
	puts("[1] Cylinder");
	puts("[2] Cone");
	puts("[3] Sphere");
	printf("\nPlease select the 3D shape you desire: ");

	switch(getch()){
		case '1':
			cylinder();
			break;
		case '2':
			cone();
			break;
		case '3':
			sphere();
			break;
		default:
			printf("\nInvalid Input ! ");
			getch();
			main();
	}
	return 0;
}