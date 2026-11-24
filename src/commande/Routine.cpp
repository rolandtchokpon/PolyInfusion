
#include "../../include/commande/Routine.h"
#include "../../include/commande/IterateurRoutine.h"

namespace CMD
{

    Routine::Routine(const std::string &nom) : nom_(nom) {}

    Routine::~Routine() = default;

    void Routine::ajouter(const std::shared_ptr<CmdReglage> &enfant) { enfants_.push_back(enfant); }

    void Routine::executer(Machine::Systeme *sys)
    {
        for (const auto &enfant : enfants_)
            enfant->executer(sys);
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

    std::string Routine::description() const { return "Routine " + nom_ + "."; }

    std::unique_ptr<IterateurReglage> Routine::creerIterateur() const { return std::make_unique<IterateurRoutine>(enfants_); }

    std::shared_ptr<CmdReglage> Routine::cloner() const
    {
        auto copie = std::make_shared<Routine>(nom_);

        for (const auto &enfant : enfants_)
            copie->ajouter(enfant->cloner());

        return copie;
    }

} // namespace CMD
