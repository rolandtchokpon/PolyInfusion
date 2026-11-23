
#include "Commande.h"

namespace CMD
{

    class CmdAide : public Commande
    {
    public:
        CmdAide(const Console::Instruction &inst);
        ~CmdAide();

        virtual void executer(Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;
        virtual void apercu(unsigned int numero = 1) override;
    };

} // namespace Commande