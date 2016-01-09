#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include "tcpclientReadWriteFn.c"
//extern int connect_to_write(char * ip,int port)
int main()
{
	char * command;
	command = malloc(sizeof(char)*30);
	printf("\n Connecting to Server \n");
	printf("\n Enter the Command : ");
	scanf()

	while(1){
		connect_to_write("192.168.42.70",5000,"CallPython.c");
	}
	return 0;
}
