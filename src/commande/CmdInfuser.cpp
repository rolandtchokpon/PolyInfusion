
#include "../../include/commande/CmdInfuser.h"

namespace CMD
{

    CmdInfuser::CmdInfuser() : Commande(false) {}

    CmdInfuser::~CmdInfuser() = default;

    void CmdInfuser::executer(const Console::Instruction &inst, Machine::Systeme *sys)
    {
        const std::string &the = sys->theSelectionne();

        if (the.empty())
        {
            std::cout << "Erreur : aucun thé sélectionné." << std::endl;
            return;
        }

        for (unsigned int i = 0; i < sys->portions(); ++i)
            sys->infuser(the);
    }

    void CmdInfuser::undo(Machine::Systeme *sys)
    {
        std::cout << "Ceci n'est pas une commande réversible." << std::endl;
    }
}