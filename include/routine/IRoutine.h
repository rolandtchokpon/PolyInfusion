
#pragma once
#include "../systeme/Systeme.h"

namespace Routine
{

    class IRoutine
    {
    public:
        virtual ~IRoutine() = 0;
        virtual void appliquer(Machine::Systeme *sys) const = 0;
        virtual void apercu() const = 0;

    protected:
        IRoutine();
    };

}