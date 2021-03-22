#include <iostream>
#include <memory>
#include <list>

using namespace std;

class IObserver{
public:
    virtual void update(std::string message) = 0;
};

class Subject{
private:
    std::list<std::shared_ptr<IObserver>> observerList;
    
    void notifyAll(){
        for(auto itr = observerList.begin(); itr != observerList.end(); itr++){
            (*itr) -> update("LOW POWER");
        }
    }

public:
    void regListener(std::shared_ptr<IObserver> observer){
        observerList.push_back(observer);
    }
    
};

class Display : public IObserver{
    
};

class Audio : public IObserver{

};