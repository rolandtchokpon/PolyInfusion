
#include <iostream>
#include "../../include/commande/CmdConfig.h"
#include "../../include/systeme/Systeme.h"

namespace CMD
{

    CmdConfig::CmdConfig() {}

    CmdConfig::~CmdConfig() = default;

    void CmdConfig::executer(Machine::Systeme *sys)
    {
        const std::string &the = sys->theSelectionne();

        std::cout << "Thé sélectionné : " << (the.empty() ? "aucun" : the) << "." << std::endl;
        std::cout << "Nombre de portions : " << sys->portions() << "." << std::endl;
    }

} // namespace CMD
