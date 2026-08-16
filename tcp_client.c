#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>


int main(){

// create a socket
int network_socket;
network_socket = socket(AF_INET, SOCK_STREAM, 0);

if (network_socket == -1){
    printf("Could not create socket\n");
    return 1;
}


// specify an address for the socket
struct sockaddr_in server_address;

server_address.sin_family = AF_INET;
server_address.sin_port = htons(9002);
server_address.sin_addr.s_addr = INADDR_ANY;

//connect
int connection_stat;

connection_stat = connect(network_socket, (struct sockaddr*)&server_address, sizeof(server_address));

// check for error with connection
if(connection_stat == -1){
    printf("CONNECTION ERROR \n");
    close(network_socket);
    return 1;
}

// recieve data from server
char server_response[256];

int data_received;
data_received = recv(network_socket, server_response, sizeof(server_response) -1, 0);
if (data_received == -1){

    printf("Could not receive data \n");
    close(network_socket);
    return 1;
}

// Mark the end of the message
server_response[data_received] = '\0';



//print out response
printf("Data from the server is %s", server_response);

//close socket
close(network_socket);


}


















}
