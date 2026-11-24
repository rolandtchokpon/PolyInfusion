
#include <iostream>
#include "../../include/commande/CmdInfuser.h"
#include "../../include/systeme/Systeme.h"

namespace CMD
{

    CmdInfuser::CmdInfuser() {}

    CmdInfuser::~CmdInfuser() = default;

    void CmdInfuser::executer(Machine::Systeme *sys)
    {
        const std::string &the = sys->theSelectionne();

        if (the.empty())
        {
            std::cout << "Erreur : aucun thé sélectionné." << std::endl;
            return;
        }

        sys->infuser(the, sys->portions());
    }

} // namespace CMD
