#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

static void sighandler(int sig){
	if (sig == SIGINT){
		int fd = open("file", O_CREAT|O_RDWR|O_APPEND, 0644);
		char msg[] = "Program exited due to SIGINT \n";
        write(fd, msg, sizeof(msg));
        close(fd);
		printf("Exited due to SIGINT \n");
		exit(0);
	}
	if (sig == SIGUSR1) {
		printf("Parent PID: %d\n",getppid());
	}
}

int main(){
	umask(0000);
	signal(SIGINT,sighandler);
	signal(SIGUSR1,sighandler);

	while (1) {
		printf("PID: %d\n",getpid());
		sleep(1);
	}

	return 0;
}