
#include <iostream>
#include "../../include/executeur/HistoriqueCMD.h"

namespace Execution
{

    HistoriqueCMD::HistoriqueCMD() = default;

    HistoriqueCMD::~HistoriqueCMD() = default;

    void HistoriqueCMD::ajouterCmd(const std::shared_ptr<CMD::CmdReglage> &cmd)
    {
        pileAnnulation_.push_back(cmd);

        // Une nouvelle opération réversible supprime les possibilités de rétablissement.
        pileRetablissement_.clear();
    }

    void HistoriqueCMD::undo(Machine::Systeme *sys)
    {
        if (pileAnnulation_.empty())
        {
            std::cout << "Erreur : aucune opération à annuler." << std::endl;
            return;
        }

        std::shared_ptr<CMD::CmdReglage> cmd = pileAnnulation_.back();
        pileAnnulation_.pop_back();

        cmd->undo(sys);
        pileRetablissement_.push_back(cmd);

        std::cout << "Opération annulée." << std::endl;
    }

    void HistoriqueCMD::redo(Machine::Systeme *sys)
    {
        if (pileRetablissement_.empty())
        {
            std::cout << "Erreur : aucune opération à rétablir." << std::endl;
            return;
        }

        std::shared_ptr<CMD::CmdReglage> cmd = pileRetablissement_.back();
        pileRetablissement_.pop_back();

        cmd->redo(sys);
        pileAnnulation_.push_back(cmd);

        std::cout << "Opération rétablie." << std::endl;
    }

} // namespace Execution
