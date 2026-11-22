
#include "../../include/reserve/Reserve.h"

namespace Machine
{

    const double QTE_EAU_INITIALE = 2000.0; // mL

    Reserve::Reserve() : 
        Notification::Notificateur(),
        qteEau_(QTE_EAU_INITIALE),
        etatEau_(Etat::CORRECT)
    {
        thes_.clear();
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
        std::cout << "Eau : " << qteEau_ << " mL" << std::endl;

        std::cout << "Réserves de thés :" << std::endl;
        for (const auto &pair : thes_)
        {
            const The &the = pair.second;
            std::cout << "  - " << "Thé " << the.nom << " : " << the.quantite << " g." << std::endl;
        }
    }

    void Reserve::ajouterThe(const The &the) { thes_[the.nom] = the; }

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

        std::cout << "Ajout de thé " << the << " : " << quantite << " g." << std::endl;

        notifier(the, thes_[the].quantite);
    }

    void Reserve::remplirEau(double quantite)
    {
        qteEau_ += quantite;

        std::cout << "Ajout d'eau : " << quantite << " mL" << std::endl;

        notifier(qteEau_);
    }

    void Reserve::distribuerThe(const std::string &the, double quantite, double ratio)
    {
        double quantiteRequise = quantite * (1.0 + ratio);

        thes_[the].quantite -= quantiteRequise;

        std::cout << "Consommation de thé " << the << " : " << quantiteRequise << " g." << std::endl;

        notifier(the, thes_[the].quantite);
    }

    void Reserve::distribuerEau(double quantite, double ratio)
    {
        double quantiteRequise = quantite * (1.0 + ratio);

        qteEau_ -= quantiteRequise;

        std::cout << "Consommation d'eau : " << quantiteRequise << " mL" << std::endl;

        this->notifier(qteEau_);
    }

    Etat Reserve::obtenirEtatEau() const { return etatEau_; }

    Etat Reserve::obtenirEtatThe(const std::string &the) const { 
        auto it = etatsThe_.find(the);
        return it == etatsThe_.end() ? Etat::CORRECT : it->second;
    }

    void Reserve::mettreEtatEau(Etat e) { etatEau_ = e; }

    void Reserve::mettreEtatThe(const std::string &the, Etat e) { etatsThe_[the] = e; }

} // namespace Machine