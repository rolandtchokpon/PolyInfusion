
#include "../../include/executeur/HistoriqueCMD.h"

namespace Execution
{

    HistoriqueCMD::HistoriqueCMD()
    {
        pileRedo_.clear();
        pileUndo_.clear();
    }

    HistoriqueCMD::~HistoriqueCMD() = default;

    void HistoriqueCMD::ajouterCmd(std::shared_ptr<CMD::Commande> &cmd)
    {
        pileUndo_.push_back(cmd);
        pileRedo_.clear(); // une nouvelle commande invalide les redo
    }

    void HistoriqueCMD::undo(Machine::Systeme *sys)
    {
        if (pileUndo_.empty())
        {
            std::cout << "Erreur : aucune opération à annuler." << std::endl;
            return;
        }

        std::shared_ptr<CMD::Commande> cmd = pileUndo_.back();
        pileUndo_.pop_back();

        cmd->undo(sys);
        pileRedo_.push_back(cmd);

        std::cout << "Opération annulée." << std::endl;
    }

    void HistoriqueCMD::redo(Machine::Systeme *sys)
    {
        if (pileRedo_.empty())
        {
            std::cout << "Erreur : aucune opération à rétablir." << std::endl;
            return;
        }

        std::shared_ptr<CMD::Commande> cmd = pileRedo_.back();
        pileRedo_.pop_back();

        cmd->executer(cmd->sauvgarde(), sys);
        pileUndo_.push_back(cmd); // directement, sans passer par ajouterCmd

        std::cout << "Opération rétablie." << std::endl;
    }

}