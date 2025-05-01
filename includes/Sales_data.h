#ifndef SALES_DATA_H_INCLUDED
#define SALES_DATA_H_INCLUDED

#include <iostream>

using namespace std;

struct Sales_data
{
    std::string book_no;
    unsigned units = 0;
    unsigned units_sold = 0;
    double revenue = 0.0;

    Sales_data &combine( const Sales_data & );
    double avg_price() const { return revenue / units; }
    std::string isbn() const { return book_no; }

};

Sales_data& Sales_data::combine( const Sales_data &data)
{
    units += data.units;
    revenue += data.revenue;
    return *this;
}


istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.book_no >> item.units >> price;
    item.revenue = price * item.units;
    return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units << " "
        << item.revenue << " " << item.avg_price();
    return os;
}

#endif // SALES_DATA_H_INCLUDED
