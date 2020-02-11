#include <iostream>
#include <stdio.h>

int main(int argc, char** argv) {
	
	for(int i = 0; i < argc; ++i) {
		std::cout << argv[i] << std::endl;
	}

	int counter;
	printf("Program Name Is: %s",argv[0]);
    if(argc==1) {
        printf("\nNo Extra Command Line Argument Passed Other Than Program Name");
	}
    if(argc>=2) {
		printf("\nNumber Of Arguments Passed: %d",argc);
        printf("\n----Following Are The Command Line Arguments Passed----"); 
        for(counter=0;counter<argc;counter++) {
            printf("\nargv[%d]: %s", counter, argv[counter]);
        }
    }

	return 0;
}
