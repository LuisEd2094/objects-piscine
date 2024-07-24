#ifndef THUESDAYDISCOUNT_HPP
# define  THUESDAYDISCOUNT_HPP

# include <command.hpp>


class thuesdayDiscount : public command
{
private:
    thuesdayDiscount() {};
public:
    thuesdayDiscount(const std::string&, const std::list<article>&);
    ~thuesdayDiscount();
    std::size_t get_total_price() const;
};

thuesdayDiscount::thuesdayDiscount(const std::string& client, const std::list<article>& articles): command(client, articles)
{
}

thuesdayDiscount::~thuesdayDiscount()
{

}

/* day_of_week == 2 if thuesday, starts on Sunday == 0*/
std::size_t thuesdayDiscount::get_total_price() const
{
    std::size_t res = command::get_total_price();

    if (day_of_week == 2 && res > 0)
    {
        res *= 0.90;
    }
    return res;
}


#endif