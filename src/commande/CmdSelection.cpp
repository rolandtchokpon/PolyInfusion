
#include "../../include/commande/CmdSelection.h"

namespace CMD
{

    CmdSelection::CmdSelection() : Commande(true) {}

    CmdSelection::~CmdSelection() = default;

    void CmdSelection::executer(const Console::Instruction &inst, Machine::Systeme *sys)
    {
        ancienThe_ = sys->theSelectionne();
        nouveauThe_ = inst.the;

        sys->modifierTheSelectionne(nouveauThe_);
        std::cout << "Thé sélectionné : " << nouveauThe_ << "." << std::endl;
    }

    void CmdSelection::undo(Machine::Systeme *sys) { sys->modifierTheSelectionne(ancienThe_); }

    void CmdSelection::redo(Machine::Systeme *sys) { sys->modifierTheSelectionne(nouveauThe_); }

} // namespace CMD
