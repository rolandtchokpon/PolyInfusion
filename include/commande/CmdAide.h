
#include "Commande.h"

namespace CMD
{

    class CmdAide : public Commande
    {
    public:
        CmdAide();
        ~CmdAide();

        virtual void executer(const Console::Instruction &inst, Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;
    };

} // namespace Commande