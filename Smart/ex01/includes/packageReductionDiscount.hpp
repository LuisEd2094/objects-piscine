#ifndef PACKAGEREDUCTIONDISCOUNT_HPP
# define  PACKAGEREDUCTIONDISCOUNT_HPP

# include <command.hpp>


class packageReductionDiscount : public command
{
private:
    packageReductionDiscount() {};
public:
    packageReductionDiscount(const std::string&, const std::list<article>&);
    ~packageReductionDiscount();
    std::size_t get_total_price() const;
};

packageReductionDiscount::packageReductionDiscount(const std::string& client, const std::list<article>& articles): command(client, articles)
{
}

packageReductionDiscount::~packageReductionDiscount()
{

}

/* day_of_week == 2 if thuesday, starts on Sunday == 0*/
std::size_t packageReductionDiscount::get_total_price() const
{
    std::size_t res = command::get_total_price();

    if (res > 150)
    {
        res -= 10;
    }
    return res;
}


#endif