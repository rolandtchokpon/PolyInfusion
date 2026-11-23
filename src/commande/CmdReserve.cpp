
#include "../../include/commande/CmdReserve.h"

namespace CMD
{

    CmdReserve::CmdReserve() : Commande(false) {}

    CmdReserve::~CmdReserve() = default;

    void CmdReserve::executer(const Console::Instruction &inst, Machine::Systeme *sys)
    {
        sys->afficherReserves();
    }

    void CmdReserve::undo(Machine::Systeme *sys)
    {
        std::cout << "Ceci n'est pas une commande réversible." << std::endl;
    }
}