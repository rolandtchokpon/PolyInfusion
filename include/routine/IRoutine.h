
#pragma once
#include "../systeme/Systeme.h"

namespace Routine
{

    class IRoutine
    {
    public:
        virtual ~IRoutine() = 0;
        virtual void appliquer(Machine::Systeme *sys, bool afficherModif) const = 0;
        virtual void apercu() const = 0;

    protected:
        IRoutine(unsigned int portions, std::string the);
        unsigned int portions_;
        std::string the_;
    };

}