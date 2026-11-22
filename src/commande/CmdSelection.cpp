
#include "../../include/commande/CmdSelection.h"

namespace CMD
{

    CmdSelection::CmdSelection() : Commande(true) {}

    CmdSelection::~CmdSelection() = default;

    void CmdSelection::executer(const Console::Instruction &inst, Machine::Systeme *sys)
    {
        instruction_ = inst;

        theAvant_ = sys->theSelectionne();
        sys->modifierTheSelectionne(inst.the, afficherModif_);

        afficherModif_ = false;
    }

    void CmdSelection::undo(Machine::Systeme *sys)
    {
        sys->modifierTheSelectionne(theAvant_, afficherModif_);
    }
}