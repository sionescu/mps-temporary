/* 
TEST_HEADER
 id = $Id$
 summary = create a pool in a destroyed arena
 language = c
 link = testlib.o
END_HEADER
*/

#include "testlib.h"
#include "mpscmv.h"

static void test(void)
{
 mps_arena_t arena;
 mps_pool_t pool;
 size_t extendBy;
 size_t avgSize;
 size_t maxSize;

 extendBy = (size_t) 4096;
 avgSize  = (size_t) 32;
 maxSize  = (size_t) 65536;

 cdie(mps_arena_create(&arena, mps_arena_class_vm(), mmqaArenaSIZE), "create arena");

 mps_arena_destroy(arena);
 comment("Destroyed arena.");

 cdie(
  mps_pool_create(&pool, arena, mps_class_mv(),
   extendBy, avgSize, maxSize),
  "create pool");
}

int main(void)
{
 easy_tramp(test);
 return 0;
}
