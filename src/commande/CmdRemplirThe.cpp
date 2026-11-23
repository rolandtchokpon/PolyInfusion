
#include "../../include/commande/CmdRemplirThe.h"

namespace CMD
{

    CmdRemplirThe::CmdRemplirThe(const Console::Instruction &inst) : Commande(true, inst) {}

    CmdRemplirThe::~CmdRemplirThe() = default;

    void CmdRemplirThe::executer(Machine::Systeme *sys)
    {
        sys->remplirThe(instruction_.the, instruction_.quantite);
    }

    void CmdRemplirThe::undo(Machine::Systeme *sys)
    {
        std::cout << "Ceci n'est pas une commande réversible." << std::endl;
    }

    void CmdRemplirThe::apercu(unsigned int numero = 1)
    {
        std::cout << "La commande suivante sera la seule exécutée" << std::endl;
    }

}