#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv){
    
    int i, pid;
    pid = fork();
    
    fprintf(stdout, "Forking...the pid: %d\n", pid);
    for(i = 0; i < 5; i++)
        fprintf(stdout, "%d\t%d\n", i, getpid());
    if(pid)
        wait(NULL);
        
    return 0;
}
