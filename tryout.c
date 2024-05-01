//FIX THIS ONE'S ERRORS
//project4.c 
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


// soz daxil edilsin  +
// sozun uzunlugu tapilsin  +
// sozun uzunluguna uygun '---'cap edilsin ve arrayin icine yigilsin ++ve gosterildi
// sozun uzunlugu sayda user'den input letter teleb edilsin(loop'da)    +
// her user input daxil etdikde sozun icinde olub olmadigi yoxlansin    +
// if varsa, arrayin hemin elementi inputla deyisdirilsin ve printf("congrats") olsun       +
// else printf("continue, this one is false") olsun +



//attemps sayi gosterilsin

int main()
{
    
    char word[20];
    printf("enter a word (max 20 letters): ");
    scanf("%s", &word);
    int length = strlen(word);
    char arr[length];
    int attempts=length;
    for (int i = 0; i < length; i++)
    {
        arr[i] = '-';
    }
    for (int j = 0; j < strlen(word); j++)
    {
        printf("%c ", arr[j]);
    }

    //sozun uzunlugu sayda userden input telebi
    for(int k=0;k<length;k++){
        char character;
        printf("Enter a char: ");
        scanf(" %c",&character);
            
            attempts--;
            // input olunan chari yoxlayir
            int indices[20];
            for(int i=0; i<20; ++i) indices[i] = -1;
            int t = 0;
        for(int l=0;l<length;l++){
            if (character==word[l]){
                indices[t++] = l;
                // arr[l]=character;
                
                //  printf("CONGRATS! Found letters:%c\nYou have %d attempts.",arr[l],attempts);
                 
            }
            // else{
            //     printf("You failed, continue to guess..You got %d attempts left",attempts);
            // }
  
        }
       
                
            
        

    }
    return 0;
}
