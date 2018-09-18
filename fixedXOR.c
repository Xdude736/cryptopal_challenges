/*
 * Author: Xdude736
 * Program: fixedXOR
 * Purpose: given two inputs of equal length hex values, xor them together and print out the output
 * Algorithm:
 * 			1.) check that inputs are of equal length and that it is modulo 2 (to allow for proper hex conversion)
 *			2.) convert the input into hex values and save those hex values
 *			3.) go through both arrays and xor each character at the current position, printing the output to the console
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ctoh(char);

 int main(int argc, char **argv){
	 
	 if( strlen(argv[1]) != strlen(argv[2]) && strlen(argv[1]) % 2 == 0){
		 printf("\nPlease use two equal length strings. String length should be a multiple of 2.\n");
		 return 1;
	 }
	 
	 printf("\n\n");
	 char *hexOne = malloc(sizeof(char) * strlen(argv[1]));
	 char *hexTwo = malloc(sizeof(char) * strlen(argv[2]));
	 
	 int count = 0;
	 for(int i = 0; i < strlen(argv[1]); i += 2){
		 char c1 = ctoh(argv[1][i]);
		 c1 = c1 << 4;
		 //printf("%.2x\n", c1);
		 char c2 = ctoh(argv[1][i+1]);
		 //printf("%.2x\n", c2);
		 hexOne[count] = c1 | c2;
		 
		 char c3 = ctoh(argv[2][i]);
		 c3 = c3 << 4;
		 //printf("%.2x\n", c3);
		 char c4 = ctoh(argv[2][i+1]);
		 //printf("%.2x\n", c4);
		 hexTwo[count] = c3 | c4;
		 
		 char xord = hexOne[count] ^ hexTwo[count];
		 printf("%.2x", xord);
		 //printf("%.2x\n", hexOne[count]);
		 //
		 //printf("%.2x\n", hexTwo[count]);
		 count++;
	 }
	 
	 return 0;
 }
 
 /*
 *Method: ctoh
 *Input: the character to be converted
 *Output: the hex value as a character (8bits)
 *Purpose: Converts an ascii character, such as '4', to the logical hex value, i.e. 0x04
 *    Only works for char 1-9, a-fA-F
 */
char ctoh(char convert)
{
	
    switch(convert){
		case '0':
			return 0x00;
		case '1':
		    return 0x01;
		case '2':
		    return 0x02;
		case '3':
		    return 0x03;
		case '4':
		    return 0x04;
		case '5':
		    return 0x05;
		case '6':
		    return 0x06;
		case '7':
		    return 0x07;
		case '8':
		    return 0x08;
		case '9':
		    return 0x09;
		case 'a':
		    return 0x0A;
		case 'A':
		    return 0x0A;
		case 'b':
		    return 0x0B;
		case 'B':
		    return 0x0B;
		case 'c':
		    return 0x0C;
		case 'C':
		    return 0x0C;
		case 'd':
		    return 0x0D;
		case 'D':
		    return 0x0D;
		case 'e':
		    return 0x0E;
		case 'E':
		    return 0x0E;
		case 'f':
		    return 0x0F;
		case 'F':
		    return 0x0F;
		default:
		    printf("Invalid Character Conversion: %c", convert);
		    return -1;
	}
}