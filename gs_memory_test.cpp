#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<time.h>
#include<string.h>
#include "gs_memory_class.hpp"
#include "types.h"

extern unsigned int str2num(unsigned char *s);

int randomTest_8w6r( const int count, const int index_base, gs_regfile_128x64_8sw6sr & rf86 ){
  tb_rf8w6r_in_t  pat;
  tb_rf8w6r_out_t gld;
  memset(&pat, 0, sizeof(pat));
  memset(&gld, 0, sizeof(gld));

  int i=0;
  do{
    memset(&pat, 0, sizeof(pat));
    memset(&gld, 0, sizeof(gld));
    pat.cmp_mask = 0x00ffffffffffffull;
    pat.wen7_0 = random()&0xff;
    pat.ren5_0 = random()&0x3f;
    pat.waddr[7] = random()&0x7f;
    pat.waddr[6] = random()&0x7f;
    pat.waddr[5] = random()&0x7f;
    pat.waddr[4] = random()&0x7f;
    pat.waddr[3] = random()&0x7f;
    pat.waddr[2] = random()&0x7f;
    pat.waddr[1] = random()&0x7f;
    pat.waddr[0] = random()&0x7f;
    pat.raddr[5] = random()&0x7f;
    pat.raddr[4] = random()&0x7f;
    pat.raddr[3] = random()&0x7f;
    pat.raddr[2] = random()&0x7f;
    pat.raddr[1] = random()&0x7f;
    pat.raddr[0] = random()&0x7f;
    pat.d[7] = random() + (0x100000000ull*random());
    pat.d[6] = random() + (0x100000000ull*random());
    pat.d[5] = random() + (0x100000000ull*random());
    pat.d[4] = random() + (0x100000000ull*random());
    pat.d[3] = random() + (0x100000000ull*random());
    pat.d[2] = random() + (0x100000000ull*random());
    pat.d[1] = random() + (0x100000000ull*random());
    pat.d[0] = random() + (0x100000000ull*random());
    if( rf86.operate(pat.wen7_0&0x01, pat.waddr[0],pat.d[0],
          pat.wen7_0&0x02, pat.waddr[1], pat.d[1],
          pat.wen7_0&0x04, pat.waddr[2], pat.d[2],
          pat.wen7_0&0x08, pat.waddr[3], pat.d[3],
          pat.wen7_0&0x10, pat.waddr[4], pat.d[4],
          pat.wen7_0&0x20, pat.waddr[5], pat.d[5],
          pat.wen7_0&0x40, pat.waddr[6], pat.d[6],
          pat.wen7_0&0x80, pat.waddr[7], pat.d[7],
          pat.ren5_0&0x01, pat.raddr[0], pat.ren5_0&0x02, pat.raddr[1],
          pat.ren5_0&0x04, pat.raddr[2], pat.ren5_0&0x08, pat.raddr[3],
          pat.ren5_0&0x10, pat.raddr[4], pat.ren5_0&0x2f, pat.raddr[5]) ){
      i++;
      gld.q[0] = rf86.get_out0();
      gld.q[1] = rf86.get_out1();
      gld.q[2] = rf86.get_out2();
      gld.q[3] = rf86.get_out3();
      gld.q[4] = rf86.get_out4();
      gld.q[5] = rf86.get_out5();
      //write_pattern(index_base+i, pat);
      //write_golden( index_base+i, gld);
    }
  }while( i < count );
  // Start test
  return count;
}

int randomTest_4w4r( const int count, const int index_base, gs_regfile_128x64_4sw4sr & rf44 ){

  tb_rf4w4r_in_t  pat;
  tb_rf4w4r_out_t gld;
  memset(&pat, 0, sizeof(pat));
  memset(&gld, 0, sizeof(gld));

  int i=0;
  do{
    memset(&pat, 0, sizeof(pat));
    memset(&gld, 0, sizeof(gld));
    pat.cmp_mask = 0x000000ffffffffull;
    pat.wen3_0 = random()&0x0f;
    pat.ren3_0 = random()&0x0f;
    pat.waddr[3] = random()&0x7f;
    pat.waddr[2] = random()&0x7f;
    pat.waddr[1] = random()&0x7f;
    pat.waddr[0] = random()&0x7f;
    pat.raddr[3] = random()&0x7f;
    pat.raddr[2] = random()&0x7f;
    pat.raddr[1] = random()&0x7f;
    pat.raddr[0] = random()&0x7f;
    pat.d[3] = random() + (0x100000000ull*random());
    pat.d[2] = random() + (0x100000000ull*random());
    pat.d[1] = random() + (0x100000000ull*random());
    pat.d[0] = random() + (0x100000000ull*random());
    if( rf44.operate(pat.wen3_0&0x01, pat.waddr[0],pat.d[0],
          pat.wen3_0&0x02, pat.waddr[1], pat.d[1],
          pat.wen3_0&0x04, pat.waddr[2], pat.d[2],
          pat.wen3_0&0x08, pat.waddr[3], pat.d[3],
          pat.ren3_0&0x01, pat.raddr[0], pat.ren3_0&0x02, pat.raddr[1],
          pat.ren3_0&0x04, pat.raddr[2], pat.ren3_0&0x08, pat.raddr[3]) ){
      i++;
      gld.q[0] = rf44.get_out0();
      gld.q[1] = rf44.get_out1();
      gld.q[2] = rf44.get_out2();
      gld.q[3] = rf44.get_out3();
      //write_pattern(index_base+i, pat);
      //write_golden( index_base+i, gld);
    }
  }while( i < count );
  // Start test
  return count;
}

int randomTest_3w5r( const int count, const int index_base, gs_cp0q_ram_64x128_3sw5sr & cp35 ){

  tb_cp0q_ram_old_in_t  pat;
  tb_cp0q_ram_old_out_t gld;
  memset(&pat, 0, sizeof(pat));
  memset(&gld, 0, sizeof(gld));

  int i=0;
  do{
    memset(&pat, 0, sizeof(pat));
    memset(&gld, 0, sizeof(gld));
    pat.cmp_mask = 0x0000ffffffffffull;
    pat.wvalue0[0] = (((uint64_t)random())<<32) + (uint64_t)random();
    pat.wvalue0[1] = (((uint64_t)random())<<32) + (uint64_t)random();
    pat.wvalue1[0] = (((uint64_t)random())<<32) + (uint64_t)random();
    pat.wvalue1[1] = (((uint64_t)random())<<32) + (uint64_t)random();
    pat.waddr0 = random()&0x7f;
    pat.waddr1 = random()&0x7f;
    pat.raddr0 = random()&0x3f;
    pat.raddr1 = random()&0x3f;
    pat.raddr2 = random()&0x3f;
    pat.raddr3 = random()&0x3f;
    pat.raddr4 = random()&0x3f;
    pat.ren    = random()&0x1f;
    pat.wmask0 = random()&0xfffful;
    pat.wmask1 = random()&0xfffful;
    pat.osel   = random()&0x1;
    pat.wen2   = random();

    if( cp35.operate( !(pat.waddr0&0x40), pat.waddr0&0x3f, pat.wvalue0[0], pat.wvalue0[1], pat.wmask0,
          !(pat.waddr1&0x40), pat.waddr1&0x3f, pat.wvalue1[0], pat.wvalue1[1], pat.wmask1,
          pat.wen2,
          pat.ren&0x01, pat.raddr0, pat.ren&0x02, pat.raddr1,
          pat.ren&0x04, pat.raddr2, pat.ren&0x08, pat.raddr3,
          pat.ren&0x10, pat.raddr4) ){
      i++;
      gld.q[0] = pat.osel ? cp35.get_out0H() :  cp35.get_out0L();
      gld.q[1] = pat.osel ? cp35.get_out1H() :  cp35.get_out1L();
      gld.q[2] = pat.osel ? cp35.get_out2H() :  cp35.get_out2L();
      gld.q[3] = pat.osel ? cp35.get_out3H() :  cp35.get_out3L();
      gld.q[4] = pat.osel ? cp35.get_out4H() :  cp35.get_out4L();
      //write_pattern(index_base+i, pat);
      //write_golden( index_base+i, gld);
    }
  }while( i < count );
  // Start test
  return count;
}

int randomTest_2w5r( const int count, const int index_base, gs_cp0q_ram_48x64_2sw5sr & cp25 ){

  tb_cp0q_ram_in_t  pat;
  tb_cp0q_ram_out_t gld;
  memset(&pat, 0, sizeof(pat));
  memset(&gld, 0, sizeof(gld));

  int i=0;
  do{
    memset(&pat, 0, sizeof(pat));
    memset(&gld, 0, sizeof(gld));
    pat.cmp_mask = 0x0000ffffffffffull;
    pat.wvalue0 = (((uint64_t)random())<<32) + (uint64_t)random();
    pat.wvalue1 = (((uint64_t)random())<<32) + (uint64_t)random();
    pat.waddr0 = random() % 48;
    pat.waddr1 = random() % 48;
    pat.raddr0 = random() % 48;
    pat.raddr1 = random() % 48;
    pat.raddr2 = random() % 48;
    pat.raddr3 = random() % 48;
    pat.raddr4 = random() % 48;
    pat.ren4_0 = random()&0x1f;
    pat.wen1_0 = random()&0x03;

    if( cp25.operate( pat.wen1_0&0x01, pat.waddr0, pat.wvalue0, 
          pat.wen1_0&0x02, pat.waddr1, pat.wvalue1,
          pat.ren4_0&0x01, pat.raddr0, pat.ren4_0&0x02, pat.raddr1,
          pat.ren4_0&0x04, pat.raddr2, pat.ren4_0&0x08, pat.raddr3,
          pat.ren4_0&0x10, pat.raddr4) ){
      i++;
      gld.q0 = cp25.get_out0();
      gld.q1 = cp25.get_out1();
      gld.q2 = cp25.get_out2();
      gld.q3 = cp25.get_out3();
      gld.q4 = cp25.get_out4();
      //write_pattern(index_base+i, pat);
      //write_golden( index_base+i, gld);
    }
  }while( i < count );
  // Start test
  return count;
}

int randomTest_cam464v( const int count, const int index_base, gs_cam_464v_64x64_1wrs & cam464v ){

  tb_cam64x64_in_t  pat;
  tb_cam64x64_out_t gld;
  memset(&pat, 0, sizeof(pat));
  memset(&gld, 0, sizeof(gld));

  int i=0;
  do{
    memset(&pat, 0, sizeof(pat));
    memset(&gld, 0, sizeof(gld));
    pat.cmp_mask = 0x1ffffull;
    pat.valid = (((uint64_t)random())<<32) + (uint64_t)random();
    pat.wd    = (((uint64_t)random())<<32) + (uint64_t)random();
    pat.wvpn  = (((uint64_t)random()&0xffff)<<32) + (uint64_t)random();
    pat.svpn  = (((uint64_t)random()&0xffff)<<32) + (uint64_t)random();
    pat.wasid = random()&0x3ff;
    pat.sasid = random()&0x3ff;
    pat.wen   = random()&0x1;
    pat.ren   = random()&0x1;
    pat.sen   = random()&0x1;
    pat.addr  = random()&0x3f;
    pat.mask  = random()&0x3ffff;
    pat.G     = random()&0x1;

    if( cam464v.operate( pat.sen, pat.svpn, pat.sasid, pat.valid,
          pat.wen, pat.wd, pat.wvpn, pat.mask, pat.wasid, pat.G,
          pat.ren, pat.addr) ){
      i++;
      gld.match = cam464v.get_match();
      gld.rd    = cam464v.get_out();
      gld.hit   = cam464v.get_hit();
      //write_pattern(index_base+i, pat);
      //write_golden( index_base+i, gld);
    }
  }while( i < count );
  // Start test
  return count;
}

int randomTest_cambtb( const int count, const int index_base, gs_cam_btb_30x96_1wrs & cambtb ){

  tb_btbcam_in_t  pat;
  tb_btbcam_out_t gld;
  memset(&pat, 0, sizeof(pat));
  memset(&gld, 0, sizeof(gld));

  int i=0;
  do{
    memset(&pat, 0, sizeof(pat));
    memset(&gld, 0, sizeof(gld));
    pat.cmp_mask = 0x1fffffull;
    pat.valid[0] = random();
    pat.valid[1] = random();
    pat.valid[2] = random();
    int tmp = random() % 96;
    pat.addr[0] = (tmp<32)&&(tmp>= 0) ? 0x1<<(tmp- 0) : 0x00;
    pat.addr[1] = (tmp<64)&&(tmp>=32) ? 0x1<<(tmp-32) : 0x00;
    pat.addr[2] = (tmp<96)&&(tmp>=64) ? 0x1<<(tmp-64) : 0x00;
    pat.wd    = (((uint64_t)random()&0x3ffff)<<32) + (uint64_t)random();
    pat.wvpn  = random() & 0x3fffffff;
    pat.svpn  = random() & 0x3fffffff;
    pat.wen   = random()&0x1;
    pat.sen   = random()&0x1;

    if( cambtb.operate( pat.sen, pat.svpn, pat.valid[0], pat.valid[1], pat.valid[2],
          pat.wen, pat.addr[0], pat.addr[1], pat.addr[2], pat.wd, pat.wvpn) ){
      i++;
      gld.match[0] = cambtb.get_match31_00();
      gld.match[1] = cambtb.get_match63_32();
      gld.match[2] = cambtb.get_match95_64();
      gld.rd    = cambtb.get_out();
      gld.hit   = cambtb.get_hit();
      //write_pattern(index_base+i, pat);
      //write_golden( index_base+i, gld);
    }
  }while( i < count );
  // Start test
  return count;
}


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
  rf86.memset(0x00ull);
  rf44.memset(0x00ull);
  cp35.memset(0xffff, 0x00ull, 0x00ull);
  cp25.memset(0x00);
  cam464v.memset(0x00, 0x00, 0x00, false, 0x00);
  cambtb.memset(0x00, 0x00);
  // End initialization

  int rf86_cnt    = randomTest_8w6r(    1000, 0, rf86 );
  int rf44_cnt    = randomTest_4w4r(    1000, 0, rf44 );
  int cp35_cnt    = randomTest_3w5r(    1000, 0, cp35 );
  int cp25_cnt    = randomTest_2w5r(    1000, 0, cp25 );
  int cam464v_cnt = randomTest_cam464v( 1000, 0, cam464v );
  int cambtb_cnt  = randomTest_cambtb(  1000, 0, cambtb );

#ifdef DUMP_MEM
  // Begin dump
  rf86.dump();
  rf44.dump();
  cp35.dump();
  cp25.dump();
  cam464v.dump();
  cambtb.dump();
  // End dump
#endif
  
  return 0;
}
