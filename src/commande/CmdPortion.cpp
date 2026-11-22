
#include "../../include/commande/CmdPortion.h"

namespace CMD
{

    CmdPortion::CmdPortion() : Commande(true) {}

    CmdPortion::~CmdPortion() = default;

    void CmdPortion::executer(const Console::Instruction &inst, Machine::Systeme *sys)
    {
        instruction_ = inst;
        portionsAvant_ = sys->portions();
        sys->modifierPortions(inst.portions);
        compteur_++;

        if (compteur_ == 1)
            std::cout << "Nombre de portions : " << sys->portions() << std::endl;
    }

    void CmdPortion::undo(Machine::Systeme *sys)
    {
        sys->modifierPortions(portionsAvant_);
    }
}