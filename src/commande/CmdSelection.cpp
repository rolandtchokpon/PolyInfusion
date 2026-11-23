
#include "../../include/commande/CmdSelection.h"

namespace CMD
{

    CmdSelection::CmdSelection(const std::string &the) : Commande(true), nouveauThe_(the) {}

    CmdSelection::~CmdSelection() = default;

    void CmdSelection::executer(const Console::Instruction &, Machine::Systeme *sys)
    {
        ancienThe_ = sys->theSelectionne();

        sys->modifierTheSelectionne(nouveauThe_);
        std::cout << "Thé sélectionné : " << nouveauThe_ << "." << std::endl;
    }

    void CmdSelection::undo(Machine::Systeme *sys) { sys->modifierTheSelectionne(ancienThe_); }

    void CmdSelection::redo(Machine::Systeme *sys) { sys->modifierTheSelectionne(nouveauThe_); }

    void CmdSelection::apercu(std::vector<std::string> &lignes) const
    {
        lignes.push_back("Sélectionner le thé " + nouveauThe_ + ".");
    }

    std::shared_ptr<Commande> CmdSelection::cloner() const { return std::make_shared<CmdSelection>(nouveauThe_); }

} // namespace CMD
