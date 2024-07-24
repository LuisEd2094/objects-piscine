#ifndef COMMAND_HPP
# define COMMAND_HPP

# include <iostream>
# include <ctime>

# include <list>

struct article
{
    std::size_t price;
    std::size_t quantity;
    std::string name;
    
    article(std::size_t p, std::size_t q, std::string n) : price(p), quantity(q), name(n) {}
};


class command
{
protected:
    static std::size_t global_id;
    std::size_t id;
    int year, month, day, hour, minute, second, day_of_week;
    std::string _client;
    
    std::list<article> _articles;
    command(){};
 
public:
    command(const std::string&, const std::list<article>&);
    ~command();

    const std::list<article>& getArticles() {return _articles;};

    virtual std::size_t get_total_price() const;
};

std::size_t command::global_id = 0;

command::command(const std::string &client, const std::list<article>& articles): id(command::global_id), _client(client), _articles(articles)
{
    std::time_t t = std::time(NULL);
    struct std::tm* now = std::localtime(&t);

    year = now->tm_year + 1900;
    month = now->tm_mon + 1;
    day = now->tm_mday;
    hour = now->tm_hour;
    minute = now->tm_min;
    second = now->tm_sec;
    day_of_week = now->tm_wday;

    std::cout << "Object created on: " << year << "-"
                << month << "-" << day << " "
                << hour << ":" << minute << ":" << second << std::endl;
}

command::~command()
{
}

std::size_t command::get_total_price() const
{
    std::size_t total = 0;
    for (std::list<article>::const_iterator it = _articles.begin(); it != _articles.end(); ++it)
    {
        total += (*it).price;
    }
    return total;
}

#endif