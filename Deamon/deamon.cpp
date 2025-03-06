#include<iostream>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

using namespace std;

int x=1;

void deamon(){
    pid_t pid = fork();
    if(pid<0) exit(EXIT_FAILURE);
    if(pid>0) exit(EXIT_SUCCESS);
    if(setsid()<0) exit(EXIT_FAILURE);

    umask(0);
    chdir("/");

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    int log_fd = open("/home/littlesparrow/operatingSystem/Deamon/deamon.log", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if(log_fd==-1){
        perror("cant find file");
        exit(EXIT_FAILURE);
    }
    while(1){
        write(log_fd,"Deamon ",7);
        sleep(5);
    }
    close(log_fd);    
}


int main(){
    deamon();
    cout<<x<<" ";
}