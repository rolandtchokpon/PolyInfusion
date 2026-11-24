
#pragma once
#include "Commande.h"

namespace CMD
{
    class CmdQuit : public Commande
    {
    public:
        CmdQuit();
        ~CmdQuit();

        virtual void executer(Machine::Systeme *sys) override;
    };

} // namespace CMD
