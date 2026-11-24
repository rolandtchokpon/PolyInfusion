
#include "../../include/commande/CmdConfig.h"

namespace CMD
{

    CmdConfig::CmdConfig() : Commande(false) {}

    CmdConfig::~CmdConfig() = default;

    void CmdConfig::executer(const Console::Instruction &, Machine::Systeme *sys)
    {
        const std::string &the = sys->theSelectionne();

        std::cout << "Thé sélectionné : " << (the.empty() ? "aucun" : the) << "." << std::endl;
        std::cout << "Nombre de portions : " << sys->portions() << "." << std::endl;
    }

    void CmdConfig::undo(Machine::Systeme *)
    {
        std::cout << "Ceci n'est pas une commande réversible." << std::endl;
    }
}