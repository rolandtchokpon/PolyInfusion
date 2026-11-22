
#pragma once
#include "IRoutine.h"
#include "../systeme/Systeme.h"

namespace Routine
{

    class Matin : public IRoutine
    {
    public:
        virtual ~Matin();
        Matin();

        virtual void appliquer(Machine::Systeme *sys, bool afficherModif) const override;
        virtual void apercu() const override;
    };

}