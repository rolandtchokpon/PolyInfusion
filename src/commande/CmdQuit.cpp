
#include "../../include/commande/CmdQuit.h"

namespace CMD
{

    CmdQuit::CmdQuit(const Console::Instruction &inst) : Commande(true, inst) {}

    CmdQuit::~CmdQuit() = default;

    void CmdQuit::executer(Machine::Systeme *sys)
    {
        sys->quitter(true);
    }

    void CmdQuit::undo(Machine::Systeme *sys)
    {
        std::cout << "Ceci n'est pas une commande réversible." << std::endl;
    }

    void CmdQuit::apercu(unsigned int numero = 1)
    {
        std::cout << "La commande suivante sera la seule exécutée" << std::endl;
    }

} // namespace CMD