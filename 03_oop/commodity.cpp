#include "commodity.hpp"

using namespace std;

Commodity::Commodity(const string &name_, int id_, double price_) :
    name(name_), id(id_), price(price_) {}

// {{{ Getters and setters

const string &Commodity::get_name() const {
    return name;
}

int Commodity::get_id() const {
    return id;
}

double Commodity::get_price() const {
    return price;
}

void Commodity::set_price(double price_) {
    price = price_;
}

// }}}

// {{{ Calculating methods

double Commodity::get_price(int units) const {
    return units * price;
}

double Commodity::get_price_with_sales_tax(int units) const {
    return units * price * SALES_TAX;
}

// }}}
