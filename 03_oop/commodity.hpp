#ifndef COMMODITY_H
#define COMMODITY_H

#include <string>
using namespace std;

const double SALES_TAX = 1.25;

class Commodity {
    public:
        Commodity(const string &name_, int id_, double price_);
        const string &get_name() const;
        int get_id() const;
        double get_price() const;
        void set_price(double price);
        double get_price(int units) const;
        double get_price_with_sales_tax(int units) const;
    private:
        string name;
        int id;
        double price;
};

#endif // COMMODITY_H
