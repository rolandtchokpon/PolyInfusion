
#pragma once
#include <memory>
#include "Commande.h"

namespace CMD
{
    class CmdApercu : public Commande
    {
    public:
        explicit CmdApercu(const std::shared_ptr<Commande> &routine);
        ~CmdApercu();

        virtual void executer(const Console::Instruction &inst, Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;

    private:
        std::shared_ptr<Commande> routine_;
    };

} // namespace CMD
