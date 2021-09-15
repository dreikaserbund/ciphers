#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int main() {
	// cast standard frequencies to ints and compile into an array
	int standard_freqs[26] = {afreq, bfreq, cfreq, dfreq, efreq, ffreq, gfreq, hfreq, ifreq, jfreq, kfreq, lfreq, mfreq, nfreq, ofreq, pfreq, qfreq, rfreq, sfreq, tfreq, ufreq, vfreq, wfreq, xfreq, yfreq, zfreq};

	FILE *fp;
	int freqs[26];

	fp = fopen(".frequency_out", "r");

	for (int i=0; i<26; i++) {
		fscanf(fp, "%d", &freqs[i]);
	}

	fclose(fp);

	return 0;
}

