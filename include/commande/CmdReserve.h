
#pragma once
#include "Commande.h"

namespace CMD
{
    class CmdReserve : public Commande
    {
    public:
        CmdReserve();
        ~CmdReserve();

        virtual void executer(Machine::Systeme *sys) override;
    };

} // namespace CMD
