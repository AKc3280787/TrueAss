/*  Current goals of this program as specified by the document      |
    is as follows:                                                  |
    1. Encypt a message with a function using a key from a file     |
       which will also be written to a file.                        |
    2. Do the reverse of point 1.                                   |
    3. Encypt with a substaution chipher with a message and key     |
    4. do the reverse of 3.                                         |
    5. Decypt a message that is encypted with rotation cypher       |
       without the key. AKA Break the code.                         |
    6. Do the same with 5 but with a sub encyption.                */
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
                                                                    |
                >Key format will be from the set of [0,25]          |
                >The sub key will be a string of 26 letters         |
                >If the letter is a lower case then subtract 32     |
                                                                  */
#include <stdio.h>
FILE *fin;
FILE *fout;


int ecsh(int key);  //function proto to encypt messages
int cap(char r);    //function that capitlizes letters if they are lowercase.
int dcsh(int key);  //function proto to decypt messages
int wrapZ(char p);  //function that will take a charcter after the key has been subtracted and wrap it up back to z area
int wrapA(char p);  //function that will take a character after the key has been added and wrap it up back to A area
int ecsub(void);    //function that will encypt messages via substatuition
int dcsub(void);    //function that will decypt messages via substatution

int main ()
{
    int sel, key, tmp;
    
    
    /* open file in */
   fin = fopen("in.txt", "r");
   fscanf(fin, "%d", &sel);
   fscanf(fin, "%d", &key);
   fclose(fin);
     
   switch(sel)
   {
       case 1:
       tmp = ecsh(key);
       break;
       
       case 2:
       //this will be the decypt function
       tmp = dcsh(key);
       break;
       
       case 3:
       ecsub();
       break;
       
       case 4:
       //this will be the decypt with the sub function
       dcsub();
       break;
       
       case 5:
       //this will be the attack funtion for the shift
       break;
       
       case 6:
       //this will be the attack function for the sub
       break;
   }

    return 0;
}
/* -------------------------------------------------------------- */
int ecsh(int key)
{
    char r, p, t;               //r for character read, p for what is to be printed and t for any temp character storage
    char array[1400];            //array to store output, maybe not needed
    int n, tmp;                 //n for counter, tmp needed for anything that is not required as a result
    n = 0;
    p = 0;
    r = 1;
    fin = fopen("in.txt", "r");

    
    while( EOF != 0 )           //starting a loop to read the file
    {
        if (n == 1400)          //hard break to stop any overflow or breaking of the array
        {
            fout = fopen("out.txt", "w");
            fwrite(array, sizeof(char), sizeof (array), fout);
            fclose(fout);
        
            return 0;
        }
        else
        {
            fscanf(fin, "%c", &r);
            if (r >= 65 && r <= 90)     //if already a cap it will have the key applied
            {
                char p = r + key;
                if (p >= 91)            //if it breaks past Z into unknown ascii letters it will be wrapped back around
                {
                    tmp = wrapA(p);
                    array[n++] = tmp;
                }
                else
                {
                    array[n++] = p;     //if the read character meets non of the above it will be printed as is
                }

            }
            else
            {
                if (r >= 97 && r <= 122)    //if the letter is lowercase then it will be converted to an uppercase before being proccessed
                {
                    t = cap(r);
                    char p = t + key;
                    if ( p >= 91)       //if it breaks past Z into unknown ascii letters it will be wrapped back around
                    {
                        tmp = wrapA(p);
                        array[n++] = tmp;
                    }
                    else
                    {
                        array[n++] = p;
                    }
                 }
                else
                {
                    array[n++] = p;
                }
            }
        }
    }
}
/* -------------------------------------------------------------- */
int cap(char r)
{
    char tmp0;
    tmp0 = r - 32;
    return tmp0;
    
}
/* -------------------------------------------------------------- */
int dcsh(int key)
{
    char r, p, t;
    char array[140];
    int n, tmp;
    n = 0;
    p = 0;
    r = 1;
    fin = fopen("in.txt", "r");

    
    while( EOF != 0 )
    {
        if (n == 140)
        {
            fout = fopen("out.txt", "w");
            fwrite(array, sizeof(char), sizeof (array), fout);
            fclose(fout);
        
            return 0;
        }
        else
        {
            fscanf(fin, "%c", &r);
            if (r >= 65 && r <= 90)
            {
                char p = r - key;
                if (p <= 64)
                {
                    tmp = wrapZ(p);
                    array[n++] = tmp;
                }
                else
                {
                    array[n++] = p;
                }        
            }
            else
            {
                if (r >= 97 && r <= 122)
                {
                    t = cap(r);
                    char p = t - key;
                    if ( p <= 64 )
                    {
                        tmp = wrapZ(p);
                        array[n++] = tmp;
                    }
                    else
                    {
                        array[n++] = p;
                    }
                }
                else
                {
                    array[n++] = p;
                }
            }
        }
    }
}
/* -------------------------------------------------------------- */
int wrapZ(char p) //function will wrap the keyed character from Z down to A
{
    int tmp, r;
    
    tmp = 90 - p;
    r = 40 + tmp;
    
    return (r);
}
/* -------------------------------------------------------------- */
int wrapA(char p) //function will wrap the keyed character from A up to Z
{
    int tmp, r;
    tmp = p - 90;
    r = 64 + tmp;
    
    return (r);
}
/* -------------------------------------------------------------- */
int ecsub(void){
    char key[2][26], tmpC = 0, a = 65;                           //to store the alphabet in one row and the key in the next.
    int i = 0, tmp;                                             //rt for the row in table / colum in table / i for counter / tmp for throw away.
    char r;
    
    fin = fopen("in.txt", "r");
    fout = fopen("out.txt", "a+");
    fscanf(fin, "%d\n", &tmp);                                   //takes the "selection" number and throws it
    
    tmp = 0;
    for(i = 0; i <= 25; i++) {                                   //fills the first row with ABC... to Z
       tmpC = a + i;
       key[0][i] = tmpC;
    }
    
    for (i = 0; i<=25; i++) {                                    //loop will read the key and assign it to row 2 to be called
        fscanf(fin, "%c", &key[1][i]);       
    }
    
    for (i = 0; i <=25; i++) {                                  //loop will print the alphabet to the file
        fprintf(fout, "%c", key[0][i]);
    }
    fprintf(fout,"\n%s\n", "--------------------------");       //will take a new line and add ascii art
    for (i = 0; i <=25; i++) {                                  //will print the read key
        fprintf(fout, "%c", key[1][i]);
    }
    fprintf(fout, "\n%s\n", " ");
   while (1) {                                                  //starting a loop to break if EOF is reached
        i = 0;
        r = fgetc(fin);                                         //Reading the file chracter to encypt
        if ( feof(fin) ) {                                      //if EOF break operations
            break;
        }
        if (r >= 97 && r <= 122) {                              //converts it to a cap if it is read as a lowercase
            tmp = r - 32;
            r = tmp;
        }
        if (r >= 65 && r <= 90) {
            while (r != key[0][i] && i < 25) {                  //if the characters DO NOT match then it will move onto the next OR while i <= 25
                i++;
            }
            fprintf(fout, "%c", key[1][i]);
        }
        else {
            fprintf(fout, "%c", r);
        }
    }
    fprintf(fout, "\n");
    fclose(fin);
    fclose(fout);
    
    return 0;
}
/* -------------------------------------------------------------- */
int dcsub(void){
    char key[2][26], tmpC = 0, a = 65;                           //to store the alphabet in one row and the key in the next.
    int i = 0, tmp;                                             //rt for the row in table / colum in table / i for counter / tmp for throw away.
    char r;
    
    fin = fopen("in.txt", "r");
    fout = fopen("out.txt", "a+");
    fscanf(fin, "%d\n", &tmp);                                   //takes the "selection" number and throws it
    
    tmp = 0;
    for(i = 0; i <= 25; i++) {                                   //fills the first row with ABC... to Z
       tmpC = a + i;
       key[1][i] = tmpC;
    }
    
    for (i = 0; i<=25; i++) {                                    //loop will read the key and assign it to row 2 to be called
        fscanf(fin, "%c", &key[0][i]);       
    }
    
    for (i = 0; i <=25; i++) {                                  //loop will print the alphabet to the file
        fprintf(fout, "%c", key[0][i]);
    }
    fprintf(fout,"\n%s\n", "--------------------------");       //will take a new line and add ascii art
    for (i = 0; i <=25; i++) {                                  //will print the read key
        fprintf(fout, "%c", key[1][i]);
    }
    fprintf(fout, "\n%s\n", " ");
   while (1) {                                                  //starting a loop to break if EOF is reached
        i = 0;
        r = fgetc(fin);                                         //Reading the file chracter to encypt
        if ( feof(fin) ) {                                      //if EOF break operations
            break;
        }
        if (r >= 65 && r <= 90) {
            while (r != key[0][i] && i < 25) {                  //if the characters DO NOT match then it will move onto the next OR while i <= 25
                i++;
            }
            fprintf(fout, "%c", key[1][i]);
        }
        else {
            fprintf(fout, "%c", r);
        }
    }
    fprintf(fout, "\n");
    fclose(fin);
    fclose(fout);
    
    return 0;
}
