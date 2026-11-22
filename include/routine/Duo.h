
#pragma once
#include "IRoutine.h"

namespace Routine
{

    class Duo : public IRoutine
    {
    public:
        ~Duo();
        virtual void appliquer(Machine::Systeme *sys) const override;
        virtual void apercu() const override;

    protected:
        Duo();
    };

}