
#pragma once
#include "IRoutine.h"

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