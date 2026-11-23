
#include "../../include/commande/CmdSelection.h"

namespace CMD
{

    CmdSelection::CmdSelection(const Console::Instruction &inst) : Commande(true, inst) {}

    CmdSelection::~CmdSelection() = default;

    void CmdSelection::executer(Machine::Systeme *sys)
    {
        theAvant_ = sys->theSelectionne();
        sys->modifierTheSelectionne(instruction_.the, afficherModif_);

        afficherModif_ = false;
    }

    void CmdSelection::undo(Machine::Systeme *sys)
    {
        sys->modifierTheSelectionne(theAvant_, afficherModif_);
    }

    void CmdSelection::apercu(unsigned int numero = 1)
    {
        std::cout << "La commande suivante sera la seule exécutée" << std::endl;
    }

}