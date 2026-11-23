
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

        // À appeler après l'exécution réussie d'une commande réversible.
        void ajouterCmd(const std::shared_ptr<CMD::Commande> &cmd);

    private:
        std::vector<std::shared_ptr<CMD::Commande>> pileAnnulation_;
        std::vector<std::shared_ptr<CMD::Commande>> pileRetablissement_;
    };

} // namespace Execution
