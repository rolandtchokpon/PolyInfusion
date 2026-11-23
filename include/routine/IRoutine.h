
#pragma once
#include <string>
#include <vector>
#include "../commande/Commande.h"

namespace Machine
{
    class Systeme;
}

namespace Routine
{

    class IRoutine : public CMD::Commande
    {
    public:
        virtual ~IRoutine() = 0;
        void virtual executer(Machine::Systeme *sys) = 0;
        void virtual undo(Machine::Systeme *sys) = 0;
        virtual void apercu(unsigned int numero = 1) = 0;

    protected:
        IRoutine();
        std::vector<std::unique_ptr<CMD::Commande>> commandes_;
    };

}