
#pragma once
#include "IRoutine.h"
#include "../systeme/Systeme.h"

namespace Routine
{

    class Duo : public IRoutine
    {
    public:
        virtual ~Duo();
        Duo();

        virtual void appliquer(Machine::Systeme *sys, bool afficherModif) const override;
        virtual void apercu() const override;
    };

}