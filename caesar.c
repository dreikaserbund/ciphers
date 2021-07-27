#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// input buffer length
#define MAX 50

char* cipher(int key, char text[]);

int main(int argc, char *argv[]) {
/*
	// get text to be encrypted/decrypted
	char buf[MAX];
	printf("Enter text:  ");
	fgets(buf, MAX, stdin);

	// get cryptographic key
	int key;
	printf("Enter key:  ");
	scanf("%d", &key);
*/
	// Expected args:
	// [0] program call
	// [1] key
	// [2] text
	if (argc != 3) {
		printf("3 arguments required\n");
		return 0;
	}
	// get key and convert to int
	int key = atoi(argv[1]);

	// open a file to store output
	FILE *out;
	out = fopen("caesar_out", "w");
	// to encrypt, use a positive key, to decrypt, use a negative key
	// print result to output file
	fprintf(out, "%s\n", cipher(key, argv[2]));
	fclose(out);
}

char* cipher(int key, char text[]) {
	// placeholder char for text[i] to improve readability
	char c;
	// loop over every character in the string
	for (int i = 0; i < strlen(text); i++) {
		// test if character is in lowercase alphabet, otherwise don't encrypt
		if ('a' <= text[i] && text[i] <= 'z') {
			// this should all be equivalent to
			// c = ((c - 'a') + key) mod 26 + 'a'
			// but c only has a remainder(%) operator no modulo
			c = text[i];
			c = (c - 'a') + key;
			// add 26 to c until it's positive, to mimic modulo behavior on negatives
			for (c; c < 0; c += 26) {}
			c = c % 26 + 'a';
			text[i] = c;
		}
	}
	return text;

}

