#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
	puts("copy command starts\n"); /* prints !!!Hello World!!! */

	int des1=0;
	int des2=0;
	int n =100;
	char BUFF[100];

	des1  =open(argv[1], O_RDONLY, 0700);
	des2 =open(argv[2], O_CREAT | O_WRONLY | O_EXCL , 0700);

	if(!(des1 != -1 && des2 !=-1)){
		perror("Returned error");
		return -1;
	}

	while(1)
	{
		n=read(des1, BUFF, 100);

		if(write(des2, BUFF, 100)!=100)
		{
			perror("Write error");
			return -1;
			break;
		}
		if(n==-1)
		{
			perror("Read Error");
			return -1;
			break;
		}
		else if(n<100)
			break;
	}
	close(des2);
	close(des1);

	if(remove(argv[1])==0)
		printf("Copied Successfully!\n");
	else
		printf("Copy Error\n");

	return EXIT_SUCCESS;
}
