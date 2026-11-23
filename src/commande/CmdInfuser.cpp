
#include "../../include/commande/CmdInfuser.h"

namespace CMD
{

    CmdInfuser::CmdInfuser(const Console::Instruction &inst) : Commande(true, inst) {}

    CmdInfuser::~CmdInfuser() = default;

    void CmdInfuser::executer(Machine::Systeme *sys)
    {
        if (sys->theSelectionne() == "Aucun")
        {
            std::cout << "Erreur : Aucun thé selectionné." << std::endl;
            return;
        }

        sys->infuser();
    }

    void CmdInfuser::undo(Machine::Systeme *sys)
    {
        std::cout << "Ceci n'est pas une commande réversible." << std::endl;
    }

    void CmdInfuser::apercu(unsigned int numero = 1)
    {
        std::cout << "La commande suivante sera la seule exécutée" << std::endl;
    }

}