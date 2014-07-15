#include "gtmdata.h"
#include <stdio.h>
#include <time.h>

#define BUFSIZ ((1024 * 1024) + 1)

int main(int argc, char **argv)
{
  int status;
  long i;
  char lib_version[BUFSIZ];
  char ret_get[BUFSIZ];
  char ret_ver[BUFSIZ];
  char set_sub[BUFSIZ];

  

  time_t start_time, end_time, elapsed;
  long nodes_per_second;

  (void) gtmdata_version(&lib_version);
  (void) printf("%s\n\n", lib_version);

  (void) printf("db_open():\n");
  status = db_open();

  (void) printf("db_get():\t");
  status = db_get("^TT(\"ACCT\",1000)", &ret_get);
  (void) printf("%s\n", ret_get);

  (void) printf("db_version():\t");
  status = db_version(&ret_ver);
  (void) printf("%s\n", ret_ver);

  (void) printf("db_set():\t1,000,000 nodes in ");
  start_time = time(NULL); 
  for(i = 1; i < 1000000; i++) {
    (void) sprintf(set_sub, "^KBBMCITS(%d)", i);
    (void) db_set(set_sub, "test");
  }
  end_time = time(NULL);
  elapsed = end_time - start_time;
  nodes_per_second = 1000000 / elapsed;
  (void) printf("%d seconds (%d nodes/second)\n", elapsed, nodes_per_second);

  (void) printf("db_kill():\n");
  (void) db_kill("^KBBMCITS");

  (void) printf("db_data():\t");
  (void) db_set("^KBBMCITS", "a");
  (void) db_set("^KBBMCITS(1)", "b");
  (void) printf("^KBBMCITS = %d ^KBBMCITS(1) = %d\n", db_data("^KBBMCITS"), db_data("^KBBMCITS(1)")); 	   

  (void) printf("db_close():\n");
  status = db_close();

  return 0;
}
