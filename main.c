#include <stdio.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int childStuff(){
  srand(time(NULL));
  printf("The pid of this child is %d\n",getpid());
  int sleepTime = rand()%4+2;
  sleep(sleepTime);
  printf("This child is done :)\n");
  return sleepTime;
}

int main(){
  srand(time(NULL));
  printf("Starting the forking process...\n");
  int firstSleep = 0;
  int firstFork = fork();
  if (firstFork != 0){

    int secondFork = fork();

    if (secondFork != 0){
      int randomnumber;
      int status = wait(&randomnumber);
      printf("Parent: Child Process %d Slept For %d Seconds\n", status, WEXITSTATUS(status));
      //printf("Everything is done :)\n");
      return 0;
      }
    else{
      int time = childStuff();
      //printf("The time was %d",time);
      return time;
    }
  }

  else{
    int time = childStuff();
    printf("The time was %d",time);
    return time;
  }
  return 0;
}
