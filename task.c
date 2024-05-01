/*1) 
1 2 3 4 5 6 
1 2 3 4 5 6
1 2 3 4 5 6
1 2 3 4 5 6
1 2 3 4 5 6
1 2 3 4 5 6

2) 
6 5 4 3 2 1 
6 5 4 3 2 1
6 5 4 3 2 1
6 5 4 3 2 1
6 5 4 3 2 1
6 5 4 3 2 1

3) 
6 
6 5
6 5 4
6 5 4 3
6 5 4 3 2
6 5 4 3 2 1
-------------------------------
4)
6 5 4 3 2 1 
6 5 4 3 2
6 5 4 3
6 5 4
6 5
6

5) 
1 2 3 4 5 6 
7 8 9 10 11 12
13 14 15 16 17 18
19 20 21 22 23 24
25 26 27 28 29 30
31 32 33 34 35 36


6) 
36 35 34 33 32 31 
30 29 28 27 26 25
24 23 22 21 20 19
18 17 16 15 14 13
12 11 10 9 8 7
6 5 4 3 2 1

7)
1 2 3 4 5 6 ---> cem: 21
7 8 9 10 11 12 ---> cem: 57
13 14 15 16 17 18 ---> cem: 93
19 20 21 22 23 24 ---> cem: 129
25 26 27 28 29 30 ---> cem: 165
31 32 33 34 35 36 ---> cem: 201


8) 300den baslayir 5-5 azalir
300 295 290 285 280 275 ---> ortalama: 287
270 265 260 255 250 245 ---> ortalama: 257
240 235 230 225 220 215 ---> ortalama: 227
210 205 200 195 190 185 ---> ortalama: 197
180 175 170 165 160 155 ---> ortalama: 167
150 145 140 135 130 125 ---> ortalama: 137
*/


#include <stdio.h>

//1)
/*
 int main(){
    int count=1;
    for(int i =1;i<7;i++){
        for(int j=1;j<7;j++){
            printf("%d ",count);
            count++;
        }
        count=1;
        printf("\n");
    }


    return 0;

 }
*/


 //2)
 /*
int main(){

int count=6;
    for(int i =1;i<7;i++){
        for(int j=1;j<7;j++){
            printf("%d ",count);
            count--;
        }
        count=6;
        printf("\n");
    }

    return 0;

}

*/

//3)
/*
int main(){
    int count=6;
    for(int i =1;i<7;i++){
        for(int j=1;j<=i;j++){
            printf("%d ",count);
            count--;
        
        }
        count=6;
        printf("\n");
    }




    return 0;
}
*/
//4)
int main(){
    int count=6;
    for(int i = 1; i <= 6; i++){
        for(int j=i; j >= 1; j--){
    
           printf("%d ",count);
           count--;
        
       }
       
       printf("\n");
        count = i;
    }




    return 0;

}





