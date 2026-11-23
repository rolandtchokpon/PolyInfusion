
#include "Commande.h"

namespace CMD
{
    class CmdRoutine : public Commande
    {
    public:
        CmdRoutine(const Console::Instruction &inst);
        ~CmdRoutine();

        virtual void executer(Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;
        virtual void apercu(unsigned int numero = 1) override;
    };

} // namespace Commande