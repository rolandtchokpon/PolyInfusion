
#include "../../include/commande/CmdApercu.h"

namespace CMD
{

    CmdApercu::CmdApercu(const Console::Instruction &inst) : Commande(true, inst) {}

    CmdApercu::~CmdApercu() = default;

    void CmdApercu::executer(Machine::Systeme *sys)
    {
        // TODO
        auto r = lireRoutine(instruction_.routine);

        r->apercu();
    }

    void CmdApercu::undo(Machine::Systeme *sys)
    {
        std::cout << "Ceci n'est pas une commande réversible." << std::endl;
    }

    void CmdApercu::apercu(unsigned int numero = 1)
    {
        // TODO
    }

}