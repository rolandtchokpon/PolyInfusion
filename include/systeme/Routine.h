
#pragma once
#include "TypeRoutine.h"

namespace Machine
{

    struct Routine
    {
        TypeRoutine type;
        std::string the;
        unsigned int portions;
    };

    struct Solo : public Routine
    {
        Solo()
        {
            type = TypeRoutine::Solo;
            the = "vert";
            portions = 1;
        };
    };

    struct Duo : public Routine
    {
        Duo()
        {
            type = TypeRoutine::Duo;
            the = "noir";
            portions = 2;
        };
    };

    struct Matin : public Routine
    {
        Matin()
        {
            the = "oolong";
        }
    };

} // namespace Machine