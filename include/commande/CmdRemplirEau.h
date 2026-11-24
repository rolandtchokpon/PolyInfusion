
#pragma once
#include "Commande.h"

namespace CMD
{
    class CmdRemplirEau : public Commande
    {
    public:
        explicit CmdRemplirEau(double quantite);
        ~CmdRemplirEau();

        virtual void executer(Machine::Systeme *sys) override;

    private:
        double quantite_;
    };

} // namespace CMD
