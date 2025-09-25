#include <cstdio> // for fileno
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

// simulates ls -l | wc
int main(int argc, char *argv[])
{
  int pipeInfo[2];
  int myPipe =  pipe(pipeInfo);
  int pid=fork();
  if (pid!=0) //let's make parent be "wc" ...
  {
     close(pipeInfo[1]); // not using writer, so close it. 
     dup2(pipeInfo[0], fileno(stdin));
     char *args[2]; args[0] = "wc"; args[1]=NULL;
     execvp(args[0], args);
  }
  else // in child (ls -l)
  {
     close(pipeInfo[0]); // not using reader, so close it. 
     dup2(pipeInfo[1], fileno(stdout));
     char *args[3]; args[0] = "ls"; args[1] = "-l"; args[2]=NULL;
     execvp(args[0], args);
 }
  return 0;
}
