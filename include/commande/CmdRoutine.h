
#pragma once
#include <memory>
#include "Commande.h"
#include "../routine/IRoutine.h"

namespace CMD
{
    class CmdRoutine : public Commande
    {
    public:
        CmdRoutine();
        ~CmdRoutine();

        virtual void executer(const Console::Instruction &inst, Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;

    private:
        std::shared_ptr<Routine::IRoutine> lireRoutine(const std::string &r);
        std::shared_ptr<Routine::IRoutine> routine_;
    };

} // namespace CMD
