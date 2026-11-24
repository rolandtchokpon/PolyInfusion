
#include "../../include/commande/CmdInfuser.h"

namespace CMD
{

    CmdInfuser::CmdInfuser() : Commande(false) {}

    CmdInfuser::~CmdInfuser() = default;

    void CmdInfuser::executer(const Console::Instruction &, Machine::Systeme *sys)
    {
        const std::string &the = sys->theSelectionne();

        if (the.empty())
        {
            std::cout << "Erreur : aucun thé sélectionné." << std::endl;
            return;
        }

        sys->infuser(the, sys->portions());
    }

    void CmdInfuser::undo(Machine::Systeme *)
    {
        std::cout << "Ceci n'est pas une commande réversible." << std::endl;
    }
}