
#include "../../include/commande/CmdRoutine.h"

namespace CMD
{

    CmdRoutine::CmdRoutine(const Console::Instruction& inst) : Commande(true, inst) {}

    CmdRoutine::~CmdRoutine() = default;

    void CmdRoutine::executer(Machine::Systeme *sys)
    {
        portionsAvant_ = sys->portions();
        theAvant_ = sys->theSelectionne();

        auto routine = lireRoutine(instruction_.routine);
        sys->appliquerRoutine(routine, afficherModif_);

        if (afficherModif_)
            std::cout << "Routine appliquée : " << instruction_.routine << std::endl;

        afficherModif_ = false;
    }

    void CmdRoutine::undo(Machine::Systeme *sys)
    {
        sys->modifierPortions(portionsAvant_, afficherModif_);
        sys->modifierTheSelectionne(theAvant_, afficherModif_);
    }

} // namespace CMD