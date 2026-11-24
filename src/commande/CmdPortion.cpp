
#include <iostream>
#include "../../include/commande/CmdPortion.h"
#include "../../include/commande/IterateurFeuille.h"
#include "../../include/systeme/Systeme.h"

namespace CMD
{

    CmdPortion::CmdPortion(unsigned int portions) : nouvellesPortions_(portions) {}

    CmdPortion::~CmdPortion() = default;

    void CmdPortion::executer(Machine::Systeme *sys)
    {
        anciennesPortions_ = sys->portions();

        sys->modifierPortions(nouvellesPortions_);
        std::cout << "Nombre de portions : " << nouvellesPortions_ << "." << std::endl;
    }

    void CmdPortion::undo(Machine::Systeme *sys) { sys->modifierPortions(anciennesPortions_); }

    void CmdPortion::redo(Machine::Systeme *sys) { sys->modifierPortions(nouvellesPortions_); }

    std::string CmdPortion::description() const { return "Régler le nombre de portions à " + std::to_string(nouvellesPortions_) + "."; }

    std::unique_ptr<IterateurReglage> CmdPortion::creerIterateur() const { return std::make_unique<IterateurFeuille>(*this); }

    std::shared_ptr<CmdReglage> CmdPortion::cloner() const { return std::make_shared<CmdPortion>(nouvellesPortions_); }

} // namespace CMD
