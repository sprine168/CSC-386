/*Steven Prine
CSC-386
Prof. Morwick
*/

#include <unistd.h>
#include <stdio.h>

int main(int argc, char** argv) {

  /* Checking if the user has access for first args for reading and
     also checking if the user has write access for second args
     0 means read access, Note: -1 is  failure  Args[1] is what is going to be copied
     Args[2] is going to be copied to*/
    if(access(argv[1], R_OK) == 0 && access(argv[2], W_OK) == 0){  
            printf("\n--- You have successfuly read in 2 arguments ---\n\n");
            FILE* fp = fopen(argv[1], "r");              /*open the file from first arg with read permission*/
            FILE* wp = fopen(argv[2], "w");              /*open the file from second arg with write permission*/

            while(!feof(fp)) {
                int b = fgetc(fp);
                if(b != EOF) {
                    fputc(b , wp);
                }                      
            }
            fclose(fp);   
            fclose(wp);

    }else{
        printf("Need to supply two arguments\n");   
    }

    return 0;
}
