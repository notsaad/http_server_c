#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {

    int network_socket;
    network_socket  = socket(AF_INET, SOCK_STREAM, 0);

    // specify an address for the socker

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(6969);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int connection_status = connect(network_socket, (struct sockaddr*) &server_address, sizeof(server_address));

    if (connection_status == -1){
        printf("There was an error connecting to the port\n");
    }

    char response[256];

    recv(network_socket, &response, sizeof(response), 0);

    // pritn out successful response

    printf("Data received from the server: %s\n", response);

    close(network_socket);

    return 0;
}