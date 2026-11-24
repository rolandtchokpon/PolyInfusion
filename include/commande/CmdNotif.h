
#pragma once
#include "Commande.h"

namespace CMD
{
    class CmdNotif : public Commande
    {
    public:
        explicit CmdNotif(bool actives);
        ~CmdNotif();

        virtual void executer(Machine::Systeme *sys) override;

    private:
        bool actives_;
    };

} // namespace CMD
