
#include "../../include/commande/CmdQuit.h"

namespace CMD
{

    CmdQuit::CmdQuit() : Commande(false) {}

    CmdQuit::~CmdQuit() = default;

    void CmdQuit::executer(const Console::Instruction &, Machine::Systeme *sys)
    {
        sys->quitter(true);
    }

    void CmdQuit::undo(Machine::Systeme *)
    {
        std::cout << "Ceci n'est pas une commande réversible." << std::endl;
    }

} // namespace CMD