
#pragma once
#include "IRoutine.h"

namespace Routine
{

    class Matin : public IRoutine
    {
    public:
        Matin();
        ~Matin();
        virtual void appliquer(Machine::Systeme *sys) const override;

    };

}