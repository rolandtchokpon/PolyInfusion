#include <stdexcept>
#include "../../include/commande/CmdPolyInfusion.h"
#include "../../include/fabrique/FabriqueCompact.h"
#include "../../include/fabrique/FabriquePro.h"

namespace CMD
{

    CmdPolyInfusion::CmdPolyInfusion(const std::string &modele) : modele_(modele) {}

    CmdPolyInfusion::~CmdPolyInfusion() = default;

    std::unique_ptr<Fabrique::FabriqueSysteme> CmdPolyInfusion::creerFabrique() const
    {
        if (modele_ == "compact")
            return std::make_unique<Fabrique::FabriqueCompact>();
        if (modele_ == "pro")
            return std::make_unique<Fabrique::FabriquePro>();

        throw std::invalid_argument("Erreur : modèle inconnu. Utilisation : PolyInfusion <compact|pro>.");
    }

    std::unique_ptr<Machine::Systeme> CmdPolyInfusion::creerSysteme() const
    {
        return creerFabrique()->creerSysteme();
    }

    void CmdPolyInfusion::executer(Machine::Systeme *sys)
    {
        if (sys != nullptr)
            throw std::logic_error("Erreur : la machine est déjà démarrée.");
    }

} // namespace CMD