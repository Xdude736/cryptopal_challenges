/*
 * Author: Xdude736
 * Program: hex2base64
 * Purpose: Given an input stream of hexidecimal values, with no spaces, convert it into properly formatted base64 output to the console
 * Algorithm: 
 *        1.) Read input as a command line argument
 *        2.) Take the input two characters at a time and map to the appropriate hex value i.e. '4' and '2' from the console becomes 0x42
 *        3.) Process the hex and perform bitwise operations on the raw bytes in order to get the appropriate bse64 values
 *        4.) Print the base64 output to the console
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char ctoh(char);
void toBase64(char,char,char, char*,int);

int main(int argc, char **argv){
	
	//Base64 encoding table: Each indicie corresponds to the decimal value generated by calulating the 6-bits of base64
	char b64[64] = {'A','B','C','D','E','F',
			'G','H','I','J','K','L',
			'M','N','O','P','Q','R',
			'S','T','U','V','W','X',
			'Y','Z','a','b','c','d',
			'e','f','g','h','i','j',
			'k','l','m','n','o','p',
			'q','r','s','t','u','v',
			'w','x','y','z','0','1',
			'2','3','4','5','6','7',
			'8','9','+','/'};

	if(argc == 1){
	  printf("please specify an argument\n");
	  return 0;
	}
    
	//Since 3 4bit hex are equal to 2 6bit base64 we have a 2 to 3 ratio. This means we multiply the size of the hex string
	//    by 2 and then divide it by three to calculate the size of the array we need for the base64 string, calculating for the
	//    remainder as needed
	int remainder = strlen(argv[1]) % 3;
	int SIZE = (((strlen(argv[1]) - remainder) * 2) / 3) + remainder;
	char *trueHex = malloc(sizeof(char) * strlen(argv[1]));
	char *base = malloc(sizeof(char) * SIZE);

	for( int i = 0; i < strlen(argv[1]); i++) {

		trueHex[i] = ctoh(argv[1][i]);
		if(trueHex[i] == -1)
			return -1;
		//printf("%.2x\n", trueHex[i]);
	}

	toBase64(trueHex[0],trueHex[1],trueHex[2],base,0);

    printf("%.2x : %.2x", base[0], base[1]);

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
		    printf("Invalid Character Conversion");
		    return -1;
	}
}

/*
 *Method: toBase64
 *Input: 3 hex values stored as characters. We only care about the last four bits of each character i.e. 0x0F we care about F.
 *    We also have a character array pointer passed in. Integer denoting if padding is needed or not
 *Output: None. The values are stored in the character array that is passed by reference as a parameter
 *Purpose: given 3 hex values we calculate the two corresponding base54 values
 */
 void toBase64(char x, char y, char z, char *arr, int pad){
	 
	char c1 = (x << 2) | ((y >> 2) & 0x3F);
	char c2 = (y << 4)  | (z & 0x3F);

    strcat(arr, &c1);
    if(pad == 1){
        c2 = '=';
    }
    
    strcat(arr, &c2);
 }
