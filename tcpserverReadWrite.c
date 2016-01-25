/* tcpserver.c */

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "fileWriterFn.c"


int main()
{

        int sock, connected, bytes_recieved , true = 1;
        static int count = 0; 
        char send_data [1024] , recv_data[1024],*filename;       

        //int sock, connected, bytes_recieved , true = 1;  
        //char send_data [1024] , recv_data[1024];       


        struct sockaddr_in server_addr,client_addr;    
        int sin_size;
        
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            perror("Socket");
            exit(1);
        }

        if (setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&true,sizeof(int)) == -1) {
            perror("Setsockopt");
            exit(1);
        }
        
        server_addr.sin_family = AF_INET;         
        server_addr.sin_port = htons(5000);     
        server_addr.sin_addr.s_addr = INADDR_ANY; 
        bzero(&(server_addr.sin_zero),8); 

        if (bind(sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr))
                                                                       == -1) {
            perror("Unable to bind");
            exit(1);
        }

        if (listen(sock, 5) == -1) {
            perror("Listen");
            exit(1);
        }
		
	printf("\nTCPServer Waiting for client on port 5000");
        fflush(stdout);


        while(1)
        {  

            sin_size = sizeof(struct sockaddr_in);

            connected = accept(sock, (struct sockaddr *)&client_addr,&sin_size);

            printf("\n I got a connection from (%s , %d)",
                   inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
            strcpy(send_data, "Ready");
			      send(connected, send_data,strlen(send_data), 0); 
            while (1)
            {
             //printf("\n SEND (q or Q to quit) : ");
              
              
              //if (strcmp(send_data , "q") == 0 || strcmp(send_data , "Q") == 0)
              //{
              //  send(connected, send_data,strlen(send_data), 0); 
                //close(connected);
                //break;
              //}
               
              //else
              bytes_recieved = recv(connected,recv_data,1024,0);

              recv_data[bytes_recieved] = '\0';
              printf("\n RECIEVED DATA = %s " , recv_data);
              if(strcmp(recv_data,"Write")==0)
              {
					       printf("\n Write Command ");
					       strcpy(send_data,"Ok");
					       send(connected, send_data,strlen(send_data), 0);
			        }
			        else if (strcmp(recv_data , "q") == 0 || strcmp(recv_data , "Q") == 0)
              {
					       close(connected);
					       break;
              }
			        else 
			        {
					       printf("\n $$$$$$$$$$$$$$$$$$$$$$ RECIEVED DATA = ");
					       char buffer[1024];
					       FILE *fp;
					       //read(connected,buffer,1000);
					       //fp=fopen("torecv.txt","w");
					       printf("\n Data received : %s ", recv_data);
					       //fprintf(fp,"%s",buffer);
					       //writeToFile("torecv.txt",recv_data);

					       //while(strcmp(recv_data,"EOF")!=0)
					       //{
                 char *temp ;
                 sprintf(temp,"%d",count);
                 filename = strcat("torecv",temp);
                 filename = strcat(filename,".txt");
                    printf("\n Filename :  %s", filename);
						        writeToFile(filename,recv_data);
						        bytes_recieved = recv(connected,recv_data,1024,0);
                    recv_data[bytes_recieved] = '\0';
						        //printf("\n RECIEVED DATA = %s " , recv_data);
					    }
					       printf("\nthe file was received successfully");
					       close(sock);
					       break;
			      }
              fflush(stdout);
              //break;
            

					      /* while(strcmp(recv_data,"EOF")!=0)
					       {
                    printf("\n RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR");
						        writeToFile("torecv.txt",recv_data);
						        bytes_recieved = recv(connected,recv_data,1024,0);
                    recv_data[bytes_recieved] = '\0';
						        //printf("\n RECIEVED DATA = %s " , recv_data);
					       }
					       printf("\nthe file was received successfully");
					       close(sock);
					       break;
			        }
              fflush(stdout);
              //break;
            }*/

            break;
        }       

      close(sock);
      return 0;
} 
