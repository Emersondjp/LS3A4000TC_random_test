#ifndef GS_MEMORY_CLASS__HPP
#define GS_MEMORY_CLASS__HPP

class gs_memory{
  public:
    virtual bool verify();
    virtual bool operate();
};

class gs_regfile_128x64_8sw6sr : public gs_memory{
  private:
    uint64_t mem[128];
  protected:
    uint64_t out0;
    uint64_t out1;
    uint64_t out2;
    uint64_t out3;
    uint64_t out4;
    uint64_t out5;
  public:
    bool verify();
    bool operate();
    bool memset();
    bool write();
    bool read();
    uint64_t get_out0();
    uint64_t get_out1();
    uint64_t get_out2();
    uint64_t get_out3();
    uint64_t get_out4();
    uint64_t get_out5();
};

class gs_regfile_128x64_4sw4sr : public gs_memory{
  private:
    uint64_t mem[128];
  protected:
    uint64_t out0;
    uint64_t out1;
    uint64_t out2;
    uint64_t out3;
  public:
    bool verify();
    bool operate();
    bool memset();
    bool write();
    bool read();
    uint64_t get_out0();
    uint64_t get_out1();
    uint64_t get_out2();
    uint64_t get_out3();
};

class gs_cp0q_ram_64x128_3sw5sr : public gs_memory{
  private:
    uint64_t mem_H[64];
    uint64_t mem_L[64];
  protected:
    uint64_t out0_H, out0_L;
    uint64_t out1_H, out1_L;
    uint64_t out2_H, out2_L;
    uint64_t out3_H, out3_L;
    uint64_t out4_H, out4_L;
  public:
    bool verify();
    bool operate();
    bool memset();
    bool write();
    bool read();
    uint64_t get_out0H();
    uint64_t get_out0L();
    uint64_t get_out1H();
    uint64_t get_out1L();
    uint64_t get_out2H();
    uint64_t get_out2L();
    uint64_t get_out3H();
    uint64_t get_out3L();
    uint64_t get_out4H();
    uint64_t get_out4L();
};

class gs_cp0q_ram_48x64_2sw5sr : public gs_memory{
  private:
    uint64_t mem[48];
  protected:
    uint64_t out0;
    uint64_t out1;
    uint64_t out2;
    uint64_t out3;
    uint64_t out4;
  public:
    bool verify();
    bool operate();
    bool memset();
    bool write();
    bool read();
    uint64_t get_out0();
    uint64_t get_out1();
    uint64_t get_out2();
    uint64_t get_out3();
    uint64_t get_out4();
};

#endif

