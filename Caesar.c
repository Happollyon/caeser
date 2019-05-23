#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, string argv[])
{   string d;
     int key;
    bool valid =false;
    // check how many arguments has been inputed
    // it has to be 2 first is the prog name, second is the arg
     if (argc>2)//more than two
     {     valid = false;
         
     }else if(argc<2)// less than 2
     {     valid = false;
          
     }else // case is 2 
     {     d = argv[1]; //passes the second string in the array to a seprate variable 
          for(int i = 0; i<strlen(d); i++)//gets the number of caractheres in the string D 
          {
              int c = (int) d[i]; //conversts each char to a int (ascII) value
             // printf("%i \n" ,c);
              if (c<48 || c>57)// tests if the char is a digit 
              {   valid = false;
                  //printf("Usage: ./caesar key\n");
              }else{ 
                      key= atoi(d);
                      valid = true;
                  }
          }
     }
 //if key is valied and true 
 if (valid == true)
 {
     string text = get_string("plaintext: "); // asks for input
     printf("ciphertext: ");
     for  (int i = 0; i<strlen(text); i++) //travels across characters
     {
         int c = (int) text[i]; //converst to digits
         int s = c + key;  // shifts key character withe key
         char s2; // variable in this scope
         if(c > 64 && c < 90) //if Caracter upper case
         {  
             if(s < 90 ) //if doesnt leave the upper group
             {
              s2 = (char) s; // converts back to char
             printf("%c" ,s2); // outputs it 
             }else // case the key plus the char leave the group
             {
                 while ( s > 90) // loop that holds it in to the upper case
                 {
                     s = s - 90;
                     s = s + 64   ; 
                 }
                 s2 = (char) s; // converts it back to char
                printf("%c" ,s2);
             }
                 
             
              
         }
         
         else if(c > 96 && c < 123) //if Caracter lower case
         {  
             if(s < 123 ) //if doesnt leave the upper group
             {
              s2 = (char) s; // converts back to char
             printf("%c" ,s2); // outputs it 
             }else // case the key plus the char leave the group
             {
                 while ( s > 122) // loop that holds it in to the upper case
                 {
                     s = s - 122;
                     s = s + 96  ; 
                 }
                 s2 = (char) s; // converts it back to char
                printf("%c" ,s2);
             }
                 
             
              
         }else 
             {
                 s2 = (char) c;
                 printf("%c" ,s2);
                 
             }
     }printf("\n");
 }else if (valid==false)
 {
     printf("Usage: ./caesar key\n");
 }
 return 0;
}

