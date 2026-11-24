
#include <iostream>
#include "../../include/commande/CmdNotif.h"
#include "../../include/systeme/Systeme.h"

namespace CMD
{

    CmdNotif::CmdNotif(bool actives) : actives_(actives) {}

    CmdNotif::~CmdNotif() = default;

    void CmdNotif::executer(Machine::Systeme *sys)
    {
        sys->activerNotifications(actives_);
    }

} // namespace CMD
