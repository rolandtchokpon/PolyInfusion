
#include "../../include/commande/CmdRemplirEau.h"

namespace CMD
{

    CmdRemplirEau::CmdRemplirEau(const Console::Instruction &inst) : Commande(true, inst) {}

    CmdRemplirEau::~CmdRemplirEau() = default;

    void CmdRemplirEau::executer(Machine::Systeme *sys)
    {
        sys->remplirEau(instruction_.quantite);
    }

    void CmdRemplirEau::undo(Machine::Systeme *sys)
    {
        std::cout << "Ceci n'est pas une commande réversible." << std::endl;
    }

    void CmdRemplirEau::apercu(unsigned int numero = 1)
    {
        std::cout << "La commande suivante sera la seule exécutée" << std::endl;
    }

}