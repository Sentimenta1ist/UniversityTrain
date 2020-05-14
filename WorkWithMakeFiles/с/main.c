#include "init.h"
#include "task.h"


int main(int argc, char *argv[]	){
    int n = 7;
    int debug = 0;  //if debug == 1 - debug version

    if(argc > 1){
    	if(argc == 2){
    		if(!strcmp("-d",argv[argc - 1])){
    			debug = 1;
    		}
    		else{
    			n = atoi(argv[argc - 1]);
    		}
    	}
    	if(argc == 3){
    		if(!strcmp("-d",argv[argc - 2])){
    			debug = 1;
    			n = atoi(argv[argc - 1]);
    		}
    		else if(!strcmp("-d",argv[argc - 1])){
    			debug = 1;
    			n = atoi(argv[argc - 2]);
    		}
    	}
    }
   
    double **Matrix = AllocMatrix(n);
    if(debug) printf("DEBUG VERSION\n");
    else printf("RELEASE VERSION\n");

    FillSortMatrix(Matrix,n);
    printf("\nSorted:\n");
    printf("Before:\n");
    PrintMatrix(Matrix,n);
    Matrix = FindAndReplace(Matrix,n,debug);
    printf("After:\n");
    PrintMatrix(Matrix,n);

    FillBackSortMatrix(Matrix,n);
    printf("\nBackSorted:\n");
    printf("Before:\n");
    PrintMatrix(Matrix,n);
    Matrix = FindAndReplace(Matrix,n,debug);
    printf("After:\n");
    PrintMatrix(Matrix,n);

    FillRandomMatrix(Matrix,n);
    printf("\nRandom:\n");
    printf("Before:\n");
    PrintMatrix(Matrix,n);
    Matrix = FindAndReplace(Matrix,n,debug);
    printf("After:\n");
    PrintMatrix(Matrix,n);

    FillTestMatrix(Matrix,n);
    printf("\nTest:\n");
    printf("Before:\n");
    PrintMatrix(Matrix,n);
    Matrix = FindAndReplace(Matrix,n,debug);
    printf("After:\n");
    PrintMatrix(Matrix,n);

    return 0;
}