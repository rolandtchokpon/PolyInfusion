
#include "../../include/commande/CmdRoutine.h"
#include "../../include/routine/Solo.h"
#include "../../include/routine/Duo.h"
#include "../../include/routine/Matin.h"

namespace CMD
{

    CmdRoutine::CmdRoutine() : Commande(true) {}

    CmdRoutine::~CmdRoutine() = default;

    void CmdRoutine::executer(const Console::Instruction &inst, Machine::Systeme *sys)
    {
        routine_ = lireRoutine(inst.routine);

        if (!routine_)
        {
            std::cout << "Erreur : routine inconnue." << std::endl;
            return;
        }

        sys->appliquerRoutine(routine_);
    }

    std::shared_ptr<Routine::IRoutine> CmdRoutine::lireRoutine(const std::string &r)
    {
        if (r == "solo")
            return std::make_shared<Routine::Solo>();
        if (r == "duo")
            return std::make_shared<Routine::Duo>();
        if (r == "matin")
            return std::make_shared<Routine::Matin>();

        return nullptr;
    }

    void CmdRoutine::undo(Machine::Systeme *sys)
    {
        // TODO
    }

} // namespace CMD
