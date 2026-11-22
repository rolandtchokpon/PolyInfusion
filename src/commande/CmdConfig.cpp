
#include "../../include/commande/CmdConfig.h"

namespace CMD
{

    CmdConfig::CmdConfig() : Commande(false) {}

    CmdConfig::~CmdConfig() = default;

    void CmdConfig::executer(const Console::Instruction &inst, Machine::Systeme *sys)
    {
        std::cout << "Thé sélectionné : " << sys->theSelectionne() << std::endl;
        std::cout << "Nombre de portions : " << sys->portions() << std::endl;
    }

    void CmdConfig::undo(Machine::Systeme *sys)
    {
        std::cout << "Ceci n'est pas une commande réversible." << std::endl;
    }
}