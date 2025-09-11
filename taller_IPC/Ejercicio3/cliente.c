#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

int main() {
	char exitmsg[100] = "exit";
	char msg[100];
	char msg_server[100];
	int id = getpid();
  int server_socket;
  struct sockaddr_un server_addr;

  server_addr.sun_family = AF_UNIX;

  strcpy(server_addr.sun_path, "unix_socket");

  printf("cliente[%d]: me estoy conectando con el servidor...\n", id);

  server_socket = socket(AF_UNIX, SOCK_STREAM, 0);

  if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
      perror("Error");
      exit(EXIT_FAILURE);
  }


	while(strcmp(msg,exitmsg)){
		if (scanf("%s", msg) == -1) {
				perror("Error");
				exit(EXIT_FAILURE);
		}

		printf("cliente[%d]: mandé mi algo al servidor\n", id);
		if (write(server_socket, &msg, sizeof(msg)) == -1) {
				perror("Error");
				exit(EXIT_FAILURE);
		}

		if (read(server_socket, &msg_server, sizeof(msg_server)) == 0) {
				perror("Error");
				exit(EXIT_FAILURE);
			}
		printf("cliente[%d]: recibí %s del servidor!\n", id, msg);
	}

  close(server_socket);
  exit(0);
}
