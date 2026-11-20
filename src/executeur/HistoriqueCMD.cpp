
#include "../../include/executeur/HistoriqueCMD.h"

namespace Execution
{

    HistoriqueCMD::HistoriqueCMD()
    {
        dernierUndo_.reset();
        cmdReversibles_.clear();
    }

    HistoriqueCMD::~HistoriqueCMD() = default;

    void HistoriqueCMD::ajouterCmd(std::shared_ptr<CMD::Commande> &cmd) { cmdReversibles_.push_back(cmd); }

    void HistoriqueCMD::undo(Machine::Systeme *sys)
    {
        if (!cmdReversibles_.empty())
        {
            dernierUndo_ = cmdReversibles_.back();
            cmdReversibles_.pop_back();
            dernierUndo_->undo(sys);
            return;
        }

        std::cout << "Erreur : aucune opération à annuler." << std::endl;
    }

    void HistoriqueCMD::redo(Machine::Systeme *sys)
    {
        if (dernierUndo_ != nullptr)
        {
            dernierUndo_->executer(dernierUndo_->sauvgarde(), sys);
            dernierUndo_ = nullptr;
            return;
        }

        std::cout << "Erreur : aucune opération à rétablir." << std::endl;
    }

}