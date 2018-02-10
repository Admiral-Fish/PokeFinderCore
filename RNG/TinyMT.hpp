#ifndef TINYMT_HPP
#define TINYMT_HPP

#include <libPokeFinder/RNG/IRNG.hpp>

class TinyMT : public IRNG
{

private:
    static const u32 MAT1 = 0x8f7011ee;
    static const u32 MAT2 = 0xfc78ff1f;
    static const int MINLOOP = 8;
    static const int PRELOOP = 8;
    static const u32 TMAT = 0x3793fdff;
    static const u32 TINYMT32MASK = 0x7FFFFFFF;
    static const int TINYMT32SH0 = 1;
    static const int TINYMT32SH1 = 10;
    static const int TINYMT32SH8 = 8;
    u32 state[4];

    void initialize(u32 seed);
    void periodCertification();

public:
    TinyMT(u32 seed);
    TinyMT(u32 st[]);
    void advanceFrames(int frames) override;
    void nextState();
    u32 nextUInt() override;
    u32 temper();
    void reseed(u32 seed) override;

};

#endif // TINYMT_HPP
