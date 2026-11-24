
#pragma once
#include "Commande.h"

namespace CMD
{
    class CmdInfuser : public Commande
    {
    public:
        CmdInfuser();
        ~CmdInfuser();

        virtual void executer(Machine::Systeme *sys) override;
    };

} // namespace CMD
