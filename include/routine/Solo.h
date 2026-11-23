
#pragma once
#include "IRoutine.h"
#include "../systeme/Systeme.h"

namespace Routine
{

    class Solo : public IRoutine
    {
    public:
        virtual ~Solo();
        Solo();

        void virtual executer(Machine::Systeme *sys) override;
        void virtual undo(Machine::Systeme *sys) override;
        virtual void apercu(unsigned int numero = 1) override;
    };

}