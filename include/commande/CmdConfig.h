
#include "Commande.h"

namespace CMD
{
    class CmdConfig : public Commande
    {
    public:
        CmdConfig(const Console::Instruction &inst);
        ~CmdConfig();

        virtual void executer(Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;
        virtual void apercu(unsigned int numero = 1) override;
    };

} // namespace Commande