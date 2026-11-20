
#pragma once
#include "IRoutine.h"

namespace Routine
{

    class Solo : public IRoutine
    {
    public:
        ~Solo();
        virtual void appliquer(Machine::Systeme *sys) const override;

    protected:
        Solo();
    };

}