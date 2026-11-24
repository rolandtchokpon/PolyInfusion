
#pragma once
#include <string>
#include "Commande.h"

namespace CMD
{
    class CmdRemplirThe : public Commande
    {
    public:
        CmdRemplirThe(const std::string &the, double quantite);
        ~CmdRemplirThe();

        virtual void executer(Machine::Systeme *sys) override;

    private:
        std::string the_;
        double quantite_;
    };

} // namespace CMD
