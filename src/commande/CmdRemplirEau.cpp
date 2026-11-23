
#include "../../include/commande/CmdRemplirEau.h"

namespace CMD
{

    CmdRemplirEau::CmdRemplirEau() : Commande(false) {}

    CmdRemplirEau::~CmdRemplirEau() = default;

    void CmdRemplirEau::executer(const Console::Instruction &inst, Machine::Systeme *sys)
    {
        sys->remplirEau(inst.quantite);
    }

    void CmdRemplirEau::undo(Machine::Systeme *sys)
    {
        std::cout << "Ceci n'est pas une commande réversible." << std::endl;
    }
}