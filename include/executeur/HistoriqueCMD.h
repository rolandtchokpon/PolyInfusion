
#pragma once
#include <memory>
#include <vector>
#include "../commande/CmdReglage.h"

namespace Execution
{

    // Historique des changements de réglages (undo / redo). Il ne connaît que CmdReglage.
    class HistoriqueCMD
    {
    public:
        HistoriqueCMD();
        ~HistoriqueCMD();

        void undo(Machine::Systeme *sys);
        void redo(Machine::Systeme *sys);

        // À appeler après l'exécution réussie d'un changement de réglage.
        void ajouterCmd(const std::shared_ptr<CMD::CmdReglage> &cmd);

    private:
        std::vector<std::shared_ptr<CMD::CmdReglage>> pileAnnulation_;
        std::vector<std::shared_ptr<CMD::CmdReglage>> pileRetablissement_;
    };

} // namespace Execution
