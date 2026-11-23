
#include "../../include/preparation/Infuseur.h"
#include "../../include/util/Format.h"

namespace Machine {

    Infuseur::Infuseur(DistributeurEau* distributeurEau, DistributeurThe* distributeurThe, SystemeChauffage* systemeChauffage) :
        distributeurEau_(distributeurEau),
        distributeurThe_(distributeurThe),
        systemeChauffage_(systemeChauffage)
    {}

    Infuseur::~Infuseur() = default;

    void Infuseur::infuser(const std::string& the) {
        const The& theObj = distributeurThe_->obtenirThe(the);
        const bool avecRincage = theObj.volumeRincage > 0.0;

        if (avecRincage)
            systemeChauffage_->chaufferEauPreparation(theObj.temperatureInfusion);
        else
            systemeChauffage_->chaufferEau(theObj.temperatureInfusion);

        distributeurEau_->distribuerEau(theObj.volumeService);

        // Avec rinçage, les feuilles ont déjà été dosées lors du rinçage.
        if (!avecRincage)
            distributeurThe_->distribuerThe(the, theObj.quantiteService);

        std::cout << "Infusion : " << Util::nombre(theObj.tempsInfusion) << " secondes simulées." << std::endl;
    }

} // namespace Machine
