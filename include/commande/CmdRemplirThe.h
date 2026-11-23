
#include "Commande.h"

namespace CMD
{
    class CmdRemplirThe : public Commande
    {
    public:
        CmdRemplirThe(const Console::Instruction &inst);
        ~CmdRemplirThe();

        virtual void executer(Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;
        virtual void apercu(unsigned int numero = 1) override;
    };

} // namespace Commande