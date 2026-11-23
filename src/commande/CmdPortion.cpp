
#include "../../include/commande/CmdPortion.h"

namespace CMD
{

    CmdPortion::CmdPortion(unsigned int portions) : Commande(true), nouvellesPortions_(portions) {}

    CmdPortion::~CmdPortion() = default;

    void CmdPortion::executer(const Console::Instruction &, Machine::Systeme *sys)
    {
        anciennesPortions_ = sys->portions();

        sys->modifierPortions(nouvellesPortions_);
        std::cout << "Nombre de portions : " << nouvellesPortions_ << "." << std::endl;
    }

    void CmdPortion::undo(Machine::Systeme *sys) { sys->modifierPortions(anciennesPortions_); }

    void CmdPortion::redo(Machine::Systeme *sys) { sys->modifierPortions(nouvellesPortions_); }

    void CmdPortion::apercu(std::vector<std::string> &lignes) const
    {
        lignes.push_back("Régler le nombre de portions à " + std::to_string(nouvellesPortions_) + ".");
    }

    std::shared_ptr<Commande> CmdPortion::cloner() const { return std::make_shared<CmdPortion>(nouvellesPortions_); }

} // namespace CMD
