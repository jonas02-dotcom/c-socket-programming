#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>

int main(){

// string to send when client connect
char server_message[256] ="Hey I'm the server";

//create your socket
int server_socket;
server_socket = socket(AF_INET, SOCK_STREAM, 0);

if(server_socket == -1){
    printf("server socket error");
    return 1;
}

//define server address
struct sockaddr_in server_address;
server_address.sin_family = AF_INET;
server_address.sin_port = htons(9002);
server_address.sin_addr.s_addr = INADDR_ANY;

//bind the socket to our specified port and ip
int bind_stat;
bind_stat = bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));

// bind error check
if(bind_stat == -1){
    printf("Bind failed\n");
    return 1;
}

//after binding you need to listen
int listen_stat;
listen_stat = listen(server_socket, 5);

if(listen_stat == -1){
    printf("Listening failed\n");
    return 1;
}

//accept a client

int client_socket;
client_socket = accept(server_socket, NULL, NULL);

//accept error check
if(client_socket == -1){
    printf("Accept failed\n");
    return 1;
}

// after succ. connection we will send our message to the client
//so we will call the string message in the beginning here

int message;
message = send(client_socket, server_message,sizeof(server_message),0);

//send error check
if(message == -1){

    printf("Send failed\n");
    return 1;
}






}
