/*
Steven Prine 
CSC-346
Prof.Morwick
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE atoi(argv[3])

int main(int argc, char** argv) {

    int checker = BUFFER_SIZE;

    if(BUFFER_SIZE <= 0){
        printf("!!! The interger provided needs to be a positive integer !!!");
        return -1;
    }     
                                           

    /* Checking if the user has access for first args for reading and
    also checking if the user has write access for second args
    0 means read access, Note: -1 is  failure  and the inputted posNum has to be positive*/
    if(access(argv[1], R_OK) == 0 && access(argv[2], W_OK) == 0 ){
        printf("Success in the making\n");
        FILE* fp = fopen(argv[1], "r");                                             //opening the args in index 1 that has read permission
        FILE* wp = fopen(argv[2], "w");                                             //opening the args in index 2 that has write permission
        int bytes_read = 0;                                       

        //Allocating the char array with memory buffer size    
        char* buffer = malloc(BUFFER_SIZE);                                         

        /*While the file is open use the buffer that was created to copy the file and overwrite*/
        while(!feof(fp)){                                                           
            bytes_read = fread(buffer, 1, BUFFER_SIZE, fp);
            fwrite(buffer, 1, bytes_read, wp);

        }
        fclose(fp);   
        fclose(wp);          

    }else{
        printf("Requires 2 arguments and a positive interger\n");
    }
    return 0;
}
