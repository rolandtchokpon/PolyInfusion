
#include "../../include/commande/CmdSelection.h"

namespace CMD
{

    CmdSelection::CmdSelection() : Commande(true) {}

    CmdSelection::~CmdSelection() = default;

    void CmdSelection::executer(const Console::Instruction &inst, Machine::Systeme *sys)
    {
        sys->modifierTheSelectionne(inst.the);
    }

    void undo(Machine::Systeme *sys)
    {
        // TOOO
    }
}