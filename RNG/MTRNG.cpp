#include "MTRNG.hpp"

// Mersenne Twister

// Constructor for Mersenne Twister
MersenneTwister::MersenneTwister(u32 seed)
{
    Initialize(seed);
}

void MersenneTwister::AdvanceFrames(int frames)
{
    index += frames;
    while (index >= 624)
    {
        index -= 624;
        Shuffle();
    }
}

// Initializes
void MersenneTwister::Initialize(u32 seed)
{
    mt[0] = seed;

    for (index = 1; index < N; index++)
        mt[index] = (0x6C078965*(mt[index - 1] ^ (mt[index - 1] >> 30)) + index);
}

void MersenneTwister::Shuffle()
{
    u32 y;
    int kk = 0;

    for (; kk < 227; ++kk)
    {
        y = (mt[kk] & UPPERMASK) | (mt[kk + 1] & LOWERMASK);
        mt[kk] = mt[kk + M] ^ (y >> 1) ^ mag01[y & 0x1];
    }

    for (; kk < 623; ++kk)
    {
        y = (mt[kk] & UPPERMASK) | (mt[kk + 1] & LOWERMASK);
        mt[kk] = mt[kk - 227] ^ (y >> 1) ^ mag01[y & 0x1];
    }

    y = (mt[623] & UPPERMASK) | (mt[0] & LOWERMASK);
    mt[623] = mt[396] ^ (y >> 1) ^ mag01[y & 0x1];
}

// Calls the next psuedo-random number
u32 MersenneTwister::Nextuint()
{
    // Array reshuffle check
    if (index >= N)
    {
        Shuffle();
        index = 0;
    }

    u32 y = mt[index++];
    y ^= TemperingShiftU(y);
    y ^= TemperingShiftS(y) & TEMPERINGMASKB;
    y ^= TemperingShiftT(y) & TEMPERINGMASKC;
    y ^= TemperingShiftL(y);

    return y;
}

// Recreates the Mersenne Twister with a new seed
void MersenneTwister::Reseed(u32 seed)
{
    Initialize(seed);
}


// Mersenne Twister Untempered

// Constructor for Mersenne Twister Untempered 
MersenneTwisterUntempered::MersenneTwisterUntempered(u32 seed)
{
    Initialize(seed);
}

void MersenneTwisterUntempered::AdvanceFrames(int frames)
{
    index += frames;
    while (index >= 624)
    {
        index -= 624;
        Shuffle();
    }
}

// Initializes
void MersenneTwisterUntempered::Initialize(u32 seed)
{
    mt[0] = seed;

    for (index = 1; index < N; index++)
        mt[index] = (0x6C078965*(mt[index - 1] ^ (mt[index - 1] >> 30)) + index);
}

void MersenneTwisterUntempered::Shuffle()
{
    int kk = 0;
    u32 y;

    for (; kk < 227; ++kk)
    {
        y = (mt[kk] & UPPERMASK) | (mt[kk + 1] & LOWERMASK);
        mt[kk] = mt[kk + M] ^ (y >> 1) ^ mag01[y & 0x1];
    }

    for (; kk < 623; ++kk)
    {
        y = (mt[kk] & UPPERMASK) | (mt[kk + 1] & LOWERMASK);
        mt[kk] = mt[kk - 227] ^ (y >> 1) ^ mag01[y & 0x1];
    }

    y = (mt[623] & UPPERMASK) | (mt[0] & LOWERMASK);
    mt[623] = mt[396] ^ (y >> 1) ^ mag01[y & 0x1];
}

// Calls the next psuedo-random number
u32 MersenneTwisterUntempered::Nextuint()
{
    // Array reshuffle check
    if (index >= N)
    {
        Shuffle();
        index = 0;
    }

    return mt[index++];
}

// Recreates the Mersenne Twister Untempered with a new seed
void MersenneTwisterUntempered::Reseed(u32 seed)
{
    Initialize(seed);
}


// Mersenne Twister Fast

// Constructor for Mersenne Twister Fast
MersenneTwisterFast::MersenneTwisterFast(u32 seed, int calls)
{
    maxCalls = calls;
    
    if (maxCalls > 227)
    {
        return;
        //Throw an error eventually
    }
    max = M + maxCalls;
    Initialize(seed);
}

void MersenneTwisterFast::AdvanceFrames(int frames)
{
	index += frames;
    while (index >= max)
    {
        index -= max;
        Shuffle();
    }
}

// Initializes
void MersenneTwisterFast::Initialize(u32 seed)
{
    mt[0] = seed;

    for (index = 1; index < max; ++index)
        mt[index] = (0x6C078965*(mt[index - 1] ^ (mt[index - 1] >> 30)) + index);
}

void MersenneTwisterFast::Shuffle()
{
    u32 y;
    int kk = 0;

    for (; kk < maxCalls; ++kk)
    {
        y = (mt[kk] & UPPERMASK) | (mt[kk + 1] & LOWERMASK);
        mt[kk] = mt[kk + M] ^ (y >> 1) ^ mag01[y & 0x1];
    }
}

// Calls the next psuedo-random number
u32 MersenneTwisterFast::Nextuint()
{
    // Array reshuffle check
    if (index >= max)
    {
        Shuffle();
        index = 0;
    }

    u32 y = mt[index++];
    y ^= TemperingShiftU(y);
    y ^= TemperingShiftS(y) & TEMPERINGMASKB;
    y ^= TemperingShiftT(y) & TEMPERINGMASKC2;

    return y;
}

// Recreates the Mersenne Twister Fast with a new seed
void MersenneTwisterFast::Reseed(u32 seed)
{
    Initialize(seed);
}
