/*  Current goals of this program as specified by the document      |
    is as follows:                                                  |
    1. Encypt a message with a function using a key from a file     |
       which will also be written to a file.                        |
    2. Do the reverse of point 1.                                   |
    3. Encypt with a substaution chipher with a message and key     |
    4. do the reverse of 3.                                         |
    5. Decypt a message that is encypted with rotation cypher       |
       without the key. AKA Break the code.                         |
    6. Do the same with 5 but with a sub encyption.                 |
*/
/*  Things to know:                                                 |
                >Each task should be done by a FUNCTION             |
                >The user input will be taken from a file           |
                >The file will be formated as a single int          |
                 on line one for the option that will be done       |
                 the second line will contain the key given as      |
                 an int. The third line will be the message.        |
                                                                    |
                >What should be done with the white spaces?         |
                >What if the message includes numerals?             |
                >Should upper and lowercase be handled diffrently?  |
                >Do not encypt grammar, spaces or numbers.          |
                >All the message will be in ASCII uppercase.        |
                
                >Key format will be from the set of [0,25]
                >The sub key will be a string of 26 letters
                >If the letter is a lower case then subtract 32
*/
#include <stdio.h>

int encypt(void)    //function proto to encypt messages
int decypt(void)    //function proto to decypt messages
int attack1(void)   //function proto to attack shift cyph
int attack2(void)   //function proto to attack scram cyph

int main ()
{
    int sel, key, tmp;
    
    /* open file in */
   FILE *Fopen(const char *in.txt, const char 'r');
    /* open file out*/
   FILE *Fopen(const char *out.txt, const char 'r+');
    /* read file for required function */
    /* go to proper function */
    /* function1, encypt stuff */
        /* while loop until the end of file */
        /*  read file for letter
            rotate the letter by the key
            check if it is in the ASCII limits
            if not then call a fix function
            else continue
            store the result into an array
            repeat the while loop
        */
    /* Print the array to an out file */
    
    
    
    return 0;
}