
#include "../../include/commande/CmdReserve.h"

namespace CMD
{

    CmdReserve::CmdReserve(const Console::Instruction& inst) : Commande(true, inst) {}

    CmdReserve::~CmdReserve() = default;

    void CmdReserve::executer(Machine::Systeme *sys)
    {
        sys->afficherReserves();
    }

    void CmdReserve::undo(Machine::Systeme *sys)
    {
        std::cout << "Ceci n'est pas une commande réversible." << std::endl;
    }

    void CmdReserve::apercu(unsigned int numero = 1)
    {
        std::cout << "La commande suivante sera la seule exécutée" << std::endl;
    }

}