/* tcpclient.c */

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "FileReaderFn.c"


int main()

{

        int sock, bytes_recieved;  
        char send_data[1024],recv_data[1024];
        struct hostent *host;
        struct sockaddr_in server_addr;  

        host = gethostbyname("127.0.0.1");

        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            perror("Socket");
            exit(1);
        }

        server_addr.sin_family = AF_INET;     
        server_addr.sin_port = htons(5000);   
        server_addr.sin_addr = *((struct in_addr *)host->h_addr);
        bzero(&(server_addr.sin_zero),8); 

        if (connect(sock, (struct sockaddr *)&server_addr,
                    sizeof(struct sockaddr)) == -1) 
        {
            perror("Connect");
            exit(1);
        }

        while(1)
        {
        
          bytes_recieved=recv(sock,recv_data,1024,0);
          recv_data[bytes_recieved] = '\0';
 
          if (strcmp(recv_data , "q") == 0 || strcmp(recv_data , "Q") == 0)
          {
           close(sock);
           break;
          }

          else
           printf("\nRecieved data = %s " , recv_data);
           
           //printf("\nSEND (q or Q to quit) : ");
           //gets(send_data);
           if(strcmp(recv_data,"Ready")==0) {
				strcpy(send_data,"Write");
		   }
		   printf("\n XXXXXXXXXXXXXXXXXXXXX" );
		   if(strcmp(recv_data,"Ok")==0) {
				printf("\n Ok received");
				char buffer[1024];
				FILE *f;
				printf("\nGoing to open file");
				f=fopen("Server.py","r");
				printf("\n YYYYYYYYYYYYYYYYY" );
        int bytes_read = 0;
          printf("\n WWWWWWWWWWWWWWWWWW");
        while (1)
          {
            printf("\n WWWWWWWWWWWWWWWWWW");
            bytes_read = fread(buffer, sizeof(char),1024, f);
            buffer[bytes_read] = '\0';
            printf("\n Read : %s ", buffer);
            printf("\n ###########################");
            if(bytes_read == 0)
            {
              printf("\n End of File ");
              write(sock,"EOF",sizeof("EOF"));
              break;
            }
            else
            {
              write(sock,buffer,1024); 
            }
					   
				  }
					
				//buffer = readFromFile("MultiThreadedServer.py");
				//write(sock,buffer,sizeof(buffer));
				printf("\nthe file was sent successfully");
				//gets(ff);
		   }
           
          if (strcmp(send_data , "q") != 0 && strcmp(send_data , "Q") != 0)
           send(sock,send_data,strlen(send_data), 0); 

          else
          {
           send(sock,send_data,strlen(send_data), 0);   
           close(sock);
           break;
          }
        
        }   
return 0;
}
