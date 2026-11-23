
#include "../../include/commande/CmdPortion.h"

namespace CMD
{

    CmdPortion::CmdPortion(const Console::Instruction &inst) : Commande(true, inst) {}

    CmdPortion::~CmdPortion() = default;

    void CmdPortion::executer(Machine::Systeme *sys)
    {
        portionsAvant_ = sys->portions();
        sys->modifierPortions(instruction_.portions, afficherModif_);

        afficherModif_ = false;
    }

    void CmdPortion::undo(Machine::Systeme *sys)
    {
        sys->modifierPortions(portionsAvant_, afficherModif_);
    }

    void CmdPortion::apercu(unsigned int numero = 1)
    {
        std::cout << "La commande suivante sera la seule exécutée" << std::endl;
    }

}