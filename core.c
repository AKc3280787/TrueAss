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

//int ecsh(int key)    //function proto to encypt messages
//int dcsh(int key)    //function proto to decypt messages

int main ()
{
    FILE *fin;
    FILE *fout;
    int sel, key;
    
    /* open file in */
   fin = fopen("in.txt", "r");
   fscanf(fin, "%d", &sel);
   printf("%d", sel);
    /* open file out*/
   fout = fopen("out.txt", "w");
   fprintf(fout, "You have selected function %d\n", sel);
   
   switch(sel)
   {
       case 1:
       //this will be the encypt function
       break
       
       case 2:
       //this will be the decypt function
       break
       
       case 3:
       //this will be the encypt with the sub function
       break
       
       case 4:
       //this will be the decypt with the sub function
       break
       
       case 5:
       //this will be the attack funtion for the shift
       break
       
       case 6:
       //this will be the attack function for the sub
       break
   }

    return 0;
}

int ecsh(int key)
{
    
    
    return 0;
}