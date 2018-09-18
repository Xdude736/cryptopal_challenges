/*
 * Author: Xdude736
 * Program: singleByteXOR
 * Purpose: given an input string representing hex, find the single byte character value that decrypts the message by using a form of
 *     frquency scoring.
 * Algorithm:
 *			1.) Given a hex string, read in the correct hex values and store them into an array, i.e. '1234' becomes 0x12 and 0x34
 *			2.) For each possible ascii character: xor the input string and then walk through it counting the frequency of
 *				characters from a list(the most common characters in the english language) which will create the score for that ascii
 *				character. Store the score in an array position that corresponds to a characters decimal value
 *			3.) Traverse the score array and find which character has the highest score.
 *			4.) Print out the plaintext from xoring the key character with the input string.
 */