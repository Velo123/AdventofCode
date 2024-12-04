/*
--- Day 4: Ceres Search ---

"Looks like the Chief's not here. Next!" One of The Historians pulls out a device and pushes the only button on it. After a brief flash, you recognize the interior of the Ceres monitoring station!

As the search for the Chief continues, a small Elf who lives on the station tugs on your shirt; she'd like to know if you could help her with her word search (your puzzle input). She only has to find one word: XMAS.

This word search allows words to be horizontal, vertical, diagonal, written backwards, or even overlapping other words. It's a little unusual, though, as you don't merely need to find one instance of XMAS - you need to find all of them. Here are a few ways XMAS might appear, where irrelevant characters have been replaced with .:

..X...
.SAMX.
.A..A.
XMAS.S
.X....

The actual word search will be full of letters instead. For example:

MMMSXXMASM
MSAMXMSMSA
AMXSXMAAMM
MSAMASMSMX
XMASAMXAMM
XXAMMXXAMA
SMSMSASXSS
SAXAMASAAA
MAMMMXMMMM
MXMXAXMASX

In this word search, XMAS occurs a total of 18 times; here's the same word search again, but where letters not involved in any XMAS have been replaced with .:

....XXMAS.
.SAMXMS...
...S..A...
..A.A.MS.X
XMASAMX.MM
X.....XA.A
S.S.S.S.SS
.A.A.A.A.A
..M.M.M.MM
.X.X.XMASX

Take a look at the little Elf's word search. How many times does XMAS appear?

Your puzzle answer was 2646.
--- Part Two ---

The Elf looks quizzically at you. Did you misunderstand the assignment?

Looking for the instructions, you flip over the word search to find that this isn't actually an XMAS puzzle; it's an X-MAS puzzle in which you're supposed to find two MAS in the shape of an X. One way to achieve that is like this:

M.S
.A.
M.S

Irrelevant characters have again been replaced with . in the above diagram. Within the X, each MAS can be written forwards or backwards.

Here's the same example from before, but this time all of the X-MASes have been kept instead:

.M.S......
..A..MSMS.
.M.S.MAA..
..A.ASMSM.
.M.S.M....
..........
S.S.S.S.S.
.A.A.A.A..
M.M.M.M.M.
..........

In this example, an X-MAS appears 9 times.

Flip the word search from the instructions back over to the word search side and try again. How many times does an X-MAS appear?

Your puzzle answer was 2000.
*/


#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int Check_surroundings(char** data, int i, int j);
int Check_surroundings2(char** data, int i, int j);

int main(int argc, char *argv[]){
    
    if (argc != 2)
    {
        printf("Insert input arguments\n");
        return -1;
    }
    

    FILE *ifp = fopen(argv[1],"r");
    if(ifp==NULL){
        printf("Couldn't open input file %s\n",argv[2]);
        exit(EXIT_FAILURE);
    }

    char** data=(char**)malloc(140*sizeof(char*));
    for (int i = 0; i < 141; i++)
    {
        data[i]=(char*)malloc(140*sizeof(char));
    }
    int counterl=0;
    int counterc=0;

    //Import data of file
    do{     
        char buffer=fgetc(ifp);
        if (buffer=='\n')
        {
            counterl++;
            counterc=0;     
            
        }
        else{   
            data[counterl][counterc]=buffer;
            counterc++;
            
        }
    }while(!feof(ifp));
    
    int XMAS_counter=0;
    for (int i = 0; i < 141; i++)
    {
        for (int j = 0; j < 141; j++)
        {       
            if (data[i][j]=='A')
            {
                XMAS_counter=XMAS_counter+Check_surroundings2(data,i,j);     
            }
            
               
        }
    }
    
    for (int i = 0; i < 141; i++)
    {
        free(data[i]);
    }
    free(data);
    


    printf("XMAS total: %d\n",XMAS_counter);
    
    return 0;
}



/*
    Scan surroundings
    For each position in the vector we will analyse it's surroundings
*/
int Check_surroundings(char** data, int i, int j){
    char buffer[5]={0};
    int check_counter=0;
    //Check forward
    if (j<=137)
    {
        buffer[0]=data[i][j];
        buffer[1]=data[i][j+1];
        buffer[2]=data[i][j+2];
        buffer[3]=data[i][j+3];
        buffer[4]='\0';
        if (strcmp(buffer,"XMAS")==0){check_counter++;}
    }
    //Check backward
    if (j>=3)
    {
        buffer[0]=data[i][j];
        buffer[1]=data[i][j-1];
        buffer[2]=data[i][j-2];
        buffer[3]=data[i][j-3];
        buffer[4]='\0';
        if (strcmp(buffer,"XMAS")==0){check_counter++;}
    }

    //Check upward
    if (i>=3)
    {
        buffer[0]=data[i][j];
        buffer[1]=data[i-1][j];
        buffer[2]=data[i-2][j];
        buffer[3]=data[i-3][j];
        buffer[4]='\0';
        if (strcmp(buffer,"XMAS")==0){check_counter++;}
    }

    //Check downward
    if (i<=137)
    {
        buffer[0]=data[i][j];
        buffer[1]=data[i+1][j];
        buffer[2]=data[i+2][j];
        buffer[3]=data[i+3][j];
        buffer[4]='\0';
        if (strcmp(buffer,"XMAS")==0){check_counter++;}
    }

    //Check diagonal 1
    if (i>=3 && j>=3)
    {
        buffer[0]=data[i][j];
        buffer[1]=data[i-1][j-1];
        buffer[2]=data[i-2][j-2];
        buffer[3]=data[i-3][j-3];
        buffer[4]='\0';
        if (strcmp(buffer,"XMAS")==0){check_counter++;}
    }

    //Check diagonal 2
    if (i>=3 && j<=137)
    {
        buffer[0]=data[i][j];
        buffer[1]=data[i-1][j+1];
        buffer[2]=data[i-2][j+2];
        buffer[3]=data[i-3][j+3];
        buffer[4]='\0';
        if (strcmp(buffer,"XMAS")==0){check_counter++;}
    }

    //Check diagonal 3
    if (i<=137 && j<=137)
    {
        buffer[0]=data[i][j];
        buffer[1]=data[i+1][j+1];
        buffer[2]=data[i+2][j+2];
        buffer[3]=data[i+3][j+3];
        buffer[4]='\0';
        if (strcmp(buffer,"XMAS")==0){check_counter++;}
    }

    //Check diagonal 4
    if (i<=137 && j>=3)
    {
        buffer[0]=data[i][j];
        buffer[1]=data[i+1][j-1];
        buffer[2]=data[i+2][j-2];
        buffer[3]=data[i+3][j-3];
        buffer[4]='\0';
        if (strcmp(buffer,"XMAS")==0){check_counter++;}
    }
    return check_counter;
}


int Check_surroundings2(char** data, int i, int j){
    char buffer[4]={0};
    int check_counter=0;

    //Check horizontal
    /*if(j>=1 && j<=139){
        buffer[0]=data[i][j-1];
        buffer[1]=data[i][j];
        buffer[2]=data[i][j+1];
        buffer[3]='\0';
        if (strcmp(buffer,"MAS")==0){check_counter++;}
    }
    
    //Check Vertical
    if(i>=1 && i<=139){
        buffer[0]=data[i-1][j];
        buffer[1]=data[i][j];
        buffer[2]=data[i+1][j];
        buffer[3]='\0';
        if (strcmp(buffer,"MAS")==0){check_counter++;}
    }
    */
    char aux={0};
    //Check Diagonal 1
    if(j>=1 && j<=139 && i>=1 && i<=139){
        buffer[0]=data[i-1][j-1];
        buffer[1]=data[i][j];
        buffer[2]=data[i+1][j+1];
        buffer[3]='\0';
        if (strcmp(buffer,"MAS")==0){check_counter++;}
        aux=buffer[0];
        buffer[0]=buffer[2];
        buffer[2]=aux;
        if (strcmp(buffer,"MAS")==0){check_counter++;}
    }

    //Check Diagonal 2
    if(j>=1 && j<=139 && i>=1 && i<=139){
        buffer[0]=data[i-1][j+1];
        buffer[1]=data[i][j];
        buffer[2]=data[i+1][j-1];
        buffer[3]='\0';
        if (strcmp(buffer,"MAS")==0){check_counter++;}
        aux=buffer[0];
        buffer[0]=buffer[2];
        buffer[2]=aux;
        if (strcmp(buffer,"MAS")==0){check_counter++;}
    }

    if (check_counter==2){return 1;}
    return 0;
    
}