
/* tcpclientReadWriteFn.c */


#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
//#include "FileReaderFn.c"



int connect_to_write(char *ip, int port, char * buffer, char * filename)
{
        int sock, bytes_recieved;  
        char send_data[1024],recv_data[1024];
        struct hostent *host;
        struct sockaddr_in server_addr;  
        printf ("\n ***** Inside connect_to_write ****** \n");
        printf("\n Connecting to %s ",ip);
        host = gethostbyname(ip);
        //host = gethostbyname("192.168.42.186");
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            perror("Socket");
            exit(1);
        }

        server_addr.sin_family = AF_INET;     
        server_addr.sin_port = htons(port);   
        server_addr.sin_addr = *((struct in_addr *)host->h_addr);
        bzero(&(server_addr.sin_zero),8); 

        if (connect(sock, (struct sockaddr *)&server_addr,
                    sizeof(struct sockaddr)) == -1) 
        {
            perror("Connect");
            exit(1);
        }
         bytes_recieved=recv(sock,recv_data,1024,0);
          recv_data[bytes_recieved] = '\0';
 
           printf("\n @@@@@@ Filename : %s",filename);
           write(sock,filename,30);
           printf("\nRecieved data = %s " , recv_data);
           
           //printf("\nSEND (q or Q to quit) : ");
           //gets(send_data);
		   printf("\n XXXXXXXXXXXXXXXXXXXXX" );
				printf("\nGoing to open file");
				//f=fopen(filename,"r");
				printf("\n YYYYYYYYYYYYYYYYY" );
        int bytes_read = 0;
          printf("\n WWWWWWWWWWWWWWWWWW");
        //while (1)
         // {
            printf("\n WWWWWWWWWWWWWWWWWW");
            //bytes_read = fread(buffer, sizeof(char),1024, f);
           // buffer[bytes_read] = '\0';
            printf("\n Read :\n %s ", buffer);
            printf("\n ###########################");
              write(sock,buffer,1024); 
				printf("\nthe file was sent successfully");
           close(sock);
          // break;
         // }
        
        //}   
return 0;
}
