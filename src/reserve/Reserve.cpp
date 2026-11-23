
#include "../../include/reserve/Reserve.h"
#include "../../include/util/Format.h"

namespace Machine
{

    const double QTE_EAU_INITIALE = 2000.0; // mL

    Reserve::Reserve() : Notification::Notificateur(),
                         qteEau_(QTE_EAU_INITIALE)
    {
        ajouterThe(TheVert());
        ajouterThe(TheNoir());
        ajouterThe(TheOolong());
    }

    void Reserve::eauSuffisante(double quantite, double ratio) const
    {
        double quantiteRequise = quantite * (1.0 + ratio);

        if (qteEau_ < quantiteRequise)
        {
            throw EauInsuffisante(quantiteRequise, qteEau_);
        }
    }

    void Reserve::theSuffisant(const std::string &the, double quantite, double ratio) const
    {
        auto it = thes_.find(the);
        double quantiteRequise = quantite * (1.0 + ratio);

        if (it == thes_.end())
        {
            throw TheInsuffisant(the, quantiteRequise, 0.0);
        }

        const The &theObj = it->second;

        if (theObj.quantite < quantiteRequise)
        {
            throw TheInsuffisant(the, quantiteRequise, theObj.quantite);
        }
    }

    void Reserve::afficherReserves() const
    {
        std::cout << "Eau : " << Util::nombre(qteEau_) << " mL" << std::endl;

        for (const std::string &nom : ordreThes_)
        {
            std::cout << "Thé " << nom << " : " << Util::nombre(thes_.at(nom).quantite) << " g" << std::endl;
        }
    }

    void Reserve::ajouterThe(const The &the)
    {
        if (thes_.find(the.nom) == thes_.end())
            ordreThes_.push_back(the.nom);

        thes_[the.nom] = the;
    }

    const The &Reserve::obtenirThe(const std::string &nomThe) const
    {
        auto it = thes_.find(nomThe);

        if (it == thes_.end())
        {
            throw TheInsuffisant(nomThe, 0.0, 0.0);
        }

        return it->second;
    }

    void Reserve::remplirThe(const std::string &the, double quantite)
    {
        thes_[the].quantite += quantite;

        std::cout << "Ajout de thé " << the << " : " << Util::nombre(quantite) << " g." << std::endl;

        verifierThe(the, thes_[the].quantite);
    }

    void Reserve::remplirEau(double quantite)
    {
        qteEau_ += quantite;

        std::cout << "Ajout d'eau : " << Util::nombre(quantite) << " mL." << std::endl;

        verifierEau(qteEau_);
    }

    void Reserve::distribuerThe(const std::string &the, double quantite, double ratio)
    {
        double quantiteRequise = quantite * (1.0 + ratio);

        thes_[the].quantite -= quantiteRequise;

        std::cout << "Consommation de thé " << the << " : " << Util::nombre(quantiteRequise) << " g." << std::endl;

        verifierThe(the, thes_[the].quantite);
    }

    void Reserve::distribuerEau(double quantite, double ratio)
    {
        double quantiteRequise = quantite * (1.0 + ratio);

        qteEau_ -= quantiteRequise;

        std::cout << "Consommation d'eau : " << Util::nombre(quantiteRequise) << " mL." << std::endl;

        verifierEau(qteEau_);
    }

} // namespace Machine
