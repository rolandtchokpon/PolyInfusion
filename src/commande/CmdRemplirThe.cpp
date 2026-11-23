
#include "../../include/commande/CmdRemplirThe.h"

namespace CMD
{

    CmdRemplirThe::CmdRemplirThe() : Commande(false) {}

    CmdRemplirThe::~CmdRemplirThe() = default;

    void CmdRemplirThe::executer(const Console::Instruction &inst, Machine::Systeme *sys)
    {
        sys->remplirThe(inst.the, inst.quantite);
    }

    void CmdRemplirThe::undo(Machine::Systeme *sys)
    {
        std::cout << "Ceci n'est pas une commande réversible." << std::endl;
    }
}