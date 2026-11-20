
#include "../../include/commande/CmdNotif.h"

namespace CMD
{

    CmdNotif::CmdNotif() : Commande(false) {}

    CmdNotif::~CmdNotif() = default;

    void CmdNotif::executer(const Console::Instruction &inst, Machine::Systeme *sys)
    {
        sys->activerNotifications(inst.notificationsActives);
    }

    void undo(Machine::Systeme *sys)
    {
        std::cout << "Ceci n'est pas une commande réversible." << std::endl;
    }
}