#include "TinyMT.hpp"

// Constructor
TinyMT::TinyMT(u32 seed)
{
    Initialize(seed);
}

// Constructor given Tiny states
TinyMT::TinyMT(u32 st[])
{
    for (int i = 0; i < 4; i++)
        state[i] = st[i];
    PeriodCertification();
}

void TinyMT::AdvanceFrames(int frames)
{
    for (int i = 0; i < frames; i++)
        NextState();
}

// Creates Tiny state given seed
void TinyMT::Initialize(u32 seed)
{
    state[0] = seed;
    state[1] = MAT1;
    state[2] = MAT2;
    state[3] = TMAT;

    int i;
    for (i = 1; i < MINLOOP; i++)
        state[i & 3] ^= i + 0x6c078965 * (state[(i - 1) & 3] ^ (state[(i - 1) & 3] >> 30));

    PeriodCertification();

    for (i = 0; i < PRELOOP; i++)
        NextState();
}

// Verifies not all 4 Tiny states are 0
void TinyMT::PeriodCertification()
{
    if (state[0] == 0 && state[1] == 0 && state[2] == 0 && state[3] == 0)
    {
        state[0] = 'T';
        state[1] = 'I';
        state[2] = 'N';
        state[3] = 'Y';
    }
}

// Generates the next Tiny state
void TinyMT::NextState()
{
    u32 y = state[3];
    u32 x = (state[0] & TINYMT32MASK) ^ state[1] ^ state[2];
    x ^= (x << TINYMT32SH0);
    y ^= (y >> TINYMT32SH0) ^ x;
    state[0] = state[1];
    state[1] = state[2];
    state[2] = x ^ (y << TINYMT32SH1);
    state[3] = y;

    if ((y & 1) == 1)
    {
        state[1] ^= MAT1;
        state[2] ^= MAT2;
    }
}

// Calls the next state and next psuedo random number
u32 TinyMT::Nextuint()
{
    NextState();
    return Temper();
}

// Generates the psuedo random number from the Tiny state
u32 TinyMT::Temper()
{
    u32 t0 = state[3];
    u32 t1 = state[0] + (state[2] >> TINYMT32SH8);

    t0 ^= t1;
    if ((t1 & 1) == 1)
        t0 ^= TMAT;
    return t0;
}

// IRNG Memeber
void TinyMT::Reseed(u32 seed)
{
    Initialize(seed);
}
