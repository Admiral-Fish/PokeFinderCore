#ifndef TINYMT_HPP
#define TINYMT_HPP

#include <cstdint>
#include <libPokeFinder/RNG/IRNG.hpp>

class TinyMT : public IRNG
{

private:
    u32 const MAT1 = 0x8f7011ee;
    u32 const MAT2 = 0xfc78ff1f;
    int const MINLOOP = 8;
    int const PRELOOP = 8;
    u32 const TMAT = 0x3793fdff;
    u32 const TINYMT32MASK = 0x7FFFFFFF;
    int const TINYMT32SH0 = 1;
    int const TINYMT32SH1 = 10;
    int const TINYMT32SH8 = 8;
    u32 state[4];

    void Initialize(u32 seed);
    void PeriodCertification();

public:
    TinyMT(u32 seed);
    TinyMT(u32 st[]);
    virtual void AdvanceFrames(int frames);
    void NextState();
    virtual u32 Nextuint();
    u32 Temper();
    virtual void Reseed(u32 seed);

};

#endif // TINYMT_HPP
