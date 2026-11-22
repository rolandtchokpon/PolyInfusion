
#pragma once
#include "IRoutine.h"

namespace Routine
{

    class Solo : public IRoutine
    {
    public:
        virtual ~Solo();
        Solo();

        virtual void appliquer(Machine::Systeme *sys, bool afficherModif) const override;
        virtual void apercu() const override;
    };

}