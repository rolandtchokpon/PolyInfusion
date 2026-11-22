
#include "../../include/commande/CmdApercu.h"

namespace CMD
{

    CmdApercu::CmdApercu() : Commande(false) {}

    CmdApercu::~CmdApercu() = default;

    void CmdApercu::executer(const Console::Instruction &inst, Machine::Systeme *sys)
    {
        // TODO
        std::cout << "Implémentation de <<apercu>>  à faire" << std::endl;
    }

    void CmdApercu::undo(Machine::Systeme *sys)
    {
        std::cout << "Ceci n'est pas une commande réversible." << std::endl;
    }
}