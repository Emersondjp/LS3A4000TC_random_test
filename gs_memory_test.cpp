#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<time.h>
#include "gs_memory_class.hpp"

extern unsigned int str2num(unsigned char *s);

int main( int argc, char *argv[] ){
  int seed=0; // random seed
  if( argc == 1 ){
    printf("No random seed specified, use ctime() to get!\n");
    seed = (int)time(NULL);
  } else {
    seed = str2num((unsigned char*)argv[1]);
  }
  srand( seed );
  printf("Random Seed is : %d .\n\n", seed);

  gs_regfile_128x64_8sw6sr  rf86;
  gs_regfile_128x64_4sw4sr  rf44;
  gs_cp0q_ram_64x128_3sw5sr cp35;
  gs_cp0q_ram_48x64_2sw5sr  cp25;
  gs_cam_464v_64x64_1wrs    cam464v;
  gs_cam_btb_30x96_1wrs     cambtb;
  // Begin initialization
  //rf86.memset(0x00ull);
  //rf44.memset(0x00ull);
  //cp35.memset(0xffffull, 0x00, 0x00);
  //cp25.memset(0x00);
  //cam464v.memset(0x00, 0x00, 0x00, false, 0x00);
  //cambtb.memset(0x00, 0x00);
  // End initialization


  // Begin dump
  rf86.dump();
  rf44.dump();
  cp35.dump();
  cp25.dump();
  cam464v.dump();
  cambtb.dump();
  // End dump
  
  return 0;
}
