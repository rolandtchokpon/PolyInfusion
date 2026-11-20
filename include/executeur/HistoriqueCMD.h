
#pragma once
#include "../commande/ApercuCmd.h"
#include "../commande/ConfigCmd.h"
#include "../commande/AideCmd.h"
#include "../commande/InfuserCmd.h"
#include "../commande/NotifCmd.h"
#include "../commande/PortionCmd.h"
#include "../commande/QuitCmd.h"
#include "../commande/RemplirEauCmd.h"
#include "../commande/RemplirTheCmd.h"
#include "../commande/ReserveCmd.h"
#include "../commande/RoutineCmd.h"
#include "../commande/SelectionCmd.h"

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