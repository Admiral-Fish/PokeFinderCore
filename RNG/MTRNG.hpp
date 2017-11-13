#ifndef MTRNG_HPP
#define MTRNG_HPP

#include <libPokeFinder/RNG/IRNG.hpp>

class MersenneTwister : public IRNG
{

private:
    u32 const LOWERMASK = 0x7FFFFFFF;
    int const M = 397;
    u32 const MATRIXA = 0x9908B0DF;
    int const N = 624;
    u32 const UPPERMASK = 0x80000000;
    u32 const TEMPERINGMASKB = 0x9D2C5680;
    u32 const TEMPERINGMASKC = 0xEFC60000;
    u32 mag01[2] = { 0x0, MATRIXA };
    u32 mt[624];
    int index;

    void init(u32 seed);

    u32 temperingShiftL(u32 y);

    u32 temperingShiftS(u32 y);

    u32 temperingShiftT(u32 y);

    u32 temperingShiftU(u32 y);

public:

    MersenneTwister(u32 seed);

    virtual u32 Nextuint();

    virtual void Reseed(u32 seed);
    
};

class MersenneTwisterUntempered : public IRNG
{
    
private:
    int const M = 397;
    int const N = 624;
    u32 const MATRIXA = 0x9908B0DF;
    u32 const LOWERMASK = 0x7FFFFFFF;
    u32 const UPPERMASK = 0x80000000;
    u32 mt[624];
    u32 mag01[2] = { 0x0, MATRIXA };
    int index;

    void init(u32 seed);

public:

    MersenneTwisterUntempered(u32 seed);

    virtual void Reseed(u32 seed);

    virtual u32 Nextuint();
    
};

class MersenneTwisterFast : public IRNG
{
    
private:
    int const M = 397;
    int const N = 624;
    u32 const LOWERMASK = 0x7FFFFFFF;
    u32 const MATRIXA = 0x9908B0DF;
    u32 const TEMPERINGMASKB = 0x9D2C5680;
    u32 const TEMPERINGMASKC2 = 0xEFC00000;
    u32 const UPPERMASK = 0x80000000;
    u32 mag01[2] = { 0x0, MATRIXA };
    int max;
    int maxCalls;
    u32 mt[624];
    int index;

    void init(u32 seed);

    u32 temperingShiftS(u32 y);

    u32 temperingShiftT(u32 y);

    u32 temperingShiftU(u32 y);

public:

    MersenneTwisterFast(u32 seed, int calls);

    virtual u32 Nextuint();

    virtual void Reseed(u32 seed);
    
};

#endif //MTRNG_HPP
