
#include "../../include/commande/CmdSelection.h"

namespace CMD
{

    CmdSelection::CmdSelection() : Commande(true) {}

    CmdSelection::~CmdSelection() = default;

    void CmdSelection::executer(const Console::Instruction &inst, Machine::Systeme *sys)
    {
        instruction_ = inst;
        theAvant_ = sys->theSelectionne();
        sys->modifierTheSelectionne(inst.the);
        compteur_++;

        if (compteur_ == 1)
            std::cout << "Thé sélectionné : " << sys->theSelectionne() << std::endl;
    }

    void CmdSelection::undo(Machine::Systeme *sys)
    {
        sys->modifierTheSelectionne(theAvant_);
    }
}