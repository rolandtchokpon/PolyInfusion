
#pragma once
#include <string>
#include <vector>
#include "CmdReglage.h"

namespace CMD
{

    // Composite : une routine est un CmdReglage qui contient d'autres CmdReglage
    // (changements élémentaires ou sous-routines). L'historique la traite comme une seule opération.
    class Routine : public CmdReglage
    {
    public:
        explicit Routine(const std::string &nom);
        ~Routine();

        void ajouter(const std::shared_ptr<CmdReglage> &enfant);

        virtual void executer(Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;
        virtual void redo(Machine::Systeme *sys) override;
        virtual std::string description() const override;
        virtual std::unique_ptr<IterateurReglage> creerIterateur() const override;
        virtual std::shared_ptr<CmdReglage> cloner() const override;

    private:
        std::string nom_;
        std::vector<std::shared_ptr<CmdReglage>> enfants_;
    };

} // namespace CMD
