#include "MagicalContainer.hpp"

using namespace std;

namespace ariel
{
    MagicalContainer::MagicalContainer() // defult constractor
    {
    }
    MagicalContainer::MagicalContainer(MagicalContainer &other) // copy constractor
    {
    }
    MagicalContainer::~MagicalContainer() // destructor
    {
    }

    void MagicalContainer::addElement(int num)
    {
        container.push_back(num);
    }

    void MagicalContainer::removeElement(int num)
    {
        for (auto it = container.begin(); it != container.end(); ++it)
        {
            if (*it == num)
            {
                container.erase(it); // delete from the last place in the vector
                break;
            }
        }
    }
    size_t MagicalContainer::size() const
    {
        return this->container.size();
    }
    // ************ AscendingIterator *************

    MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer &container) : container(container), index(0) {}
    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : container(other.container), index(other.index)
    {
        //other.container = this->container;
        //other.index = this->index;

    }
    int MagicalContainer::AscendingIterator::operator*() const 
    {
        return 1;
    }
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const {return MagicalContainer::AscendingIterator(container);}
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const {  return AscendingIterator(container);}
    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const 
    {
        return true;
    }
    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const 
    { 
        return true;
    }
    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const 
    {
        return true;
    }
    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const 
    {
        return true;
    }
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other) 
    {
        return *this;
    }
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() 
    {
        return *this;
    }


    // ************ SideCrossIterator *************

    MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer &container,size_t forward,size_t backward) : container(container), forwardIndex(forward), backwardIndex(backward){}
    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : container(other.container), forwardIndex(other.forwardIndex), backwardIndex(other.backwardIndex){}
    int MagicalContainer::SideCrossIterator::operator*() const 
    {
        return -1;
    }
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const { return MagicalContainer::SideCrossIterator(container,0,container.size());}
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const { return SideCrossIterator(container,0,0); }
    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const {return true;}
    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const {return true;}
    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const {return true;}
    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const {return true;}
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other) { return *this;}
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {return *this;}

    // ************ PrimeIterator *************

    bool MagicalContainer::PrimeIterator::isPrime(int number)
    {
        if (number < 2)
            return false;
        for (int i = 2; i <= sqrt(number); ++i)
        {
            if (number % i == 0)
                return false;
        }
        return true;
    }
    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &container) : container(container), index(0) {}
    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : container(other.container), index(other.index)  {}
    int MagicalContainer::PrimeIterator::operator*() const {return 1;}
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const {return MagicalContainer::PrimeIterator(container);}
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const {return PrimeIterator(container);}
    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const {return true;}
    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const {return true;}
    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const {return true;}
    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const {return true;}
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other) {return *this;}
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() { return *this;}
}
