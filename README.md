# cryptopal_challenges
These are my solutions to the cryptopals challenges

SET_1_CHALLENGE_1: HEX TO BASE64

  I chose to work with the char data type in C, since this allows for 8-bits. For the hex characters we only need 4-bits and for the base64 for we need 6-bits, which makes the 8-bit char optimal for the storage. For this challenge we need to use left and right bit shifts along with bitwise 'or' and 'and'. Below is an example of how the three 4-bit hex values are combined to make the two 6-bit base64 values:
  
    0x01      0x02      0x03
  0 0 0 1 | 0 0 1 0 | 0 1 1 0
               |
               v
   0 0 0 1 0 0 | 1 0 0 1 1 0
       0x04        0x16
      
    Because we are working with chars, which are 8-bit, it works a little bit(ha!) diferrently: 
         0x01             0x02              0x03
  0 0 0 0 0 0 0 1 | 0 0 0 0 0 0 1 0 | 0 0 0 0 0 1 1 0
                           |
                           v
           0 0 0 0 0 1 0 0 | 0 0 1 0 0 1 1 0
                 0x04              0x16
                 
Here's how it works:
  * To get base64 character 1 we need:
    - The last four bits of hex 1 (0001) or'd with the first two bits from hex 2 (00). To do this in C we have : 
      ((hex1 << 2) | (hex2 >> 2)) & 3F;
    - This shifts hex1 to the left by two places (00000100) and hex2 to the right two places (00000000) then or them together (00000100),
    - Then 'and' it with 3F(00111111) which effectively keeps the first two bits cleared
  * To get base64 character 2 we need:
    - The last two bits of hex2 (10) or'd with the last four bits of hex3 (0110). To do this in ce we have: 
      ((hex2 << 4) | hex3)  & 0x3F;
    - This shifts hex2 four places to the left (00100000) and 'or' it with hex3 (00000110) which gives us (00100110)
    - Then 'and' it with 3F(00111111) which effectively keeps the first two bits cleared
  * This generates two decimal values that can be used with a corresponding base64 encoding table to find and print the corresponding           character
  
  Note how we always keep the highest bits valued at 0 (00xxxxxx) since the most bits we ever use are 6 bits.
