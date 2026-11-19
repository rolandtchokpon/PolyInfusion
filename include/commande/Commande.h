
#include <iostream>
#include "../systeme/Systeme.h"

namespace CMD
{

    class Commande
    {
    public:
        virtual void executer(Instruction inst, Machine::Systeme sys) = 0;

    protected:
        Commande(bool estReversible);

        bool estReversible() const;
        bool estReversible_;
    };

}