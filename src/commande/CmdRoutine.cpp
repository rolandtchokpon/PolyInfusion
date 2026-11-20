
#include "../../include/commande/CmdRoutine.h"

namespace CMD
{

    CmdRoutine::CmdRoutine() : Commande(true) {}

    CmdRoutine::~CmdRoutine() = default;

    void CmdRoutine::executer(const Console::Instruction &inst, Machine::Systeme *sys)
    {
        Machine::Routine r;
        r = lireRoutine(inst.routine);
        sys->appliquerRoutine(r);
    }

    Machine::Routine CmdRoutine::lireRoutine(const std::string &r)
    {
        if (r == "solo")
        {
            return Machine::Solo();
        }
        else if (r == "duo")
        {
            return Machine::Duo();
        }
        else if (r == "matin")
        {
            return Machine::Matin();
        }

        return Machine::Routine();
    }

    void undo(Machine::Systeme *sys)
    {
        // TODO
    }

} // namespace CMD