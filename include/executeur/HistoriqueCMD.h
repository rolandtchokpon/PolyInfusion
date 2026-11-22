
#pragma once
#include "../commande/CmdApercu.h"
#include "../commande/CmdConfig.h"
#include "../commande/CmdAide.h"
#include "../commande/CmdInfuser.h"
#include "../commande/CmdNotif.h"
#include "../commande/CmdPortion.h"
#include "../commande/CmdQuit.h"
#include "../commande/CmdRemplirEau.h"
#include "../commande/CmdRemplirThe.h"
#include "../commande/CmdReserve.h"
#include "../commande/CmdRoutine.h"
#include "../commande/CmdSelection.h"

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
        std::vector<std::shared_ptr<CMD::Commande>> pileUndo_;
        std::vector<std::shared_ptr<CMD::Commande>> pileRedo_;
    };

} // namespace Execution