
#pragma once
#include "Commande.h"

namespace CMD
{
    class CmdConfig : public Commande
    {
    public:
        CmdConfig();
        ~CmdConfig();

        virtual void executer(Machine::Systeme *sys) override;
    };

} // namespace CMD
