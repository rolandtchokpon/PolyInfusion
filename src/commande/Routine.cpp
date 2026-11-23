
#include "../../include/commande/Routine.h"

namespace CMD
{

    Routine::Routine(const std::string &nom) : Commande(true), nom_(nom) {}

    Routine::~Routine() = default;

    void Routine::ajouter(const std::shared_ptr<Commande> &enfant) { enfants_.push_back(enfant); }

    void Routine::executer(const Console::Instruction &inst, Machine::Systeme *sys)
    {
        for (const auto &enfant : enfants_)
            enfant->executer(inst, sys);
    }

    void Routine::undo(Machine::Systeme *sys)
    {
        // Ordre inverse : chaque enfant restaure l'état qu'il avait trouvé.
        for (auto it = enfants_.rbegin(); it != enfants_.rend(); ++it)
            (*it)->undo(sys);
    }

    void Routine::redo(Machine::Systeme *sys)
    {
        for (const auto &enfant : enfants_)
            enfant->redo(sys);
    }

    void Routine::apercu(std::vector<std::string> &lignes) const
    {
        for (const auto &enfant : enfants_)
            enfant->apercu(lignes);
    }

    std::shared_ptr<Commande> Routine::cloner() const
    {
        auto copie = std::make_shared<Routine>(nom_);

        for (const auto &enfant : enfants_)
            copie->ajouter(enfant->cloner());

        return copie;
    }

} // namespace CMD
