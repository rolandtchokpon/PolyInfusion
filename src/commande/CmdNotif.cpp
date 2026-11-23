
#include "../../include/commande/CmdNotif.h"

namespace CMD
{

    CmdNotif::CmdNotif(const Console::Instruction &inst) : Commande(true, inst) {}

    CmdNotif::~CmdNotif() = default;

    void CmdNotif::executer(Machine::Systeme *sys)
    {
        sys->activerNotifications(instruction_.notificationsActives);
    }

    void CmdNotif::undo(Machine::Systeme *sys)
    {
        std::cout << "Ceci n'est pas une commande réversible." << std::endl;
    }

    void CmdNotif::apercu(unsigned int numero = 1)
    {
        std::cout << "La commande suivante sera la seule exécutée" << std::endl;
    }

}