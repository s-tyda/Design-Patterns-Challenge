#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

class Subscriber {
public:
    virtual void update(std::string const &context);
};

void Subscriber::update(const std::string &context) {

}

class ConcreteSubscriber : public Subscriber {
private:
    std::string username;
public:
    ConcreteSubscriber(std::string login) : username(login){}
    void update(std::string const &context) override;
};

class Youtuber {
public:
    void subscribe(Subscriber* subscriber);
    void unsubscribe(Subscriber* subscriber);
    void notifySubscribers();
private:
    std::vector<Subscriber*> subscribers;
    int state;
};

void ConcreteSubscriber::update(std::string const &context) {
    std::cout << this->username << " otrzymałem powiadomienie: " << context << "\n";
}

void Youtuber::subscribe(Subscriber* subscriber) {
    this->subscribers.push_back(subscriber);
}

void Youtuber::unsubscribe(Subscriber* subscriber) {
    subscribers.erase(std::find(subscribers.begin(), subscribers.end(), subscriber));
}

void Youtuber::notifySubscribers() {
    for (Subscriber* subscriber : subscribers) {
        subscriber->update("Hejo! Nowy film!");
    }
}

int main(){
    Youtuber albert;
    ConcreteSubscriber *yeti = new ConcreteSubscriber("yetito*****");
    ConcreteSubscriber *tydziolec = new ConcreteSubscriber("styda");
    albert.subscribe(yeti);
    albert.subscribe(tydziolec);
    albert.notifySubscribers();
    albert.unsubscribe(tydziolec);
    albert.notifySubscribers();
}
