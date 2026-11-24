
#pragma once
#include <string>
#include "CmdReglage.h"

namespace CMD
{
    class CmdSelection : public CmdReglage
    {
    public:
        explicit CmdSelection(const std::string &the);
        ~CmdSelection();

        virtual void executer(Machine::Systeme *sys) override;
        virtual void undo(Machine::Systeme *sys) override;
        virtual void redo(Machine::Systeme *sys) override;
        virtual std::string description() const override;
        virtual std::unique_ptr<IterateurReglage> creerIterateur() const override;
        virtual std::shared_ptr<CmdReglage> cloner() const override;

    private:
        std::string ancienThe_;
        std::string nouveauThe_;
    };

} // namespace CMD
