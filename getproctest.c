#ifdef CS333_P2
#include "types.h"
#include "user.h"
#include "uproc.h"
// Fork to 64 process and then make sure we get all when passing table array
// of sizes 1, 16, 64, 72. NOTE: caller does all forks.
int
testprocarray(int max, int expected_ret){
  struct uproc * table;
  int ret, success = 0;

  table = malloc(sizeof(struct uproc) * max);  // bad code, assumes success
  if (!table) {
    printf(2, "Error: malloc() call failed. %s at line %d\n", __FUNCTION__, __LINE__);
    exit();
  }
  ret = getprocs(max, table);
  if (ret != expected_ret){
    printf(2, "FAILED: getprocs(%d) returned %d, expected %d\n", max, ret, expected_ret);
    success = -1;
  }
  else{
    printf(2, "getprocs() was asked for %d processes and returned %d. SUCCESS\n", max, expected_ret);
  }
  free(table);
  return success;
}

int
testinvalidarray(void){
  struct uproc * table;
  int ret;

  table = malloc(sizeof(struct uproc));
  if (!table) {
    printf(2, "Error: malloc() call failed. %s at line %d\n", __FUNCTION__, __LINE__);
    exit();
  }
  ret = getprocs(1024, table);
  free(table);
  if(ret >= 0){
    printf(2, "FAILED: called getprocs with max way larger than table and returned %d, not error\n", ret);
    return -1;
  }
  return 0;
}

int
main(void){
  int ret, success;

  printf(1, "\n----------\nRunning GetProcs Test\n----------\n");
  printf(1, "Filling the proc[] array with dummy processes\n");
  // Fork until no space left in ptable
  ret = fork();
  if (ret == 0){
    while((ret = fork()) == 0);
    if(ret > 0){
      wait();
      exit();
    }
    printf(1, "64 processes created!.\n");
    // Only return left is -1, which is no space left in ptable
    success  = testinvalidarray();
    printf(1, "Testing with max = 1:\n");
    success |= testprocarray( 1,  1);
    
    printf(1, "Testing with max = 16:\n");
    success |= testprocarray(16, 16);
   
    printf(1, "Testing with max = 64:\n");
    success |= testprocarray(64, 64);
  
    printf(1, "Testing with max = 72:\n");
    success |= testprocarray(72, 64);
    sleep(5000);
    if (success == 0)
      printf(1, "** All Tests Passed **\n");
    exit();
  }
  wait();
  exit();
}
#endif
