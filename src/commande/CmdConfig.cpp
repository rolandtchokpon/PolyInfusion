
#include "../../include/commande/CmdConfig.h"

namespace CMD
{

    CmdConfig::CmdConfig() : Commande(false) {}

    CmdConfig::~CmdConfig() = default;

    void CmdConfig::executer(const Console::Instruction &inst, Machine::Systeme *sys)
    {
        // TODO
        std::cout << "Implémentation de <<configuration>> à faire" << std::endl;
    }

    void undo(Machine::Systeme *sys)
    {
        std::cout << "Ceci n'est pas une commande réversible." << std::endl;
    }
}