
#include "Commande.h"

namespace CMD
{
    class CmdInfuser : public Commande
    {
    public:
        CmdInfuser(const Console::Instruction &inst);
        ~CmdInfuser();

        virtual void executer(Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;
        virtual void apercu(unsigned int numero = 1) override;
    };

} // namespace Commande