#include <iostream>
#include <memory>
#include <vector>

// Nitpick: Det heter ikke MatVare. Ikke anglifiser norske ord, please

/// General class for all (mal)wares
class Vare {
public:
    // Constant attributes
    const std::string navn;
    const int antall;

    Vare(const std::string &navn, const int antall) : navn(navn), antall(antall) {}

    /// Virtual (abstract in Java terms) method for MVA
    virtual double mva() const {
        return 0.25;
    }
};

/// Subclass for food (but is it edible?)
class MatVare : public Vare {
public:
    /// Construct the superclass
    MatVare(const std::string &navn, const int antall) : Vare(navn, antall) {}

    /// Overrides MVA (only needs virtual if this will be overriden in a deeper subclass)
    double mva() const override {
        return 0.15;
    }
};

/// Storage class for totally not suspicious items.
/// Very simple.
class Butikk {
public:
    std::vector<Vare *> varer;
};

int main() {
    Butikk butikk;
    // It should be possible to add some mysterious wares
    butikk.varer.emplace_back(new MatVare("NTNU-nistepakken", 5));
    butikk.varer.emplace_back(new Vare("NTNU-koppen", 10));
    // And access all relevant propertise
    for (auto &v : butikk.varer) {
        std::cout << v->navn << ", "
                  << v->antall << ", "
                  << v->mva() << std::endl;
    }
}
