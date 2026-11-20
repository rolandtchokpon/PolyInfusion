
#pragma once
#include "IRoutine.h"

namespace Routine
{

    class Duo : public IRoutine
    {
    public:
        ~Duo();
        virtual void appliquer(Machine::Systeme *sys) const override;

    protected:
        Duo();
    };

}