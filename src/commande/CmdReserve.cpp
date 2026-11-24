
#include <iostream>
#include "../../include/commande/CmdReserve.h"
#include "../../include/systeme/Systeme.h"

namespace CMD
{

    CmdReserve::CmdReserve() {}

    CmdReserve::~CmdReserve() = default;

    void CmdReserve::executer(Machine::Systeme *sys)
    {
        sys->afficherReserves();
    }

} // namespace CMD
