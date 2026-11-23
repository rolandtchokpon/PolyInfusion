
#include "Commande.h"
#include "../routine/RegistreRoutine.h"

namespace CMD
{
    class CmdApercu : public Commande
    {
    public:
        CmdApercu(const Console::Instruction &inst);
        ~CmdApercu();

        virtual void executer(Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;
        virtual void apercu(unsigned int numero = 1) override;

    private:
        std::unique_ptr<Routine::RegistreRoutine> registre_;
    };

} // namespace Commande