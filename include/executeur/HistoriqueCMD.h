
#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "../commande/Commande.h"

namespace Execution
{

    class HistoriqueCMD
    {
    public:
        HistoriqueCMD();
        ~HistoriqueCMD();

        void undo(Machine::Systeme *sys);
        void redo(Machine::Systeme *sys);

        void ajouterCmd(std::shared_ptr<CMD::Commande> &cmd);

    private:
        std::shared_ptr<CMD::Commande> dernierUndo_;
        std::vector<std::shared_ptr<CMD::Commande>> cmdReversibles_;
    };

} // namespace Execution