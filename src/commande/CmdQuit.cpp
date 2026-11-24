
#include <iostream>
#include "../../include/commande/CmdQuit.h"
#include "../../include/systeme/Systeme.h"

namespace CMD
{

    CmdQuit::CmdQuit() {}

    CmdQuit::~CmdQuit() = default;

    void CmdQuit::executer(Machine::Systeme *sys)
    {
        sys->quitter(true);
    }

} // namespace CMD
