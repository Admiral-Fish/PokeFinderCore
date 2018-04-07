#ifndef SEARCHER4_HPP
#define SEARCHER4_HPP

#include <PokeFinderCore/Objects/Searcher.hpp>
#include <PokeFinderCore/Gen4/Frame4.hpp>

class Searcher4 : public Searcher
{
public:
    Searcher4();
    Searcher4(u16 tid, u16 sid, u32 ratio, FrameCompare compare, Method method);
    vector<Frame4> search(u32 hp, u32 atk, u32 def, u32 spa, u32 spd, u32 spe);

private:
    Frame4 frame = Frame4(0, 0, 0);
    FrameCompare compare;
};

#endif // SEARCHER4_HPP
