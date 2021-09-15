#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// standard english character frequencies to be printed as a reference
#define afreq 8.34
#define bfreq 1.54
#define cfreq 2.73
#define dfreq 4.14
#define efreq 12.6
#define ffreq 2.03
#define gfreq 1.92
#define hfreq 6.11
#define ifreq 6.71
#define jfreq 0.23
#define kfreq 0.87
#define lfreq 4.24
#define mfreq 2.53
#define nfreq 6.8
#define ofreq 7.7
#define pfreq 1.66
#define qfreq 0.09
#define rfreq 5.68
#define sfreq 6.11
#define tfreq 9.37
#define ufreq 2.85
#define vfreq 1.06
#define wfreq 2.34
#define xfreq 0.2
#define yfreq 2.04
#define zfreq 0.06

int* frequency(char text[], int abc[]);

int print_graph(int abc[]);

int main(int argc, char *argv[]) {
	// cast standard frequencies to ints and compile into an array
	int standard_freqs[26] = {afreq, bfreq, cfreq, dfreq, efreq, ffreq, gfreq, hfreq, ifreq, jfreq, kfreq, lfreq, mfreq, nfreq, ofreq, pfreq, qfreq, rfreq, sfreq, tfreq, ufreq, vfreq, wfreq, xfreq, yfreq, zfreq};
	/* arguments:
	[0] program call
	[1] frequency to be analyzed */
	if (argc != 2) {
		printf("2 arguments required\n");
		return 0;
	}
	/* abc used to store frequency of each character.
	Each ascii character corresponds to an index in abc, where 'a' is abc[0].
	To get this you subtract 'a' from whatever character you have and that gets you the index. */
	// allocate memory for 26 integers and initialize to 0, create an int pointer at the start of the allocated memory
	int* abc = calloc(26, sizeof(int));
	// run frequency algorithm and assign results to abc
	abc = frequency(argv[1], abc);

	// create and open file for output
	FILE *out;
	out = fopen(".frequency_out", "w");
	// print output to file
	for (int i=0; i<26; i++) {
		fprintf(out, "%d ", abc[i]);
	}
	fclose(out);

	// print graphs of standard frequencies and results side by side to compare visually
	print_graph(standard_freqs);
	printf("\n");
	print_graph(abc);
	printf("\n");
	return 0;
}

int* frequency(char text[], int abc[]) {
	// total number of characters
	int total = strlen(text);
	char c;
	// to start, abc used to store total quantities of each character. then those will be converted to percentages
	for (int i=0; i<total; i++) {
		c = text[i];
		// add one to character quantity
		abc[c-'a']++;
	}
	// quantity
	float q;
	// percentage
	float p;
	// calculate percentages
	for (int i=0; i<26; i++) {
		q = abc[i];
		p = (q / total) * 100;
		abc[i] = (int)p;
	}
	// abc now stores frequency percentages of each character
	return abc;
}

int print_graph(int abc[]) {
	// simple bar graph of each character frequency
	printf("  0    5    10   15\n  |    |    |    |\n");
	for (int i=0; i< 26; i++) {
		printf("%c: ", (char)i+'a');
		for (int n=0; n<abc[i]; n++) {
			printf(".");
		}
		printf("\n");
	}
}
