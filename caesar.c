#include <stdio.h>
#include <string.h>
#include <math.h>

// input buffer length
#define MAX 50

char* cipher(int key, char text[]);

int main() {
	// get text to be encrypted/decrypted
	char buf[MAX];
	printf("Enter text:  ");
	fgets(buf, MAX, stdin);

	// get cryptographic key
	int key;
	printf("Enter key:  ");
	scanf("%d", &key);

	// to encrypt, use a positive key, to decrypt, use a negative key
	printf("%s\n", cipher(key, buf));
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

