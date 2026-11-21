
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

    class Historique
    {
    public:
        Historique();
        ~Historique();

        void undo(Machine::Systeme *sys);
        void redo(Machine::Systeme *sys);

        void ajouter(std::shared_ptr<::Commande> &);

    private:
        std::shared_ptr<::Commande> dernierUndo_;
        std::vector<std::shared_ptr<::Commande>> Reversibles_;
    };

} // namespace Execution