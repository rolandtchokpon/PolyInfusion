
#include "../../include/commande/CmdConfig.h"

namespace CMD
{

    CmdConfig::CmdConfig(const Console::Instruction &inst) : Commande(true, inst) {}

    CmdConfig::~CmdConfig() = default;

    void CmdConfig::executer(Machine::Systeme *sys)
    {
        std::cout << "Thé sélectionné : " << sys->theSelectionne() << std::endl;
        std::cout << "Nombre de portions : " << sys->portions() << std::endl;
    }

    void CmdConfig::undo(Machine::Systeme *sys)
    {
        std::cout << "Ceci n'est pas une commande réversible." << std::endl;
    }

    void CmdConfig::apercu(unsigned int numero = 1)
    {
        std::cout << "La commande suivante sera la seule exécutée" << std::endl;
    }

}