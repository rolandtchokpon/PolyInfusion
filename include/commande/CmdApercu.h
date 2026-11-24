
#pragma once
#include <memory>
#include "CmdReglage.h"

namespace CMD
{
    class CmdApercu : public Commande
    {
    public:
        explicit CmdApercu(const std::shared_ptr<CmdReglage> &routine);
        ~CmdApercu();

        virtual void executer(Machine::Systeme *sys) override;

    private:
        std::shared_ptr<CmdReglage> routine_;
    };

} // namespace CMD
