
#include "Commande.h"

namespace CMD
{
    class CmdReserve : public Commande
    {
    public:
        CmdReserve(const Console::Instruction &inst);
        ~CmdReserve();

        virtual void executer(Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;
        virtual void apercu(unsigned int numero = 1) override;
    };

} // namespace Commande