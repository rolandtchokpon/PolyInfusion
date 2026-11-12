
#pragma once

#include <exception>
#include <string>

namespace Machine {

    class EauInsuffisante : public std::exception {
        public:
            EauInsuffisante(double quantiteRequise, double quantiteDisponible);
            virtual const char* what() const noexcept override;

        private:
            double quantiteRequise_;
            double quantiteDisponible_;
            std::string message_;
    };

} // namespace Machine
