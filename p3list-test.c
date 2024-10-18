#ifdef CS333_P3
//Usertest by Addison Wurtz
//Based off of p3-test.c
//This program is designed to test the SLEEPING, ZOMBIE, and UNUSED lists are updated correctly 
//in response to system calls that change the relevant process state.

#include "types.h"
#include "user.h"
#include "param.h"
#include "pdx.h"

int
main(int argc, char *argv[])
{
  int rc, i = 0, childCount = 20;
//  int n = 0;

  if (argc > 1) {
    childCount = atoi(argv[1]);
  }
  if (!childCount) {
    printf(1, "No children to create, so %s is exiting.\n", argv[0]);
    exit();
  }

  //single child process calls exit while parent sleeps
  //shows child moves to ZOMBIE list after exit()
  
  printf(1, "P3 List Test Starting\n");
  //sleep(5000);

  if (childCount == 1) {
    do {
      rc = fork();
      if(rc < 0) {
       printf(1, "Fork failed!\n");
       exit();
      }
      childCount--;
    } while(childCount);
    if(rc == 0) {
//      printf(1, "Child process running\n");
      sleep(5000);
//      printf(1, "Child process calls exit\n");
      exit();
    }
    
    if(rc != 0) {
      //printf(1, "Parent is awake.\n");
      printf(1, "Parent goes to sleep while child exits\n");
      sleep(5000);
      printf(1, "Parent calls wait()\n");
      wait();
      printf(1, "Child has been reaped\n");
      /*while(n < 99999999) {
        printf(1, ""); 
        printf(1, "");
        n++;
      }
     */ 
      printf(1, "Parent process is sleeping\n");
      sleep(5000);
      exit();
    }

  }
  else {
  printf(1, "Starting %d child processes that will run forever\n", childCount);

  do {
    rc = fork();
    if (rc < 0) {
      printf(2, "Fork failed!\n");
      exit();
    }
    if (rc == 0) { // child process
      sleep(5000);
      while(1) i++;  // infinite
      exit();  // not reachable.
    }
    childCount--;
  } while(childCount);

  printf(1, "All child processes created\n");
  while(1) i++;  // loop forever and don't call wait. Good for zombie check
  exit();  // not reachable
  }
}
#endif // CS333_P3
