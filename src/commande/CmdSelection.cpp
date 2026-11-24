
#include <iostream>
#include "../../include/commande/CmdSelection.h"
#include "../../include/commande/IterateurFeuille.h"
#include "../../include/systeme/Systeme.h"

namespace CMD
{

    CmdSelection::CmdSelection(const std::string &the) : nouveauThe_(the) {}

    CmdSelection::~CmdSelection() = default;

    void CmdSelection::executer(Machine::Systeme *sys)
    {
        ancienThe_ = sys->theSelectionne();

        sys->modifierTheSelectionne(nouveauThe_);
        std::cout << "Thé sélectionné : " << nouveauThe_ << "." << std::endl;
    }

    void CmdSelection::undo(Machine::Systeme *sys) { sys->modifierTheSelectionne(ancienThe_); }

    void CmdSelection::redo(Machine::Systeme *sys) { sys->modifierTheSelectionne(nouveauThe_); }

    std::string CmdSelection::description() const { return "Sélectionner le thé " + nouveauThe_ + "."; }

    std::unique_ptr<IterateurReglage> CmdSelection::creerIterateur() const { return std::make_unique<IterateurFeuille>(*this); }

    std::shared_ptr<CmdReglage> CmdSelection::cloner() const { return std::make_shared<CmdSelection>(nouveauThe_); }

} // namespace CMD
